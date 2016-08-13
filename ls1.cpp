extern "C" {
	#include <dirent.h>	
}
#include <iostream>
#include <cstdio>
#include <string>

int main(int argc, char *argv[]) {

	DIR *dp;
	dirent *dirp;
	
	if (argc != 2) {
		perror("usage: ls directory_name");
		exit(1);
	}
	if ((dp = opendir(argv[1])) == nullptr) {
		std::string dirname(argv[1]);
		std::string e("can't open " + dirname);
		perror(e.c_str());
		exit(1);
	}
	while ((dirp = readdir(dp)) != nullptr)
		std::cout<<dirp->d_name<<std::endl;
	closedir(dp);

	return 0;
}
