
CC := gcc -Wall -g

app : main.o $(FF).o 
	gcc -o $@ $^
	mv app ../
main.o : main.c 
	$(CC) -DMAX=23 -c $^
$(FF).o:$(FF).c
	$(CC) -c -DMAX=23 $^ 
clean:
	rm main.o fun.o 
	rm ../app
