#include <stdlib.h>
#include <stdio.h>
#include "core/Object/object.h"

void *new_obj(struct Object *new){
    return _object._class->constructor(new, 0);
    //return cls.constructor(cls.obj);
}

int main(void){
    struct Object *a, *b;
    a = (struct Object *)new_obj(a);
    b = (struct Object *)new_obj(b);
    a->_class->toString(a);
    b->_class->toString(b);
    printf("%d", a->_class->hash(a));
    printf("%d", b->_class->hash(b));
    printf("\nfirst%d second%d\n", a->_class->equals(a, b), a->_class->equals(a, a));
    a->_class->destructor(a);
    b->_class->destructor(b);
}
