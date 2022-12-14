.PHONY:clean

SLL:*.o 
	gcc -o $@ $^
%o:%c
	gcc -c $^ -I ../header
clean:
	rm *.o
