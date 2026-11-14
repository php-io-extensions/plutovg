/*
 * The binding's shared machinery: value structs (all float, so one reader and one
 * writer per struct), the handle objects, and argument checks PlutoVG does not make.
 */

#ifndef PV_RUNTIME_H
#define PV_RUNTIME_H

/* Byte orders of the straight 32-bit memory plutovg_surface_blend_colour/ramp write (binding addition). */
#define PV_MEMORY_RGBA 0
#define PV_MEMORY_BGRA 1
#define PV_MEMORY_ARGB 2
#define PV_MEMORY_ABGR 3

#include "php.h"
#include "plutovg.h"

extern zend_class_entry *pv_surface_ce, *pv_paint_ce, *pv_canvas_ce, *pv_font_face_ce, *pv_font_face_cache_ce;

/*
 * Surfaces, paints, canvases, font faces and caches: one reference each, plus `keep`, the PHP values
 * whose memory the C object may draw into (a create_for_data string, a create_for_address owner).
 * Anything built on a handle copies its keep list, so that memory outlives every C reference to it.
 */
typedef struct {
	void *ptr;     /* NULL once released by its *_destroy() */
	HashTable *keep;
	zend_object std;
} pv_handle_obj;

static inline pv_handle_obj *pv_handle_from(zend_object *o) { return (pv_handle_obj *) ((char *) o - XtOffsetOf(pv_handle_obj, std)); }

/* The live C pointer of a handle argument, or NULL with ValueError thrown. */
void *pv_handle_arg(zval *zv, uint32_t arg_num);
/* A new handle object of `ce` taking over one reference to ptr (NULL: null), keeping what `from` keeps. */
void pv_handle_wrap(zend_class_entry *ce, void *ptr, zend_object *from, zval *out);
/* Adds everything `from` keeps (and `value`, if given) to `to`'s keep list. */
void pv_handle_keep(zend_object *to, zend_object *from, zval *value);
/* Releases the object's reference now (the *_destroy() functions). */
void pv_handle_release(zend_object *o);

extern zend_class_entry *pv_point_ce, *pv_rect_ce, *pv_matrix_ce, *pv_color_ce, *pv_gradient_stop_ce,
	*pv_path_element_header_ce, *pv_path_element_ce, *pv_path_ce, *pv_path_iterator_ce, *pv_text_iterator_ce;

typedef struct {
	plutovg_path_t *path; /* NULL once plutovg_path_destroy() released it */
	zend_object std;
} pv_path_obj;

typedef struct {
	plutovg_path_iterator_t it;
	zend_object *path;                        /* the plutovg_path object it iterates; NULL until init */
	const plutovg_path_element_t *elements;   /* what the path held at init, to detect a change */
	int size;
	zend_object std;
} pv_path_iterator_obj;

typedef struct {
	plutovg_text_iterator_t it;
	zend_string *text; /* NULL until init */
	zend_object std;
} pv_text_iterator_obj;

static inline pv_path_obj *pv_path_from(zend_object *o) { return (pv_path_obj *) ((char *) o - XtOffsetOf(pv_path_obj, std)); }
static inline pv_path_iterator_obj *pv_path_iterator_from(zend_object *o) { return (pv_path_iterator_obj *) ((char *) o - XtOffsetOf(pv_path_iterator_obj, std)); }
static inline pv_text_iterator_obj *pv_text_iterator_from(zend_object *o) { return (pv_text_iterator_obj *) ((char *) o - XtOffsetOf(pv_text_iterator_obj, std)); }

void pv_runtime_minit(int module_number);

/* Value structs. read: object -> C; write: C -> existing object; new: C -> new object. */
void pv_point_read(zend_object *o, plutovg_point_t *out);
void pv_point_write(zend_object *o, const plutovg_point_t *in);
void pv_point_new(const plutovg_point_t *in, zval *out);
void pv_rect_read(zend_object *o, plutovg_rect_t *out);
void pv_rect_write(zend_object *o, const plutovg_rect_t *in);
void pv_matrix_read(zend_object *o, plutovg_matrix_t *out);
void pv_matrix_write(zend_object *o, const plutovg_matrix_t *in);
void pv_color_read(zend_object *o, plutovg_color_t *out);
void pv_color_write(zend_object *o, const plutovg_color_t *in);
void pv_gradient_stop_read(zend_object *o, plutovg_gradient_stop_t *out);

/* A list of $count plutovg_point from a PHP array (ValueError, false on a short list or a non-point). */
bool pv_points_read(HashTable *arr, zend_long count, plutovg_point_t *out, uint32_t arg_num);

/* The live path of an argument, or NULL with ValueError thrown. */
plutovg_path_t *pv_path_arg(zval *zv, uint32_t arg_num);
/* A new plutovg_path object taking over one reference (NULL: returns null). */
void pv_path_wrap(plutovg_path_t *path, zval *out);

/*
 * Dash arrays: $ndashes finite, non-negative floats from $dashes (emalloc'd into *out, NULL when 0).
 * When `path` is given and the dashes sum above zero, refuses a pattern that would split the path into
 * more than 2^22 dashes: PlutoVG's float dasher stops advancing (and never returns) long before that.
 */
bool pv_dashes(HashTable *dashes, zend_long ndashes, const plutovg_path_t *path, float **out, uint32_t arg_num);
/* The same bound for dashes already in C (a canvas's): false with ValueError naming `fn` when exceeded. */
bool pv_dash_bound(const float *dashes, int ndashes, const plutovg_path_t *path, const char *what);

/* Gradient stops: $nstops plutovg_gradient_stop from a list (emalloc'd into *out, NULL when 0). */
bool pv_stops(HashTable *stops, zend_long nstops, plutovg_gradient_stop_t **out, uint32_t arg_num);

/* An enum argument within [0, max]. */
bool pv_enum(zend_long value, zend_long max, const char *prefix, uint32_t arg_num);

/* A codepoint argument: 0..0xFFFFFFFF. */
bool pv_codepoint(zend_long value, uint32_t arg_num);

/* $length of a string argument PlutoVG would parse: -1 or 0..strlen. */
bool pv_length(zend_string *s, zend_long length, uint32_t arg_num);

/*
 * Text with an encoding: checks the encoding and the unit count, and resolves -1 to the units up to the
 * first zero unit inside the string (PlutoVG itself would scan past the end of a PHP string for UTF-16/32).
 */
bool pv_text(zend_string *s, zend_long length, zend_long encoding, int *units, uint32_t arg_num);

#endif
