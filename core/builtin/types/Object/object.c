#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include "object.h"

void *object_constructor(void *_self, void *_super, ...){
    struct Object *self = (struct Object *)_self;
    struct Class *super = (struct Class *)_super;
    self = malloc(sizeof(struct Object));
    self->_class = malloc(sizeof(struct Class));
    self->_class->super = super;
    if(self->_class->super != 0){
        void *(*super_constructor)(void *, void *, ...) = self->_class->super->constructor;
        self->_class->super->_object = super_constructor(self->_class->super->_object, super->super); //Maybe problem
    }
    self->_class->_object = self;
    self->_class->constructor = &object_constructor;
    self->_class->destructor = &object_destructor;
    self->_class->hash = &object_hash;
    self->_class->toString = &object_toString;
    self->_class->equals = &object_equals;
    return self;
}

void object_destructor(void *_self){
    struct Object *self = (struct Object *)_self;
    free(self->_class);
    free(self);
}

int object_hash(void *_self){
    struct Object *self = (struct Object *)_self;
    uintptr_t hash = 12345;
    uintptr_t personality = (uintptr_t)self;
    //return 31 * personality + hash;
    return (hash << 3) ^ personality;
}

void object_toString(void *_self){
    struct Object *self = (struct Object *)_self;
    printf("Object@%x\n", self);
}

int object_equals(void *_self, void *_other){
    struct Object *self = (struct Object *)_self;
    struct Object *other = (struct Object *)_other;
    return self == other;
}

struct Class _class = {0, 0, &object_constructor, &object_destructor, &object_hash, &object_toString, &object_equals};
struct Object _object = {&_class};