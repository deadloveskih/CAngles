struct Object{
    struct Class *cls;
    int x;
};

struct Class{
    struct Object *obj;
    void *(*constructor)(struct Object *self, int x);
    void (*destructor)(struct Object *self);
};

void *constructor(struct Object *self, int x);
void destructor(struct Object *self);

extern struct Class cls;