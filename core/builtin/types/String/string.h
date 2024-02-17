struct String{
    struct Class *_class;
    char *value;
    struct String *(*concat)(void *_self, void *_other);
};

void *string_constructor(void *_self, void *_super, ...);
void string_destructor(void *_self);
int string_hash(void *_self);
int string_equals(void *_self, void *_other);
struct String *concat(void *_self, void *_other);

extern struct String _string;