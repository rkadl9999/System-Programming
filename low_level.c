//low_level.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int write_file(void){
	int fd;
	fd = open("systemP",O_WRONLY|O_CREAT, 0600);
	if(fd==-1){
		printf("open() errer\n");
		return -1;
	}
	dprintf(fd,"system programming\n");
	close(fd);
	return 0;
}

static int trunc_file(void){
	int fd;
	fd = open("systemP", O_WRONLY|O_CREAT|O_TRUNC, 0600);
	if(fd==-1){
		printf("open() error\n");
		return -1;
	}
	dprintf(fd,"start again");
	close(fd);
	return 0;
}

static int append_file(void){
	int fd;
	fd = open("systemP",O_WRONLY|O_APPEND);
	if(fd==-1){
		printf("open() error\n");
		return -1;
	}
	dprintf(fd, "THE END");
	close(fd);
	return 0;
}

int main(){
	if(write_file()){
		printf("write_file() error\n");
		return -1;
	}
	if(trunc_file()){
		printf("trunc_file() error\n");
		return -1;
	}
	if(append_file()){
		printf("append_file() error\n");
		return -1;
	}

	return 0;
}
