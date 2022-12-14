.PHONY:clean

VPATH = ../header : ./source
OBJECT = integervalidation_func.o Q8_str_atoi.o max.o max.o delete.o insert_bst.o inorder1.o postorder.o level.o sum_all.o preorder1.o mirror.o BST.o 
CC=gcc -Wall 

INCLUDE= -I ../header


BST:$(OBJECT)
	gcc $^ -o $@
	rm *.o 
%.o: %.c
	$(CC) -c $^ $(INCLUDE) -g


