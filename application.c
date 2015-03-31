#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#define BUFF_SIZE 1024
int main(int argc,char *argv[])
{
int fd,len,ret;
char buff[BUFF_SIZE];
char *str = "hello to the world of linux kernel device driver.This is Salman's first kernel driver";
if (argc < 2) {
fprintf(stderr,"Insufficient number of arguments\n");
exit(EXIT_FAILURE);
}
fd = open(argv[1],O_WRONLY);
printf("Application open fd=%d\n",fd);
if (fd < 0) {
perror(":error in opening file");
exit(EXIT_FAILURE);
}
ret = write(fd,str,strlen(str));
if(ret < 0)
{
	fprintf(stderr,"write failed \n");
	exit(EXIT_FAILURE);
}
printf("No. of bytes written = %d\n",ret);
close(fd);
printf("Write Application close fd\n");

fd = open(argv[1],O_RDONLY);
printf("Application open fd=%d\n",fd);
if (fd < 0) {
perror(":error in opening file");
exit(EXIT_FAILURE);
}
//ret = read(fd,str,strlen(str));
close(fd);
printf("Read Application close fd\n");

return 0;
}
