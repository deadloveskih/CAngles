struct Float{
    struct Class *_class;
    float value;
};

void *float_constructor(void *_self, void *_super, ...);
void float_destructor(void *_self);
int float_hash(void *_self);
void float_toString(void *_self);

extern struct Float _float;