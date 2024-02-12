struct Object{
    struct Class *_class;
};

struct Class{
    struct Object *_object;
    struct Object *super;
    void *(*constructor)(struct Object *self, struct Object *super);
    void (*destructor)(struct Object *self);
    int (*hash)(struct Object *self);
    void (*toString)(struct Object *self);
    int (*equals)(struct Object *self, struct Object *other);
};

void *object_constructor(struct Object *self, struct Object *super);
void object_destructor(struct Object *self);
int object_hash(struct Object *self);
void object_toString(struct Object *self);
int object_equals(struct Object *self, struct Object *other);

extern struct Object _object;