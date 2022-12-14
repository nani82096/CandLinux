obj-m:= kmod1.o kmod2.o

KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_kmod  
	rmmod kmod2
	rmmod kmod1
	rm -r /lib/modules/4.4.1/mymodules
copy:
	mkdir /lib/modules/4.4.1/mymodules
	cp *.ko /lib/modules/4.4.1/mymodules
                                  

