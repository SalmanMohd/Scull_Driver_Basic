INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m := lkm.o

lkm-objs := init.o cleanup.o dev_open.o dev_close.o creat_scull.o dev_write.o dev_read.o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE)  -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	-rm -rf ${INSTALL_DIR}
	-rm -f modules.order
	-rm -f Module.symvers
	-rm -rf .tmp_versions
	-rm -f init.o
	-rm -f cleanup.o
	-rm -f dev_open.o
	-rm -f dev_close.o
	-rm -f create_scull.o
	-rm -f dev_write.o
	-rm -f dev_read.o
endif

