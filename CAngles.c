#include <stdlib.h>
#include <stdio.h>
#include "core/builtin/types/Object/object.h"
#include "core/builtin/types/Integer/integer.h"
#include "core/builtin/types/Float/float.h"
#include "core/builtin/types/String/string.h"

void *new_obj(struct Object *new){
    void *(*constructor)(void *, void *, ...) = _object._class->constructor;
    return constructor(new, 0);
}

void *new_int(struct Integer *new, int value){
    void *(*constructor)(void *, void *, ...) = _integer._class->constructor;
    return constructor(new, 0);
}

void *new_float(struct Float *new, float value){
    void *(*constructor)(void *, void *, ...) = _float._class->constructor;
    return constructor(new, 0);
}

void *new_string(struct String *new, char *value){
    void *(*constructor)(void *, void *, ...) = _string._class->constructor;
    return constructor(new, 0);
}

int main(void){
    struct Object *a, *b;
    a = (struct Object *)new_obj(a);
    b = (struct Object *)new_obj(b);
    void *(*OBJtoString)(void *) = _object._class->toString;
    int (*OBJhash)(void *) = _object._class->hash;
    int (*OBJequals)(void *, void *) = _object._class->equals;
    OBJtoString(a);
    OBJtoString(b);
    printf("hash a - %d\n", OBJhash(a));
    printf("hash b - %d\n", OBJhash(b));
    printf("a = b (%d), a = a (%d)\n", OBJequals(a, b), OBJequals(a, a));
}