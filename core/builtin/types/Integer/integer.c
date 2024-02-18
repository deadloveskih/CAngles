#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include "../Object/object.h"
#include "integer.h"

void *integer_constructor(void *_self, void *_super, ...){
    va_list args;
    va_start(args, _super);
    struct Integer *self = (struct Integer *)_self;
    struct Class *super = (struct Class *)_super;
    self = malloc(sizeof(struct Integer));
    self->_class = malloc(sizeof(struct Class));
    self->_class->super = super;
    if(self->_class->super != 0){
        void *(*super_constructor)(void *, void *, ...) = self->_class->super->constructor;
        self->_class->super->_object = super_constructor(self->_class->super->_object, super->super); //Maybe problem
    }
    self->_class->_object = self;
    self->_class->constructor = &integer_constructor;
    self->_class->destructor = &integer_destructor;
    self->_class->hash = &integer_hash;
    self->_class->toString = &integer_toString;

    self->value = va_arg(args, int);
    va_end(args);

    return self;
}

void integer_destructor(void *_self){
    struct Integer *self = (struct Integer *)_self;
    void (*destructor)() = self->_class->super->destructor;
    destructor(self);
}

int integer_hash(void *_self){
    struct Integer *self = (struct Integer *)_self;
    int (*hash_method)(void *) = self->_class->super->hash;
    int hash = hash_method(self);
    return 31 * (uintptr_t)&(self->value) + hash;
}

void integer_toString(void *_self){
    struct Integer *self = (struct Integer *)_self;
    printf("Integer@%x, value: %d\n", self, self->value);
}

struct Class _integer_class = {0, (struct Class *)&_object._class, &integer_constructor, &integer_destructor, &integer_hash, &integer_toString, &object_equals};
struct Integer _integer = {&_integer_class, 0};