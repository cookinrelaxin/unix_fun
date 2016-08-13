extern "C" {
	#include <dirent.h>	
	#include <unistd.h>
	#include <sys/wait.h>
}
#include <iostream>
#include <cstdio>
#include <string>

#define MAXLINE 4096

void sig_int(int) {
	printf("interrupt\n%% ");
}

int main(int argc, char *argv[]) {

	char buf[MAXLINE];
	pid_t pid;
	int status;

	if(signal(SIGINT, sig_int) == SIG_ERR) {
		perror("signal error");
		exit(1);
	}

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != nullptr) {
		if (buf[strlen(buf) -1] == '\n')
			buf[strlen(buf) -1] = 0;
		if ((pid = fork()) < 0) {
			perror("fork error");
			exit(1);
		}
		else if (pid == 0) {
			execlp(buf, buf, (char *)0);
			std::string err("couldn't execute ");
			err += buf;
			perror(err.c_str());
			exit(127);
		}
		if ((pid = waitpid(pid, &status, 0)) < 0) {
			perror("waitpid error");
			exit (1);
		}
		printf("%% ");
	}
	
	return 0;
}
