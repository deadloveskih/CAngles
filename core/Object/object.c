#include <stdlib.h>
#include <stdio.h>
#include "object.h"

void *constructor(struct Object *self, int x){
    printf("constructor");
    self = malloc(sizeof(struct Object));
    self->cls = malloc(sizeof(struct Class));
    self->cls->obj = self;
    self->cls->constructor = &constructor;
    self->cls->destructor = &destructor;
    self->x = x;

    return self;
}

void destructor(struct Object *self){
    printf("destructor");
    free(self->cls);
    free(self);
}

struct Object obj = {0};
struct Class cls = {&obj, &constructor, &destructor};