obj-m:= page_walk.o

KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules 

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app
	rmmod page_walk
	dmesg -C

insert: 
	insmod page_walk.ko devname=myChar	
