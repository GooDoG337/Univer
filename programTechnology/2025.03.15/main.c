#include <stdio.h>
//#include <fcntl.h>
#include <stdlib.h>
//#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
int main(void) {
	/*int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd < 0) {
		perror("r2");
		exit(1);
	} write(fd, "osu!", strlen("osu!"));
	printf("Have written\n");
	close(fd);*/
	char buffer[100];
	int bytesload = syscall(SYS_read, 0, buffer, sizeof(buffer)-1);
	if(bytesload == 1) {
		perror("syscall failed");
		exit(1);
	}
	buffer[bytesload] = '\0';
	printf("Your type: %s", buffer);
	return 0;
}
// 0 -std::input
// 1 -std::cout
// 2 - std::err