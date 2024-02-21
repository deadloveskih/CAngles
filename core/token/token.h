enum token_type{
    _cls,
    _method,
    _sentence,
    _integer,
    _float, 
    _str,
    _bool,
    _cycle,
    _branching,
    _math
};

struct Token{
    char *start;
    char *end;
    enum token_type type;
};