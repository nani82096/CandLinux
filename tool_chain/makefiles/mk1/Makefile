#VPATH = ./dir1/ : ./dir2/obj/ : ./dir2/
all :dir12 dir11 project
	
project: ./dir2/obj/f1.o
	gcc $^ -o $@
#	rm ./dir2/obj/*.o
#	rm ./dir1/obj/*.o
		
dir12:
		$(MAKE) -C ./dir1
dir11:
		$(MAKE) -C ./dir2
