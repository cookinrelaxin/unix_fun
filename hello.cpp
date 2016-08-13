extern "C" {
	#include <dirent.h>	
	#include <unistd.h>
	#include <sys/wait.h>
}
#include <iostream>
#include <cstdio>
#include <string>

int main(int argc, char *argv[]) {
	
	//printf("hello world from process ID %ld\n", (long)getpid());
	std::cout<<"hello world from process ID "<<getpid()<<std::endl;
	
	return 0;
}
