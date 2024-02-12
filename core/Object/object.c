#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "object.h"

void *object_constructor(struct Object *self, struct Object *super){
    printf("\nconstructor_start\n");
    self = malloc(sizeof(struct Object));
    self->_class = malloc(sizeof(struct Class));
    self->_class->super = super;
    if(self->_class->super != 0){
        self->_class->super->_class->constructor(self, 0);
    }
    self->_class->_object = self;
    self->_class->constructor = &object_constructor;
    self->_class->destructor = &object_destructor;
    self->_class->hash = &object_hash;
    self->_class->toString = &object_toString;
    self->_class->equals = &object_equals;
    printf("\nconstructor_end\n");

    return self;
}

void object_destructor(struct Object *self){
    printf("\ndestructor_start\n");
    free(self->_class);
    printf("\ndestructor_end\n");
    free(self);
}

int object_hash(struct Object *self){
    printf("\nhash_start\n");
    uintptr_t hash = 12345;
    uintptr_t personality = (uintptr_t)self;
    //return 31 * personality + hash;
    return (hash << 3) ^ personality;
}

void object_toString(struct Object *self){
    printf("Object@%x\n", self);
}

int object_equals(struct Object *self, struct Object *other){
    return self == other;
}

struct Class _class = {0, 0, &object_constructor, &object_destructor, &object_hash, &object_toString};
struct Object _object = {&_class};