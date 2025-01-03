obj-m += LKM.o
LKM-objs := init.o cleanup.o openMyCDD.o closeMyCDD.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
