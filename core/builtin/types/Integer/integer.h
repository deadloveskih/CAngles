struct Integer{
    struct Class *_class;
    int value;
};

void *integer_constructor(void *_self, void *_super, ...);
void integer_destructor(void *_self);
int integer_hash(void *_self);
void integer_toString(void *_self);

extern struct Integer _integer;