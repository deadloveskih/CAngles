#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
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
        self->_class->super->constructor(self, super->super); //Maybe problem
    }
    self->_class->_object = self;
    self->_class->constructor = &integer_constructor;
    self->_class->destructor = &integer_destructor;
    self->_class->hash = &integer_hash;
    self->_class->toString = &integer_toString;
    self->_class->equals = &integer_equals;

    self->value = va_arg(args, int);
    va_end(args);

    return self;
}

void integer_destructor(void *_self){
    struct Integer *self = (struct Integer *)_self;
    self->_class->super->destructor(self);
    free(self->_class);
    free(self);
}

int integer_hash(void *_self){
    struct Integer *self = (struct Integer *)_self;
    int hash = self->_class->super->hash(self->_class->super->_object);
    return 31 * (uintptr_t)&(self->value) + hash;
}

void integer_toString(void *_self){
    struct Integer *self = (struct Integer *)_self;
    printf("Integer@%x, value: %d\n", self, self->value);
}

int integer_equals(void *_self, void *_other){
    struct Integer *self = (struct Integer *)_self;
    struct Integer *other = (struct Integer *)_other;
    return self->value == other->value;
}

struct Class _integer_class = {0, (struct Class *)&_object._class, &integer_constructor, &integer_destructor, &integer_hash, &integer_toString, &integer_equals};
struct Integer _integer = {&_integer_class, 0};