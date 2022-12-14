.PHONY:clean
VPATH = ./Header ./Source


app:*.o
	gcc  $^ -o $@
%.o:%.c
	gcc -c $^  -I ../../../Header
clean:
	rm -f *.o app
