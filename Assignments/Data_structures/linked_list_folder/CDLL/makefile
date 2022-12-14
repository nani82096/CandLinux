VPATH = ./header/ : ./source/
OBJECT = deletion.o  insertion.o  integervalidation_func.o  CDLL.o  Q8_str_atoi.o exit.o 
INCLUDE = -I ./header/ 
CDLL: $(OBJECT)
	gcc $^ -o $@
%.o:%.c
	gcc -c ./source/*.c $(INCLUDE)
mov :
	mkdir Object
	mv *.o ./Object
clean :
	rm -rf Object
