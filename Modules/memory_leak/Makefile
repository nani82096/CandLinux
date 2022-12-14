obj-m:=memory.o
KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	insmod memory.ko devname=mydev
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app
	rmmod travel

