all: dir1 dir2 

dir1: 
	$(MAKE) -C ./src1
dir2:
	$(MAKE) -C ./src2

clean:
	$(MAKE) clean -C ./src1
	$(MAKE) clean -C ./src2
move:
	cp src1/src1 ./srcc11
	cp src2/src2 ./srcc22

