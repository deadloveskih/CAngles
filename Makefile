string.o: core/builtin/types/String/string.c
		gcc -c core/builtin/types/String/string.c -o core/builtin/types/String/string.o
object.o: core/builtin/types/Object/object.c
		gcc -c core/builtin/types/Object/object.c -o core/builtin/types/Object/object.o
bufferize.o: core/parser/bufferize/bufferize.c
		gcc -c core/parser/bufferize/bufferize.c -o core/parser/bufferize/bufferize.o
CAngles: CAngles.c string.o object.o bufferize.o
		gcc -o CAngles CAngles.c core/builtin/types/String/string.o core/builtin/types/Object/object.o core/parser/bufferize/bufferize.o