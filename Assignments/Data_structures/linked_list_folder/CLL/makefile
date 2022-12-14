VPATH = ./header/ : ./source/
OBJECT = deletion.o  cl_insert.o  integervalidation_func.o  CLL.o  Q8_str_atoi.o
INCLUDE = -I ./header/ 
CLL: $(OBJECT)
	gcc $^ -o $@
	mv *.o ./Object
	rm ./Object/*.o
	rmdir Object
%.o:%.c
	gcc -c ./source/*.c $(INCLUDE) 
