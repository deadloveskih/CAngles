#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include "../Object/object.h"
#include "float.h"

void *float_constructor(void *_self, void *_super, ...){
    va_list args;
    va_start(args, _super);
    struct Float *self = (struct Float *)_self;
    struct Class *super = (struct Class *)_super;
    self = malloc(sizeof(struct Float) + sizeof(self->_class->super));
    self->_class = malloc(sizeof(struct Class));
    self->_class->super = super;
    if(self->_class->super != 0){
        self->_class->super->constructor(self, super->super); //Maybe problem
    }
    self->_class->_object = self;
    self->_class->constructor = &float_constructor;
    self->_class->destructor = &float_destructor;
    self->_class->hash = &float_hash;
    self->_class->toString = &float_toString;
    self->_class->equals = &float_equals;

    self->value = (float)va_arg(args, double);
    va_end(args);

    return self;
}

void float_destructor(void *_self){
    struct Float *self = (struct Float *)_self;
    self->_class->super->destructor(self);
}

int float_hash(void *_self){
    struct Float *self = (struct Float *)_self;
    int hash = self->_class->super->hash(self);
    return 31 * (uintptr_t)&(self->value) + hash;
}

void float_toString(void *_self){
    struct Float *self = (struct Float *)_self;
    printf("Float@%x, value: %f\n", self, self->value);
}

int float_equals(void *_self, void *_other){
    struct Float *self = (struct Float *)_self;
    struct Float *other = (struct Float *)_other;
    return self->value == other->value;
}

struct Class _float_class = {0, (struct Class *)&_object._class, &float_constructor, &float_destructor, &float_hash, &float_toString, &float_equals};
struct Float _float = {&_float_class, 0};