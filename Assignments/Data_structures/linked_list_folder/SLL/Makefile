VPATH = ./header/ : ./source/

OBJECT = deletion.o  insert.o  integervalidation_func.o  SLL.o  Q8_str_atoi.o swaplinks.o

INCLUDE = -I ./header/ 
CC = gcc -Wall

SLL: $(OBJECT)
	gcc $^ -o $@
	mv *.o ./Object
%.o:%.c
	$(CC) -c $^ $(INCLUDE)
clean :
	rm  -f Object/*.o SLL
