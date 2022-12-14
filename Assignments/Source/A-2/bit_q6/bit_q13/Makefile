.PHONY:clean
VPATH = ./Header ./Source


app:*.o
	gcc  $^ -o $@
%.o:%.c
	gcc -c $^ -o $@  -I ../../../Header
clean:
	rm -f *.o app
