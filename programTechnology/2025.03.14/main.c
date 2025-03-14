#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
extern int errno;
int main(void) {
  /*  int fd = open("foo.txt", O_RDONLY | O_CREAT);
    printf("fd = %d", fd);
    if(fd < 0) {
        perror("Foo");
        _exit(1);
    }
    printf("opened file fd = %d", fd);
    if(close(fd)<0) {
        perror("c1");
        _exit(2);
    }
    printf("Closed file\n");*/
int fd,fs;
    char *c = (char*)calloc(100, sizeof(char));
    fd=open("foo.txt", O_RDONLY);
    if(fd < 0) {
        perror("c1");
        exit(1);
    }
    fs=read(fd,c,10);
    printf("called read(%d,c,10) returned: %d", fd, fs);
    c[fs] = '\0';
    return 0;
}
