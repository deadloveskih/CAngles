#include <stdio.h>
#include "bufferize.h"
#include "../../builtin/types/Object/object.h"
#include "../../builtin/types/String/string.h"

struct String *buffer(FILE *file){
    void *(*STRconstructor)(void *, void *, ...) = _string._class->constructor;
    void (*STRdestructor)(void *) = _string._class->destructor;
    struct String *(*STRconcat)(void *, void *) = _string.concat;
    
    char buf[100];
    struct String *code;
    code = STRconstructor(code, _object._class, " ");
    while(fgets(buf, 100, file)){
        struct String *line;
        struct String *old = code;

        line = STRconstructor(line, _object._class, buf);
        code = STRconcat(code, line);

        STRdestructor(line);
        STRdestructor(old);
    }
    return code;
}