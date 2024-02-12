struct Object{
    struct Class *cls;
};

struct Class{
    struct Object *obj;
    void *(*constructor)(struct Object *self);
    void (*destructor)(struct Object *self);
    int (*hash)(struct Object *self);
    void (*toString)(struct Object *self);
};

void *constructor(struct Object *self);
void destructor(struct Object *self);
int hash(struct Object *self);
void toString(struct Object *self);

extern struct Class cls;