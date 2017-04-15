CCFLAGS =  -O2 -g
LFLAGS = -lm

default:
	${CC} -c ${CCFLAGS} tinyexpr/tinyexpr.c
	${CC} -c ${CCFLAGS} expr.c -I tinyexpr
	ar rc libsoundpipe_expr.a *.o
	ranlib libsoundpipe_expr.a

shared:
	${CC} -fPIC -c ${CCFLAGS} tinyexpr/tinyexpr.c
	${CC} -fPIC -c ${CCFLAGS} expr.c -I tinyexpr
	${CC} -shared ${CCFLAGS} *.o  -o expr.so

test: default
	make -C examples/

clean:
	rm -f *.o *.a *.so
