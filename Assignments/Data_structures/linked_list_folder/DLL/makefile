VPATH = ./header/ : ./source/
OBJECT = deletion.o  insert.o  integervalidation_func.o  DLL.o  Q8_str_atoi.o
INCLUDE = -I ./header/ 
DLL: $(OBJECT)
	gcc $^ -o $@
%.o:%.c
	gcc -c ./source/*.c $(INCLUDE)
mov :
	mkdir Object
	mv *.o ./Object
clean :
	rm ./Object/*.o
	rmdir Object
