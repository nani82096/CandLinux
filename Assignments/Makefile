.PHONY : clean

VPATH = ./source/ : ./header/ : ./object/

CC = gcc -Wall

INCLUDE = -I ./header/

#OBJECT is a variable,which has to be intialized to the object files present in your directory as I did
OBJECT = atob.o main.o myatoi.o read_num.o string_valid.o num_valid.o

all : $(OBJECT)
	$(CC) $^ $(INCLUDE) -o $@
	
%.o: %.c  
	$(CC) -c $^ $(INCLUDE) 
	mv $@ ./object/ 

clean :
	-rm ./object/*.o all




