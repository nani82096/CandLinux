.PHONY : clean

VPATH = ./bit_q1/ : ../../Header/ 

CC = gcc -Wall

INCLUDE = -I ../../Header/

OBJECT = bit_q1.o bit_swap.o integervalidation_func.o Q8_str_atoi.o showbits.o

all : $(OBJECT)
	$(CC) $^ $(INCLUDE) -o $@
	
%.o: %.c  
	$(CC) -c $^ $(INCLUDE) 
	#mv $@ ./bit_obj/ 

clean :
	-rm *.o all




