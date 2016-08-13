extern "C" {
	#include <dirent.h>	
	#include <unistd.h>
	#include <sys/wait.h>
}
#include <iostream>
#include <cstdio>
#include <string>

int main(int argc, char *argv[]) {
	
	printf("uid: %d, gid: %d\n", getuid(), getgid());
	return 0;
}
