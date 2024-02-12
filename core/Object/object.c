#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "object.h"

void *constructor(struct Object *self){
    printf("\nconstructor_start\n");
    self = malloc(sizeof(struct Object));
    self->cls = malloc(sizeof(struct Class));
    self->cls->obj = self;
    self->cls->constructor = &constructor;
    self->cls->destructor = &destructor;
    self->cls->hash = &hash;
    self->cls->toString = &toString;
    printf("\nconstructor_end\n");

    return self;
}

void destructor(struct Object *self){
    printf("\ndestructor_start\n");
    free(self->cls);
    printf("\ndestructor_end\n");
    free(self);
}

int hash(struct Object *self){
    printf("\nhash_start\n");
    uintptr_t hash = 12345;
    uintptr_t personality = (uintptr_t)self;
    //return 31 * personality + hash;
    return (hash << 3) ^ personality;
}

void toString(struct Object *self){
    printf("Object@%x", self);
}

struct Object obj = {0};
struct Class cls = {&obj, &constructor, &destructor, &hash, &toString};