.PHONY:clean

VPATH = ./header : ./source
SRC = $(shell ls source )
OBJECT = $(SRC:%.c=%.o)

CC = gcc -Wall

INCLUDE= -I ./header


app:$(OBJECT)
	gcc $^ -o $@ 
	rm *.o 
%.o: %.c
	$(CC) -c $^ $(INCLUDE) -g
clean:
	rm app

