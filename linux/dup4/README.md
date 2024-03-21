# dup4

Addition of syscall to replace a file descriptor in another
process's table using our own as a reference.

This can be a nice, convenient way to replace, say, a daemon's
file descriptors with our own, such as for logging.

It's not extremely essential, but it's a fun little change
that I can use as I introduce myself to the Linux kernel.

## Patch Files

* file.c.patch -> fs/file.c
* syscall\_64.tbl -> arch/x86/entry/syscalls/syscall\_64.tbl
