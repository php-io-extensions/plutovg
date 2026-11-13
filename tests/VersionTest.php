<?php

declare(strict_types=1);

it('reports PlutoVG 1.3.3', function (): void {
    expect(plutovg_version_string())->toBe('1.3.3')
        ->and(plutovg_version())->toBe(10303);
});

it('prints the extension version, the PlutoVG version, and the upstream commit', function (): void {
    ob_start();
    phpinfo(INFO_MODULES);
    $info = ob_get_clean();

    expect($info)->toContain('0.11.0')
        ->and($info)->toContain('1.3.3')
        ->and($info)->toContain('bbd91f0d06a71491691b36330f29dffa4af87ccf');
});
