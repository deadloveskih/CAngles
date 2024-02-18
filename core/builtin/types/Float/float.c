#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include "../Object/object.h"
#include "float.h"

void *float_constructor(void *_self, void *_super, ...){
    va_list args;
    va_start(args, _super);
    struct Float *self = (struct Float *)_self;
    struct Class *super = (struct Class *)_super;
    self = malloc(sizeof(struct Float));
    self->_class = malloc(sizeof(struct Class));
    self->_class->super = super;
    if(self->_class->super != 0){
        void *(*super_constructor)(void *, void *, ...) = self->_class->super->constructor;
        self->_class->super->_object = super_constructor(self->_class->super->_object, super->super); //Maybe problem
    }
    self->_class->_object = self;
    self->_class->constructor = &float_constructor;
    self->_class->destructor = &float_destructor;
    self->_class->hash = &float_hash;
    self->_class->toString = &float_toString;

    self->value = (float)va_arg(args, double);
    va_end(args);

    return self;
}

void float_destructor(void *_self){
    struct Float *self = (struct Float *)_self;
    void (*destructor)() = self->_class->super->destructor;
    destructor(self);
}

int float_hash(void *_self){
    struct Float *self = (struct Float *)_self;
    int (*hash_method)(void *) = self->_class->super->hash;
    int hash = hash_method(self);
    return 31 * (uintptr_t)&(self->value) + hash;
}

void float_toString(void *_self){
    struct Float *self = (struct Float *)_self;
    printf("Float@%x, value: %f\n", self, self->value);
}

struct Class _float_class = {0, (struct Class *)&_object._class, &float_constructor, &float_destructor, &float_hash, &float_toString, &object_equals};
struct Float _float = {&_float_class, 0};