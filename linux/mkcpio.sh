#!/bin/sh

cd rootfs || exit
find .  -depth -print  | cpio -o -H newc -R root:root | gzip >../rootfs.cpio.gz
cd $OLDPWD
