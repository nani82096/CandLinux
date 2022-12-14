

CC := gcc -Wall -g
app : main.o fun.o 
	gcc -o $@ $^
	mv app ../
%.o : %.c 
	$(CC) -DMAX=${VAL} -c $^
clean:
	rm main.o fun.o 
	rm ../app
	
