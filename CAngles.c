#include <stdlib.h>
#include <stdio.h>
#include "core/Object/object.h"
#include "core/Integer/integer.h"
#include "core/Float/float.h"

void *new_obj(struct Object *new){
    return _object._class->constructor(new, 0);
}

void *new_int(struct Integer *new, int value){
    return _integer._class->constructor(new, _object._class, value);
}

void *new_float(struct Float *new, float value){
    return _float._class->constructor(new, _object._class, value);
}

int main(void){
    struct Object *a, *b;
    a = (struct Object *)new_obj(a);
    b = (struct Object *)new_obj(b);
    a->_class->toString(a);
    b->_class->toString(b);
    printf("%d\n", a->_class->hash(a));
    printf("%d\n", b->_class->hash(b));
    printf("\nfirst%d second%d\n", a->_class->equals(a, b), a->_class->equals(a, a));
    a->_class->destructor(a);
    b->_class->destructor(b);

    printf("\n____________________________________\n");
    struct Float *i, *j;
    j = (struct Float *)new_float(j, 5);
    i = (struct Float *)new_float(i, 10);
    i->_class->toString(i);
    j->_class->toString(j);
    printf("%d\n", i->_class->hash(i));
    printf("%d\n", j->_class->hash(j));
    printf("\nfirst%d second%d\n", i->_class->equals(i, j), j->_class->equals(j, j));
    i->_class->destructor(i);
    j->_class->destructor(j);

    printf("\n____________________________________\n");
    struct Integer *x, *y;
    x = (struct Integer *)new_int(x, 10);
    y = (struct Integer *)new_int(y, 5);
    x->_class->toString(x);
    y->_class->toString(y);
    printf("%d\n", x->_class->hash(x));
    printf("%d\n", y->_class->hash(y));
    printf("\nfirst%d second%d\n", x->_class->equals(x, y), y->_class->equals(y, y));
    x->_class->destructor(x);
    y->_class->destructor(y);

    
}
