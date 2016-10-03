CC = gcc
CFLAGS = -O3
mailcount: mailcount.o filecount
	${CC} mailcount.o ${CFLAGS} -o mailcount
mailcount.o:
	${CC} mailcount.c ${CFLAGS} -c
filecount: filecount.o
	${CC} filecount.o ${CFLAGS} -o filecount
filecount.o:
	${CC} filecount.c ${CFLAGS} -c
clean:
	rm -rf *.o
	rm -rf mailcount
	rm -rf filecount
install:
	cp mailcount /bin
	cp filecount /bin
