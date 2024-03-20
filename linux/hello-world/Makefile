obj-m += hello-world.o

all:
	make -C ../linux-* M=$(PWD) modules
	cp hello-world.ko ../rootfs
clean:
	make -C ../linux-* M=$(PWD) clean
