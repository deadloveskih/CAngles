#include <stdlib.h>
#include <stdio.h>
#include "core/Object/object.h"

void *new_obj(){
    return cls.constructor(cls.obj);
}

int main(void){
    struct Object *a = (struct Object *)new_obj();
    a->cls->toString(a);
    printf("%d", a->cls->hash(a));
    a->cls->destructor(a);
}
