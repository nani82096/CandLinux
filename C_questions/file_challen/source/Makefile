.PHONY:clean

VPATH = ../header : ./source
OBJECT = insert_bst.o inorder.o BST.o 
CC=gcc -Wall 

INCLUDE= -I ../header


BST:$(OBJECT)
	gcc $^ -o $@ 
	rm *.o 
%.o: %.c
	$(CC) -c $^ $(INCLUDE) -g
clean:
	rm BST

