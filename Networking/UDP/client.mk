.PHONY:clean
VPATH= ./header ./src

INCLUDE = -I ./header

client: client.o
	gcc -o $@ $^ 
%.o:%.c header.h
	gcc -Wall -c  $^ $(INCLUDE)
clean:
	rm client.o
	rm client
