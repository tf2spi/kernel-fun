#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>

#ifndef __NR_dup4
#define __NR_dup4 457
#endif

int main(int argc, char ** argv) {
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <file> <fd> [pid]\n", *argv);
		fprintf(stderr, "Default pid: parent\n");
		return EXIT_FAILURE;
	}

	const char *file = argv[1];
	int target = atoi(argv[2]);
	int pid = getppid();
	if (argc >= 4) {
		pid = atoi(argv[3]);
	}

	int fd = open(file, O_RDWR | O_CREAT, 0644);
	if (fd == -1) {
		perror("open");
		return EXIT_FAILURE;
	}

	fprintf(stderr, "dup %d -> %d on pid %d\n", fd, target, pid);
	int err = syscall(__NR_dup4, fd, target, 0, pid);
	if (err == -1) {
		perror("dup4");
		return EXIT_FAILURE;
	}

	// Multiple spinlocks were involved, some of which
	// may be aliased in the case (task == current),
	// so test this by using our own pid for dup4.
	// Note that dup3 is equivalent to dup4 with getpid().
	fprintf(stderr, "dup4 successful!\n");
	fprintf(stderr, "Let's try to break the kernel!\n");
	err = dup3(fd, 1, 0);
	if (err == -1) {
		perror("dup4 again");
	} else {
		fprintf(stderr, "Yay! Nothing broke!\n");
		printf("Testing dup4 on ourselves!\n");
		fflush(stdout);
	}
	return 0;
}
