/*
 * Canvases: plutovg.h from plutovg_canvas_create to plutovg_canvas_text_extents. Every function
 * written out (the plain setters, getters and path builders first, then the ones with checks).
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <math.h>

#include "php.h"
#include "zend_exceptions.h"
#include "main/fopen_wrappers.h"
#include "runtime.h"
#include "../stubs/plutovg_canvas_arginfo.h"

void pv_canvas_minit(void) { zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT); }

#define CANVAS_ARG(zv, num, var) plutovg_canvas_t *var = pv_handle_arg(zv, num); if (!var) { RETURN_THROWS(); }

ZEND_FUNCTION(plutovg_canvas_save)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_save(canvas);
}

ZEND_FUNCTION(plutovg_canvas_restore)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_restore(canvas);
}

ZEND_FUNCTION(plutovg_canvas_set_rgb)
{
	zval *zc;
	double r;
	double g;
	double b;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(r)
		Z_PARAM_DOUBLE(g)
		Z_PARAM_DOUBLE(b)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_set_rgb(canvas, (float) r, (float) g, (float) b);
}

ZEND_FUNCTION(plutovg_canvas_set_rgba)
{
	zval *zc;
	double r;
	double g;
	double b;
	double a;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(r)
		Z_PARAM_DOUBLE(g)
		Z_PARAM_DOUBLE(b)
		Z_PARAM_DOUBLE(a)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_set_rgba(canvas, (float) r, (float) g, (float) b, (float) a);
}

ZEND_FUNCTION(plutovg_canvas_set_font_size)
{
	zval *zc;
	double size;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(size)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_set_font_size(canvas, (float) size);
}

ZEND_FUNCTION(plutovg_canvas_get_font_size)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_DOUBLE(plutovg_canvas_get_font_size(canvas));
}

ZEND_FUNCTION(plutovg_canvas_get_fill_rule)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_LONG(plutovg_canvas_get_fill_rule(canvas));
}

ZEND_FUNCTION(plutovg_canvas_get_operator)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_LONG(plutovg_canvas_get_operator(canvas));
}

ZEND_FUNCTION(plutovg_canvas_set_opacity)
{
	zval *zc;
	double opacity;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(opacity)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_set_opacity(canvas, (float) opacity);
}

ZEND_FUNCTION(plutovg_canvas_get_opacity)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_DOUBLE(plutovg_canvas_get_opacity(canvas));
}

ZEND_FUNCTION(plutovg_canvas_set_line_width)
{
	zval *zc;
	double line_width;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(line_width)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_set_line_width(canvas, (float) line_width);
}

ZEND_FUNCTION(plutovg_canvas_get_line_width)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_DOUBLE(plutovg_canvas_get_line_width(canvas));
}

ZEND_FUNCTION(plutovg_canvas_get_line_cap)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_LONG(plutovg_canvas_get_line_cap(canvas));
}

ZEND_FUNCTION(plutovg_canvas_get_line_join)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_LONG(plutovg_canvas_get_line_join(canvas));
}

ZEND_FUNCTION(plutovg_canvas_set_miter_limit)
{
	zval *zc;
	double miter_limit;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(miter_limit)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_set_miter_limit(canvas, (float) miter_limit);
}

ZEND_FUNCTION(plutovg_canvas_get_miter_limit)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_DOUBLE(plutovg_canvas_get_miter_limit(canvas));
}

ZEND_FUNCTION(plutovg_canvas_set_dash_offset)
{
	zval *zc;
	double offset;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(offset)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_set_dash_offset(canvas, (float) offset);
}

ZEND_FUNCTION(plutovg_canvas_get_dash_offset)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_DOUBLE(plutovg_canvas_get_dash_offset(canvas));
}

ZEND_FUNCTION(plutovg_canvas_translate)
{
	zval *zc;
	double tx;
	double ty;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(tx)
		Z_PARAM_DOUBLE(ty)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_translate(canvas, (float) tx, (float) ty);
}

ZEND_FUNCTION(plutovg_canvas_scale)
{
	zval *zc;
	double sx;
	double sy;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(sx)
		Z_PARAM_DOUBLE(sy)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_scale(canvas, (float) sx, (float) sy);
}

ZEND_FUNCTION(plutovg_canvas_shear)
{
	zval *zc;
	double shx;
	double shy;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(shx)
		Z_PARAM_DOUBLE(shy)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_shear(canvas, (float) shx, (float) shy);
}

ZEND_FUNCTION(plutovg_canvas_rotate)
{
	zval *zc;
	double angle;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(angle)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_rotate(canvas, (float) angle);
}

ZEND_FUNCTION(plutovg_canvas_reset_matrix)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_reset_matrix(canvas);
}

ZEND_FUNCTION(plutovg_canvas_move_to)
{
	zval *zc;
	double x;
	double y;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_move_to(canvas, (float) x, (float) y);
}

ZEND_FUNCTION(plutovg_canvas_line_to)
{
	zval *zc;
	double x;
	double y;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_line_to(canvas, (float) x, (float) y);
}

ZEND_FUNCTION(plutovg_canvas_quad_to)
{
	zval *zc;
	double x1;
	double y1;
	double x2;
	double y2;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x1)
		Z_PARAM_DOUBLE(y1)
		Z_PARAM_DOUBLE(x2)
		Z_PARAM_DOUBLE(y2)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_quad_to(canvas, (float) x1, (float) y1, (float) x2, (float) y2);
}

ZEND_FUNCTION(plutovg_canvas_cubic_to)
{
	zval *zc;
	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x1)
		Z_PARAM_DOUBLE(y1)
		Z_PARAM_DOUBLE(x2)
		Z_PARAM_DOUBLE(y2)
		Z_PARAM_DOUBLE(x3)
		Z_PARAM_DOUBLE(y3)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_cubic_to(canvas, (float) x1, (float) y1, (float) x2, (float) y2, (float) x3, (float) y3);
}

ZEND_FUNCTION(plutovg_canvas_arc_to)
{
	zval *zc;
	double rx;
	double ry;
	double angle;
	bool large_arc_flag;
	bool sweep_flag;
	double x;
	double y;
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(rx)
		Z_PARAM_DOUBLE(ry)
		Z_PARAM_DOUBLE(angle)
		Z_PARAM_BOOL(large_arc_flag)
		Z_PARAM_BOOL(sweep_flag)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_arc_to(canvas, (float) rx, (float) ry, (float) angle, large_arc_flag, sweep_flag, (float) x, (float) y);
}

ZEND_FUNCTION(plutovg_canvas_rect)
{
	zval *zc;
	double x;
	double y;
	double w;
	double h;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(w)
		Z_PARAM_DOUBLE(h)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_rect(canvas, (float) x, (float) y, (float) w, (float) h);
}

ZEND_FUNCTION(plutovg_canvas_round_rect)
{
	zval *zc;
	double x;
	double y;
	double w;
	double h;
	double rx;
	double ry;
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(w)
		Z_PARAM_DOUBLE(h)
		Z_PARAM_DOUBLE(rx)
		Z_PARAM_DOUBLE(ry)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_round_rect(canvas, (float) x, (float) y, (float) w, (float) h, (float) rx, (float) ry);
}

ZEND_FUNCTION(plutovg_canvas_ellipse)
{
	zval *zc;
	double cx;
	double cy;
	double rx;
	double ry;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(cx)
		Z_PARAM_DOUBLE(cy)
		Z_PARAM_DOUBLE(rx)
		Z_PARAM_DOUBLE(ry)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_ellipse(canvas, (float) cx, (float) cy, (float) rx, (float) ry);
}

ZEND_FUNCTION(plutovg_canvas_circle)
{
	zval *zc;
	double cx;
	double cy;
	double r;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(cx)
		Z_PARAM_DOUBLE(cy)
		Z_PARAM_DOUBLE(r)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_circle(canvas, (float) cx, (float) cy, (float) r);
}

ZEND_FUNCTION(plutovg_canvas_new_path)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_new_path(canvas);
}

ZEND_FUNCTION(plutovg_canvas_close_path)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_close_path(canvas);
}

ZEND_FUNCTION(plutovg_canvas_fill_contains)
{
	zval *zc;
	double x;
	double y;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_BOOL(plutovg_canvas_fill_contains(canvas, (float) x, (float) y));
}

ZEND_FUNCTION(plutovg_canvas_clip_contains)
{
	zval *zc;
	double x;
	double y;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_BOOL(plutovg_canvas_clip_contains(canvas, (float) x, (float) y));
}

ZEND_FUNCTION(plutovg_canvas_fill)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_fill(canvas);
}

ZEND_FUNCTION(plutovg_canvas_clip)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_clip(canvas);
}

ZEND_FUNCTION(plutovg_canvas_paint)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_paint(canvas);
}

ZEND_FUNCTION(plutovg_canvas_fill_preserve)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_fill_preserve(canvas);
}

ZEND_FUNCTION(plutovg_canvas_clip_preserve)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_clip_preserve(canvas);
}

ZEND_FUNCTION(plutovg_canvas_fill_rect)
{
	zval *zc;
	double x;
	double y;
	double w;
	double h;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(w)
		Z_PARAM_DOUBLE(h)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_fill_rect(canvas, (float) x, (float) y, (float) w, (float) h);
}

ZEND_FUNCTION(plutovg_canvas_clip_rect)
{
	zval *zc;
	double x;
	double y;
	double w;
	double h;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(w)
		Z_PARAM_DOUBLE(h)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_canvas_clip_rect(canvas, (float) x, (float) y, (float) w, (float) h);
}

/* ---- lifetime -------------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_canvas_create)
{
	zval *zs;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
	ZEND_PARSE_PARAMETERS_END();
	plutovg_surface_t *surface = pv_handle_arg(zs, 1);
	if (!surface) {
		RETURN_THROWS();
	}
	pv_handle_wrap(pv_canvas_ce, plutovg_canvas_create(surface), Z_OBJ_P(zs), return_value);
}

ZEND_FUNCTION(plutovg_canvas_reference)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	pv_handle_wrap(pv_canvas_ce, plutovg_canvas_reference(canvas), Z_OBJ_P(zc), return_value);
}

ZEND_FUNCTION(plutovg_canvas_destroy)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	(void) canvas;
	pv_handle_release(Z_OBJ_P(zc));
}

ZEND_FUNCTION(plutovg_canvas_get_reference_count)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_LONG(plutovg_canvas_get_reference_count(canvas));
}

/* The canvas keeps its surface; the returned handle takes a reference of its own. */
ZEND_FUNCTION(plutovg_canvas_get_surface)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	pv_handle_wrap(pv_surface_ce, plutovg_surface_reference(plutovg_canvas_get_surface(canvas)), Z_OBJ_P(zc), return_value);
}

/* ---- paint ----------------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_canvas_set_color)
{
	zval *zc, *zcolor;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zcolor, pv_color_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_color_t color;
	pv_color_read(Z_OBJ_P(zcolor), &color);
	plutovg_canvas_set_color(canvas, &color);
}

ZEND_FUNCTION(plutovg_canvas_set_linear_gradient)
{
	zval *zc, *zm;
	double x1, y1, x2, y2;
	zend_long spread, nstops;
	HashTable *zstops;
	ZEND_PARSE_PARAMETERS_START(9, 9)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x1) Z_PARAM_DOUBLE(y1) Z_PARAM_DOUBLE(x2) Z_PARAM_DOUBLE(y2)
		Z_PARAM_LONG(spread)
		Z_PARAM_ARRAY_HT(zstops)
		Z_PARAM_LONG(nstops)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_gradient_stop_t *stops;
	if (!pv_enum(spread, PLUTOVG_SPREAD_METHOD_REPEAT, "PLUTOVG_SPREAD_METHOD_", 6) || !pv_stops(zstops, nstops, &stops, 8)) {
		RETURN_THROWS();
	}
	plutovg_matrix_t m;
	if (zm) {
		pv_matrix_read(Z_OBJ_P(zm), &m);
	}
	plutovg_canvas_set_linear_gradient(canvas, (float) x1, (float) y1, (float) x2, (float) y2, (plutovg_spread_method_t) spread, stops, (int) nstops, zm ? &m : NULL);
	if (stops) efree(stops);
}

ZEND_FUNCTION(plutovg_canvas_set_radial_gradient)
{
	zval *zc, *zm;
	double cx, cy, cr, fx, fy, fr;
	zend_long spread, nstops;
	HashTable *zstops;
	ZEND_PARSE_PARAMETERS_START(11, 11)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(cx) Z_PARAM_DOUBLE(cy) Z_PARAM_DOUBLE(cr)
		Z_PARAM_DOUBLE(fx) Z_PARAM_DOUBLE(fy) Z_PARAM_DOUBLE(fr)
		Z_PARAM_LONG(spread)
		Z_PARAM_ARRAY_HT(zstops)
		Z_PARAM_LONG(nstops)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_gradient_stop_t *stops;
	if (!pv_enum(spread, PLUTOVG_SPREAD_METHOD_REPEAT, "PLUTOVG_SPREAD_METHOD_", 8) || !pv_stops(zstops, nstops, &stops, 10)) {
		RETURN_THROWS();
	}
	plutovg_matrix_t m;
	if (zm) {
		pv_matrix_read(Z_OBJ_P(zm), &m);
	}
	plutovg_canvas_set_radial_gradient(canvas, (float) cx, (float) cy, (float) cr, (float) fx, (float) fy, (float) fr,
		(plutovg_spread_method_t) spread, stops, (int) nstops, zm ? &m : NULL);
	if (stops) efree(stops);
}

ZEND_FUNCTION(plutovg_canvas_set_texture)
{
	zval *zc, *zs, *zm;
	zend_long type;
	double opacity;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_surface_ce)
		Z_PARAM_LONG(type)
		Z_PARAM_DOUBLE(opacity)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_surface_t *surface = pv_handle_arg(zs, 2);
	if (!surface || !pv_enum(type, PLUTOVG_TEXTURE_TYPE_TILED, "PLUTOVG_TEXTURE_TYPE_", 3)) {
		RETURN_THROWS();
	}
	plutovg_matrix_t m;
	if (zm) {
		pv_matrix_read(Z_OBJ_P(zm), &m);
	}
	pv_handle_keep(Z_OBJ_P(zc), Z_OBJ_P(zs), NULL);
	plutovg_canvas_set_texture(canvas, surface, (plutovg_texture_type_t) type, (float) opacity, zm ? &m : NULL);
}

ZEND_FUNCTION(plutovg_canvas_set_paint)
{
	zval *zc, *zp;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zp, pv_paint_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_paint_t *paint = NULL;
	if (zp) {
		if (!(paint = pv_handle_arg(zp, 2))) {
			RETURN_THROWS();
		}
		pv_handle_keep(Z_OBJ_P(zc), Z_OBJ_P(zp), NULL);
	}
	plutovg_canvas_set_paint(canvas, paint);
}

ZEND_FUNCTION(plutovg_canvas_get_paint)
{
	zval *zc, *zcolor;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zcolor, pv_color_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_color_t color;
	plutovg_paint_t *paint = plutovg_canvas_get_paint(canvas, zcolor ? &color : NULL);
	if (zcolor) {
		pv_color_write(Z_OBJ_P(zcolor), &color);
	}
	pv_handle_wrap(pv_paint_ce, paint ? plutovg_paint_reference(paint) : NULL, Z_OBJ_P(zc), return_value);
}

/* ---- fonts ----------------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_canvas_set_font_face_cache)
{
	zval *zc, *zcache;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zcache, pv_font_face_cache_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_font_face_cache_t *cache = NULL;
	if (zcache && !(cache = pv_handle_arg(zcache, 2))) {
		RETURN_THROWS();
	}
	plutovg_canvas_set_font_face_cache(canvas, cache);
}

ZEND_FUNCTION(plutovg_canvas_get_font_face_cache)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_font_face_cache_t *cache = plutovg_canvas_get_font_face_cache(canvas);
	pv_handle_wrap(pv_font_face_cache_ce, cache ? plutovg_font_face_cache_reference(cache) : NULL, NULL, return_value);
}

ZEND_FUNCTION(plutovg_canvas_add_font_face)
{
	zval *zc, *zf;
	char *family;
	size_t family_len;
	bool bold, italic;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_STRING(family, family_len)
		Z_PARAM_BOOL(bold) Z_PARAM_BOOL(italic)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zf, pv_font_face_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_font_face_t *face = NULL;
	if (zf && !(face = pv_handle_arg(zf, 5))) {
		RETURN_THROWS();
	}
	plutovg_canvas_add_font_face(canvas, family, bold, italic, face);
}

ZEND_FUNCTION(plutovg_canvas_add_font_file)
{
	zval *zc;
	char *family, *filename;
	size_t family_len, filename_len;
	bool bold, italic;
	zend_long ttcindex;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_STRING(family, family_len)
		Z_PARAM_BOOL(bold) Z_PARAM_BOOL(italic)
		Z_PARAM_PATH(filename, filename_len)
		Z_PARAM_LONG(ttcindex)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (ttcindex < 0 || ttcindex > INT_MAX) {
		zend_argument_value_error(6, "must be between 0 and INT_MAX");
		RETURN_THROWS();
	}
	if (php_check_open_basedir(filename)) {
		RETURN_FALSE;
	}
	RETURN_BOOL(plutovg_canvas_add_font_file(canvas, family, bold, italic, filename, (int) ttcindex));
}

ZEND_FUNCTION(plutovg_canvas_select_font_face)
{
	zval *zc;
	char *family;
	size_t family_len;
	bool bold, italic;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_STRING(family, family_len)
		Z_PARAM_BOOL(bold) Z_PARAM_BOOL(italic)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	RETURN_BOOL(plutovg_canvas_select_font_face(canvas, family, bold, italic));
}

ZEND_FUNCTION(plutovg_canvas_set_font)
{
	zval *zc, *zf;
	double size;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zf, pv_font_face_ce)
		Z_PARAM_DOUBLE(size)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_font_face_t *face = NULL;
	if (zf && !(face = pv_handle_arg(zf, 2))) {
		RETURN_THROWS();
	}
	plutovg_canvas_set_font(canvas, face, (float) size);
}

ZEND_FUNCTION(plutovg_canvas_set_font_face)
{
	zval *zc, *zf;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zf, pv_font_face_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_font_face_t *face = NULL;
	if (zf && !(face = pv_handle_arg(zf, 2))) {
		RETURN_THROWS();
	}
	plutovg_canvas_set_font_face(canvas, face);
}

ZEND_FUNCTION(plutovg_canvas_get_font_face)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_font_face_t *face = plutovg_canvas_get_font_face(canvas);
	pv_handle_wrap(pv_font_face_ce, face ? plutovg_font_face_reference(face) : NULL, NULL, return_value);
}

/* ---- state enums (PlutoVG indexes its compositing table with the operator) ------------------- */

ZEND_FUNCTION(plutovg_canvas_set_fill_rule)
{
	zval *zc;
	zend_long winding;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_LONG(winding)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (!pv_enum(winding, PLUTOVG_FILL_RULE_EVEN_ODD, "PLUTOVG_FILL_RULE_", 2)) {
		RETURN_THROWS();
	}
	plutovg_canvas_set_fill_rule(canvas, (plutovg_fill_rule_t) winding);
}

ZEND_FUNCTION(plutovg_canvas_set_operator)
{
	zval *zc;
	zend_long op;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_LONG(op)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (!pv_enum(op, PLUTOVG_OPERATOR_XOR, "PLUTOVG_OPERATOR_", 2)) {
		RETURN_THROWS();
	}
	plutovg_canvas_set_operator(canvas, (plutovg_operator_t) op);
}

ZEND_FUNCTION(plutovg_canvas_set_line_cap)
{
	zval *zc;
	zend_long cap;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_LONG(cap)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (!pv_enum(cap, PLUTOVG_LINE_CAP_SQUARE, "PLUTOVG_LINE_CAP_", 2)) {
		RETURN_THROWS();
	}
	plutovg_canvas_set_line_cap(canvas, (plutovg_line_cap_t) cap);
}

ZEND_FUNCTION(plutovg_canvas_set_line_join)
{
	zval *zc;
	zend_long join;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_LONG(join)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (!pv_enum(join, PLUTOVG_LINE_JOIN_BEVEL, "PLUTOVG_LINE_JOIN_", 2)) {
		RETURN_THROWS();
	}
	plutovg_canvas_set_line_join(canvas, (plutovg_line_join_t) join);
}

/* ---- dashes ---------------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_canvas_set_dash)
{
	zval *zc;
	double offset;
	HashTable *zdashes;
	zend_long ndashes;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(offset)
		Z_PARAM_ARRAY_HT(zdashes)
		Z_PARAM_LONG(ndashes)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	float *dashes;
	if (!pv_dashes(zdashes, ndashes, NULL, &dashes, 4)) {
		RETURN_THROWS();
	}
	plutovg_canvas_set_dash(canvas, (float) offset, dashes, (int) ndashes);
	if (dashes) efree(dashes);
}

ZEND_FUNCTION(plutovg_canvas_set_dash_array)
{
	zval *zc;
	HashTable *zdashes;
	zend_long ndashes;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_ARRAY_HT(zdashes)
		Z_PARAM_LONG(ndashes)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	float *dashes;
	if (!pv_dashes(zdashes, ndashes, NULL, &dashes, 3)) {
		RETURN_THROWS();
	}
	plutovg_canvas_set_dash_array(canvas, dashes, (int) ndashes);
	if (dashes) efree(dashes);
}

ZEND_FUNCTION(plutovg_canvas_get_dash_array)
{
	zval *zc, *zdashes;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_ZVAL(zdashes)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	const float *dashes = NULL;
	int n = plutovg_canvas_get_dash_array(canvas, &dashes);
	zval list;
	array_init_size(&list, (uint32_t) n);
	for (int i = 0; i < n; i++) {
		add_next_index_double(&list, dashes[i]);
	}
	ZEND_TRY_ASSIGN_REF_TMP(zdashes, &list);
	RETURN_LONG(n);
}

/* Before PlutoVG dashes `path` with the canvas's dash array: the bound pv_dashes puts on path dashing. */
static bool pv_stroke_ok(plutovg_canvas_t *canvas, const plutovg_path_t *path)
{
	const float *dashes = NULL;
	int n = plutovg_canvas_get_dash_array(canvas, &dashes);
	return n == 0 || pv_dash_bound(dashes, n, path, get_active_function_name());
}

/* ---- matrix ---------------------------------------------------------------------------------- */

ZEND_FUNCTION(plutovg_canvas_transform)
{
	zval *zc, *zm;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_matrix_t m;
	pv_matrix_read(Z_OBJ_P(zm), &m);
	plutovg_canvas_transform(canvas, &m);
}

ZEND_FUNCTION(plutovg_canvas_set_matrix)
{
	zval *zc, *zm;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_matrix_t m;
	pv_matrix_read(Z_OBJ_P(zm), &m);
	plutovg_canvas_set_matrix(canvas, &m);
}

ZEND_FUNCTION(plutovg_canvas_get_matrix)
{
	zval *zc, *zm;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zm, pv_matrix_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_matrix_t m;
	plutovg_canvas_get_matrix(canvas, &m);
	pv_matrix_write(Z_OBJ_P(zm), &m);
}

ZEND_FUNCTION(plutovg_canvas_map)
{
	zval *zc, *zxx, *zyy;
	double x, y;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
		Z_PARAM_ZVAL(zxx) Z_PARAM_ZVAL(zyy)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	float xx, yy;
	plutovg_canvas_map(canvas, (float) x, (float) y, &xx, &yy);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zxx, xx);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zyy, yy);
}

ZEND_FUNCTION(plutovg_canvas_map_point)
{
	zval *zc, *zs, *zd;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_point_ce)
		Z_PARAM_OBJECT_OF_CLASS(zd, pv_point_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_point_t src, dst;
	pv_point_read(Z_OBJ_P(zs), &src);
	plutovg_canvas_map_point(canvas, &src, &dst);
	pv_point_write(Z_OBJ_P(zd), &dst);
}

ZEND_FUNCTION(plutovg_canvas_map_rect)
{
	zval *zc, *zs, *zd;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zs, pv_rect_ce)
		Z_PARAM_OBJECT_OF_CLASS(zd, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_rect_t src, dst;
	pv_rect_read(Z_OBJ_P(zs), &src);
	plutovg_canvas_map_rect(canvas, &src, &dst);
	pv_rect_write(Z_OBJ_P(zd), &dst);
}

/* ---- path ------------------------------------------------------------------------------------ */

ZEND_FUNCTION(plutovg_canvas_arc)
{
	zval *zc;
	double cx, cy, r, a0, a1;
	bool ccw;
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(cx) Z_PARAM_DOUBLE(cy) Z_PARAM_DOUBLE(r)
		Z_PARAM_DOUBLE(a0) Z_PARAM_DOUBLE(a1)
		Z_PARAM_BOOL(ccw)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	/* As plutovg_path_add_arc: a NaN sweep makes PlutoVG cast NaN to its segment count. */
	if (!isfinite((float) a0) || !isfinite((float) a1)) {
		zend_argument_value_error(isfinite((float) a0) ? 6 : 5, "must be a finite angle");
		RETURN_THROWS();
	}
	plutovg_canvas_arc(canvas, (float) cx, (float) cy, (float) r, (float) a0, (float) a1, ccw);
}

ZEND_FUNCTION(plutovg_canvas_add_path)
{
	zval *zc, *zp;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_path_t *path = pv_path_arg(zp, 2);
	if (!path) {
		RETURN_THROWS();
	}
	/* plutovg_canvas_add_path is plutovg_path_add_path into the canvas's path: same self-add hazard. */
	if (path == plutovg_canvas_get_path(canvas)) {
		zend_argument_value_error(2, "must not be the canvas's own path; add a plutovg_path_clone() of it");
		RETURN_THROWS();
	}
	plutovg_canvas_add_path(canvas, path);
}

ZEND_FUNCTION(plutovg_canvas_get_current_point)
{
	zval *zc, *zx, *zy;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_ZVAL(zx) Z_PARAM_ZVAL(zy)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	float x, y;
	plutovg_canvas_get_current_point(canvas, &x, &y);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zx, x);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zy, y);
}

/* The canvas keeps its path; the returned handle takes a reference of its own (and sees later changes). */
ZEND_FUNCTION(plutovg_canvas_get_path)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	pv_path_wrap(plutovg_path_reference(plutovg_canvas_get_path(canvas)), return_value);
}

/* ---- strokes (each checks the dash bound first) ---------------------------------------------- */

ZEND_FUNCTION(plutovg_canvas_stroke_contains)
{
	zval *zc;
	double x, y;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (!pv_stroke_ok(canvas, plutovg_canvas_get_path(canvas))) {
		RETURN_THROWS();
	}
	RETURN_BOOL(plutovg_canvas_stroke_contains(canvas, (float) x, (float) y));
}

ZEND_FUNCTION(plutovg_canvas_fill_extents)
{
	zval *zc, *zr;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zr, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_rect_t extents;
	plutovg_canvas_fill_extents(canvas, &extents);
	pv_rect_write(Z_OBJ_P(zr), &extents);
}

ZEND_FUNCTION(plutovg_canvas_stroke_extents)
{
	zval *zc, *zr;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zr, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (!pv_stroke_ok(canvas, plutovg_canvas_get_path(canvas))) {
		RETURN_THROWS();
	}
	plutovg_rect_t extents;
	plutovg_canvas_stroke_extents(canvas, &extents);
	pv_rect_write(Z_OBJ_P(zr), &extents);
}

ZEND_FUNCTION(plutovg_canvas_clip_extents)
{
	zval *zc, *zr;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zr, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_rect_t extents;
	plutovg_canvas_clip_extents(canvas, &extents);
	pv_rect_write(Z_OBJ_P(zr), &extents);
}

ZEND_FUNCTION(plutovg_canvas_stroke)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (!pv_stroke_ok(canvas, plutovg_canvas_get_path(canvas))) {
		RETURN_THROWS();
	}
	plutovg_canvas_stroke(canvas);
}

ZEND_FUNCTION(plutovg_canvas_stroke_preserve)
{
	zval *zc;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (!pv_stroke_ok(canvas, plutovg_canvas_get_path(canvas))) {
		RETURN_THROWS();
	}
	plutovg_canvas_stroke_preserve(canvas);
}

ZEND_FUNCTION(plutovg_canvas_stroke_rect)
{
	zval *zc;
	double x, y, w, h;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y) Z_PARAM_DOUBLE(w) Z_PARAM_DOUBLE(h)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_path_t *rect = plutovg_path_create();
	plutovg_path_add_rect(rect, (float) x, (float) y, (float) w, (float) h);
	bool ok = pv_stroke_ok(canvas, rect);
	plutovg_path_destroy(rect);
	if (!ok) {
		RETURN_THROWS();
	}
	plutovg_canvas_stroke_rect(canvas, (float) x, (float) y, (float) w, (float) h);
}

ZEND_FUNCTION(plutovg_canvas_fill_path)
{
	zval *zc, *zp;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_path_t *path = pv_path_arg(zp, 2);
	if (!path) {
		RETURN_THROWS();
	}
	plutovg_canvas_fill_path(canvas, path);
}

ZEND_FUNCTION(plutovg_canvas_stroke_path)
{
	zval *zc, *zp;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_path_t *path = pv_path_arg(zp, 2);
	if (!path || !pv_stroke_ok(canvas, path)) {
		RETURN_THROWS();
	}
	plutovg_canvas_stroke_path(canvas, path);
}

ZEND_FUNCTION(plutovg_canvas_clip_path)
{
	zval *zc, *zp;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_OBJECT_OF_CLASS(zp, pv_path_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	plutovg_path_t *path = pv_path_arg(zp, 2);
	if (!path) {
		RETURN_THROWS();
	}
	plutovg_canvas_clip_path(canvas, path);
}

/* ---- text ------------------------------------------------------------------------------------ */

ZEND_FUNCTION(plutovg_canvas_add_glyph)
{
	zval *zc;
	zend_long codepoint;
	double x, y;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_LONG(codepoint)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (!pv_codepoint(codepoint, 2)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(plutovg_canvas_add_glyph(canvas, (plutovg_codepoint_t) codepoint, (float) x, (float) y));
}

ZEND_FUNCTION(plutovg_canvas_add_text)
{
	zval *zc;
	zend_string *text;
	zend_long length, encoding;
	double x, y;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(encoding)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	int units;
	if (!pv_text(text, length, encoding, &units, 3)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(plutovg_canvas_add_text(canvas, ZSTR_VAL(text), units, (plutovg_text_encoding_t) encoding, (float) x, (float) y));
}

ZEND_FUNCTION(plutovg_canvas_fill_text)
{
	zval *zc;
	zend_string *text;
	zend_long length, encoding;
	double x, y;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(encoding)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	int units;
	if (!pv_text(text, length, encoding, &units, 3)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(plutovg_canvas_fill_text(canvas, ZSTR_VAL(text), units, (plutovg_text_encoding_t) encoding, (float) x, (float) y));
}

/* plutovg_canvas_stroke_text is new_path, add_text, stroke; done in those steps so the glyph path can be checked. */
ZEND_FUNCTION(plutovg_canvas_stroke_text)
{
	zval *zc;
	zend_string *text;
	zend_long length, encoding;
	double x, y;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(encoding)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	int units;
	if (!pv_text(text, length, encoding, &units, 3)) {
		RETURN_THROWS();
	}
	plutovg_canvas_new_path(canvas);
	float advance = plutovg_canvas_add_text(canvas, ZSTR_VAL(text), units, (plutovg_text_encoding_t) encoding, (float) x, (float) y);
	if (!pv_stroke_ok(canvas, plutovg_canvas_get_path(canvas))) {
		plutovg_canvas_new_path(canvas);
		RETURN_THROWS();
	}
	plutovg_canvas_stroke(canvas);
	RETURN_DOUBLE(advance);
}

ZEND_FUNCTION(plutovg_canvas_clip_text)
{
	zval *zc;
	zend_string *text;
	zend_long length, encoding;
	double x, y;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(encoding)
		Z_PARAM_DOUBLE(x) Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	int units;
	if (!pv_text(text, length, encoding, &units, 3)) {
		RETURN_THROWS();
	}
	RETURN_DOUBLE(plutovg_canvas_clip_text(canvas, ZSTR_VAL(text), units, (plutovg_text_encoding_t) encoding, (float) x, (float) y));
}

ZEND_FUNCTION(plutovg_canvas_font_metrics)
{
	zval *zc, *zascent, *zdescent, *zgap, *zr;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_ZVAL(zascent) Z_PARAM_ZVAL(zdescent) Z_PARAM_ZVAL(zgap)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zr, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	float ascent, descent, line_gap;
	plutovg_rect_t extents;
	plutovg_canvas_font_metrics(canvas, &ascent, &descent, &line_gap, zr ? &extents : NULL);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zascent, ascent);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zdescent, descent);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zgap, line_gap);
	if (zr) {
		pv_rect_write(Z_OBJ_P(zr), &extents);
	}
}

ZEND_FUNCTION(plutovg_canvas_glyph_metrics)
{
	zval *zc, *zadvance, *zbearing, *zr;
	zend_long codepoint;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_LONG(codepoint)
		Z_PARAM_ZVAL(zadvance) Z_PARAM_ZVAL(zbearing)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zr, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	if (!pv_codepoint(codepoint, 2)) {
		RETURN_THROWS();
	}
	float advance_width, left_side_bearing;
	plutovg_rect_t extents;
	plutovg_canvas_glyph_metrics(canvas, (plutovg_codepoint_t) codepoint, &advance_width, &left_side_bearing, zr ? &extents : NULL);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zadvance, advance_width);
	ZEND_TRY_ASSIGN_REF_DOUBLE(zbearing, left_side_bearing);
	if (zr) {
		pv_rect_write(Z_OBJ_P(zr), &extents);
	}
}

ZEND_FUNCTION(plutovg_canvas_text_extents)
{
	zval *zc, *zr;
	zend_string *text;
	zend_long length, encoding;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(zc, pv_canvas_ce)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(encoding)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(zr, pv_rect_ce)
	ZEND_PARSE_PARAMETERS_END();
	CANVAS_ARG(zc, 1, canvas);
	int units;
	if (!pv_text(text, length, encoding, &units, 3)) {
		RETURN_THROWS();
	}
	plutovg_rect_t extents;
	float advance = plutovg_canvas_text_extents(canvas, ZSTR_VAL(text), units, (plutovg_text_encoding_t) encoding, zr ? &extents : NULL);
	if (zr) {
		pv_rect_write(Z_OBJ_P(zr), &extents);
	}
	RETURN_DOUBLE(advance);
}
