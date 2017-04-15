CFLAGS= -I.. -I../tinyexpr -lsoundpipe ../libsoundpipe_expr.a -lsndfile
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.bin)
TST=$(SRC:.c=.test)

all: ${OBJ}

%.bin : %.c
	gcc -g --std=c99 -I ../h -L /usr/local/lib -I /usr/local/include $< ${CFLAGS} -o $@ -lm

%.test : %.bin
	valgrind --leak-check=yes ./$< 2<&1 | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0" > /dev/null

test: ${TST}

clean:
	rm -f *.bin test.wav
