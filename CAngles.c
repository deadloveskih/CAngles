#include <stdlib.h>
#include <stdio.h>
#include "core/Object/object.h"


int main(void){
    struct Object a = *(struct Object *)cls.constructor(cls.obj, 5);
    printf("%d", a.x);
    cls.destructor(cls.obj);
}
