obj-m:=r8169_mod.o

KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
CFLAGS_r8169Mod.o=-w

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_kmod app

