#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "../Object/object.h"
#include "string.h"

void *string_constructor(void *_self, void *_super, ...){
    va_list args;
    va_start(args, _super);
    char *value = va_arg(args, char *);
    struct String *self = (struct String *)_self;
    struct Class *super = (struct Class *)_super;
    self = malloc(sizeof(struct String));
    self->_class = malloc(sizeof(struct Class));
    self->value = malloc(sizeof(char) * strlen(value));
    self->_class->super = super;
    if(self->_class->super != 0){
        self->_class->super->constructor(self, super->super); //Maybe problem
    }
    self->_class->_object = self;
    self->_class->constructor = &string_constructor;
    self->_class->destructor = &string_destructor;
    self->_class->hash = &string_hash;
    self->_class->toString = &object_toString;
    self->_class->equals = &string_equals;
    self->concat = &concat;
    strcpy(self->value, value);
    return self;
}

void string_destructor(void *_self){
    struct String *self = (struct String *)_self;
    free(self->value);
    self->_class->super->destructor(self);
}

int string_hash(void *_self){
    struct String *self = (struct String *)_self;
    int hash = self->_class->super->hash(self);
    return 31 * (uintptr_t)&(self->value) + hash;
}

int string_equals(void *_self, void *_other){
    struct String *self = (struct String *)_self;
    struct String *other = (struct String *)_other;
    return strcmp(self->value, other->value);
}

struct String *concat(void *_self, void *_other){
    struct String *self = (struct String *)_self;
    struct String *other = (struct String *)_other;
    size_t size_self = sizeof(char) * strlen(self->value);
    size_t size_other = sizeof(char) * strlen(other->value);
    char *result = malloc(size_self + size_other + 1);

    int divider = 0;
    for(int i = 0; i < size_self + size_other; i++){
        if(divider == 0){
            result[i] = self->value[i];
            if(!self->value[i+1]){
                divider = 1;
            }
        }else{
            result[i] = other->value[i - size_self];
        }
    }
    struct String *new;
    return (struct String *)string_constructor(new, _object._class, result);
}


struct Class _string_class = {0, (struct Class *)&_object._class, &string_constructor, &string_destructor, &string_hash, &object_toString, &string_equals};
struct String _string = {&_string_class, "", &concat};