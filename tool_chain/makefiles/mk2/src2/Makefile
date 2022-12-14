
src2: hello.o 
	gcc -o src2 ./Object/hello.o 

hello.o: ./Source/hello.c
	gcc -c -DMAX=100  ./Source/hello.c -I ./Header
	mv hello.o ./Object

clean:
	rm ./src2
