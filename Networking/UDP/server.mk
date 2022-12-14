.PHONY:clean
VPATH= ./header ./src

INCLUDE = -I ./header

server: server.o
	gcc -o $@ $^ 
%.o:%.c header.h
	gcc -Wall -c  $^ $(INCLUDE)
clean:
	rm server.o
	rm server
