

.PHONY:clean

VPATH = ./header : ./source
SRC := $(wildcard ./source/*.c )
OBJECT := $(SRC:./source/%.c=%.o)

CC = gcc -Wall

INCLUDE= -I ./header


app:$(OBJECT)
	gcc $^ -o $@ 
	mv *.o ./obj
#	rm *.o 
%.o: %.c
	$(CC) -c $^ $(INCLUDE) -g
clean:
	rm app

