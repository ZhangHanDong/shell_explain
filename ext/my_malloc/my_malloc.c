#include "ruby.h"

static VALUE rb_cMyMalloc;

void
Init_my_malloc()
{
    rb_cMyMalloc = rb_define_class("MyMalloc");
}
