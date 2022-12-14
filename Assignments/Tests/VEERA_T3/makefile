VPATH = ./header/ : ./source/
OBJECT = q2.o  
INCLUDE = -I ./header/ 
Q2: $(OBJECT)
	gcc $^ -o $@
%.o:%.c
	gcc -c ./source/*.c $(INCLUDE)
mov :
	mv Q2 ./obj	
	mv *.o ./obj
clean :
	rm -rf obj
