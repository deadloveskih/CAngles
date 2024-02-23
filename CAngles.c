#include <stdlib.h>
#include <stdio.h>
#include "core/builtin/types/Object/object.h"
#include "core/builtin/types/String/string.h"
#include "core/parser/bufferize/bufferize.h"

/*void *new_obj(struct Object *new){
    void *(*constructor)(void *, void *, ...) = _object._class->constructor;
    return constructor(new, 0);
}

void *new_string(struct String *new, char *value){
    void *(*constructor)(void *, void *, ...) = _string._class->constructor;
    return constructor(new, _object._class, value);
}*/

int main(int args, char *argv[]){
    /*struct Object *a, *b;
    a = (struct Object *)new_obj(a);
    b = (struct Object *)new_obj(b);
    void *(*OBJtoString)(void *) = _object._class->toString;
    int (*OBJhash)(void *) = _object._class->hash;
    int (*OBJequals)(void *, void *) = _object._class->equals;
    void (*OBJdestructor)(void *) = _object._class->destructor;
    OBJtoString(a);
    OBJtoString(b);
    printf("hash a - %d\n", OBJhash(a));
    printf("hash b - %d\n", OBJhash(b));
    printf("a = b (%d), a = a (%d)\n", OBJequals(a, b), OBJequals(a, a));
    OBJdestructor(a);
    OBJdestructor(b);

    printf("\n__________________________________________\n");
    struct String *x, *y;  
    x = (struct String *)new_string(x, "qwerty");
    y = (struct String *)new_string(y, "uiop");*/
    void *(*STRtoString)(void *) = _string._class->toString;
    int (*STRhash)(void *) = _string._class->hash;
    int (*STRequals)(void *, void *) = _string._class->equals;
    void (*STRdestructor)(void *) = _string._class->destructor;
    struct String *(*STRconcat)(void *, void *) = _string.concat;
    /*STRtoString(x);
    STRtoString(y);
    printf("hash x - %d\n", STRhash(x));
    printf("hash y - %d\n", STRhash(y));
    printf("x = y (%d), x = x (%d)\n", STRequals(x, y), STRequals(x, x));
    struct String *conc = STRconcat(x, y);
    printf("%s", conc->value);

    STRdestructor(x);
    STRdestructor(y);*/

    FILE *file = fopen(argv[1], "r");
    struct String *code = buffer(file);
    printf("%s", code->value);
}