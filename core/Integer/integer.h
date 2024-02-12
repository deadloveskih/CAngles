struct Integer{
    struct Class *_class;
    int value;
};

void *integer_constructor(void *self, void *super, ...);
void integer_destructor(void *self);
int integer_hash(void *self);
void integer_toString(void *self);
int integer_equals(void *self, void *other);

extern struct Integer _integer;