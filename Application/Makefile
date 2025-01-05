#! /bin/bash
CC=gcc
CF= -c -Wall
DF=-DDEBUG
application: main.o init.o mainMenu.o exitProgram.o openDevice.o readDevice.o writeDevice.o lseekDevice.o closeDevice.o
	${CC} -o application main.o init.o mainMenu.o exitProgram.o openDevice.o readDevice.o writeDevice.o lseekDevice.o closeDevice.o
main.o: main.c f_headers.h f_declarations.h
	${CC} ${CF} ${DF} main.c
init.o: init.c f_headers.h f_declarations.h
	${CC} ${CF} ${DF} init.c
mainMenu.o: mainMenu.c f_headers.h f_declarations.h
	${CC} ${CF} ${DF} mainMenu.c
exitProgram.o: exitProgram.c f_headers.h f_declarations.h
	${CC} ${CF} ${DF} exitProgram.c
openDevice.o: openDevice.c f_headers.h f_declarations.h
	${CC} ${CF} ${DF} openDevice.c
readDevice.o: readDevice.c f_headers.h f_declarations.h
	${CC} ${CF} ${DF} readDevice.c
writeDevice.o: writeDevice.c f_headers.h f_declarations.h
	${CC} ${CF} ${DF} writeDevice.c
lseekDevice.o: lseekDevice.c f_headers.h f_declarations.h
	${CC} ${CF} ${DF} lseekDevice.c
closeDevice.o: closeDevice.c f_headers.h f_declarations.h
	${CC} ${CF} ${DF} closeDevice.c
clean:
	-rm -f application
	-rm *.o

