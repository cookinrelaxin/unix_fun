extern "C" {
	#include <dirent.h>	
	#include <unistd.h>
}
#include <iostream>
#include <cstdio>
#include <string>

#define BUFFSIZE 4096

int main(int argc, char *argv[]) {
	
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf,  n) != n) {
			perror("write error");
			exit(1);
		}
	if (n < 0) {
		perror("read error");
		exit(1);
	}

	return 0;
}
