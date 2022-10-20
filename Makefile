SRC = src/ssp.cpp
INC = include
CFLAGS = -shared
LIBS = lib/linux_x64/libssp.so
OUT = libssp2.so

all:
	${CC} -I ${INC} ${CFLAGS} ${SRC} -o ${OUT} -Wl,--whole-archive ${LIBS} -Wl,--no-whole-archive

clean:
	rm -f ${OUT}
