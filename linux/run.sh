#!/bin/sh
qemu-system-x86_64 \
	-accel kvm \
	-m 128M \
	-nographic \
	-kernel linux-*/arch/x86_64/boot/bzImage \
	-initrd ./rootfs.cpio.gz \
	-monitor /dev/null \
	-cpu qemu64 \
	-append 'root=/dev/ram init=/init console=ttyS0 loglevel=3 oops=panic panic=1 kaslr' \
