struct Object{
    struct Class *_class;
};

struct Class{
    void *_object;
    struct Class *super;
    void *(*constructor)(void *_self, void *_super, ...);
    void (*destructor)(void *_self);
    int (*hash)(void *_self);
    void (*toString)(void *_self);
    int (*equals)(void *_self, void *_other);
};

void *object_constructor(void *_self, void *_super, ...);
void object_destructor(void *_self);
int object_hash(void *_self);
void object_toString(void *_self);
int object_equals(void *_self, void *_other);

extern struct Object _object;