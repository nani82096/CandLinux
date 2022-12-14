.PHONY : clean

VPATH = ./q6/ : ../../Header/ : ./q6/

CC = gcc -Wall

INCLUDE = -I ../../Header/

#OBJECT is a variable,which has to be intialized to the object files present in your directory as I did
OBJECT = q6.o q6_file.o q6_file_write.o

all : $(OBJECT)
	$(CC) $^ $(INCLUDE) -o $@
	
%.o: %.c  
	$(CC) -c $^ $(INCLUDE) 
	mv $@ ./q6/ 

clean :
	-rm ./q6/*.o all




