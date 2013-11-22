#include <ruby.h>

/*
 * This structure holds the size of the pointer (to make cleanup easier) and
 * the pointer to the allocated memory.  Data_Make_Struct() and
 * Data_Get_Struct will extract this structure from the wrapped object so you
 * can work with the pointer.
 */

struct my_malloc {
    size_t size;
    void *ptr;
};

/*
 * This frees the internal pointer at garbage-collection time.  Ruby will free
 * the struct my_malloc for us.
 */

static void
my_malloc_free(void *p) {
    struct my_malloc *ptr = p;

    if (ptr->size > 0)
        free(ptr->ptr);
}

/*
 * This allocates the object and default values for the struct my_malloc.
 */

static VALUE
my_malloc_alloc(VALUE klass) {
    VALUE obj;
    struct my_malloc *ptr;

    /* there is no mark function as struct my_malloc does not store ruby
     * objects
     */

    obj = Data_Make_Struct(klass, struct my_malloc, NULL, my_malloc_free, ptr);

    ptr->size = 0;
    ptr->ptr  = NULL;

    return obj;
}

/*
 * This is #initialize which allocates some memory and stores the pointer in
 * struct my_malloc.  (There's not anything useful you can do with the memory,
 * though.)
 */

static VALUE
my_malloc_init(VALUE self, VALUE size) {
    struct my_malloc *ptr;
    size_t requested = NUM2SIZET(size);

    if (0 == requested)
        rb_raise(rb_eArgError, "unable to allocate 0 bytes");

    Data_Get_Struct(self, struct my_malloc, ptr);

    ptr->ptr = malloc(requested);

    if (NULL == ptr->ptr)
        rb_raise(rb_eNoMemError, "unable to allocate %ld bytes", requested);

    ptr->size = requested;

    return self;
}

/*
 * This frees the internal pointer so you can explicitly control the lifetime
 * of the held memory (instead of waiting for GC).  If you don't free the
 * memory the GC will do it for us.
 */

static VALUE
my_malloc_release(VALUE self) {
    struct my_malloc *ptr;

    Data_Get_Struct(self, struct my_malloc, ptr);

    if (0 == ptr->size)
        return self;

    ptr->size = 0;
    free(ptr->ptr);

    return self;
}

/*
 * This defines the C functions as extensions.
 *
 * The name of the Init_ function is important.  What follows Init_ must match
 * the file name (including case) so ruby knows what method to call to define
 * the extensions.
 */

void
Init_my_malloc(void) {
    VALUE cMyMalloc;

    cMyMalloc = rb_const_get(rb_cObject, rb_intern("MyMalloc"));

    rb_define_alloc_func(cMyMalloc, my_malloc_alloc);
    rb_define_method(cMyMalloc, "initialize", my_malloc_init, 1);
    rb_define_method(cMyMalloc, "free", my_malloc_release, 0);
}
