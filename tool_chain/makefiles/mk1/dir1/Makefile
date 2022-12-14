#.PHONY:clean

VPATH = ./src/ : ./hdr/ : ./obj/

INCLUDE = -I ./hdr/

#project: f1.o
#	gcc -o app f1.o

f1.o: f1.c headers.h
	gcc -c ./src/*.c $(INCLUDE)
	mv *.o ./obj

#clean:
#	rm ./obj/*.o
