.PHONY:clean
VPATH= ./header ./src ./obj

INCLUDE = -I ./header

client: client.o
	gcc -o $@ $^ 
%.o:%.c header.h
	gcc -Wall -c  $^ $(INCLUDE)
mov:
	mv *.o ./obj
clean:
	rm client.o
	rm client
