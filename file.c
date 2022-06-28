//File open
//

#include <stdio.h>
#include <string.h>

int write_to_file(void){
	FILE *fp;
	fp = fopen("hyeonuk","w");
	if (fp == NULL){
		perror("fopen error\n");
		return -1;
	}
	fputs("hello world..", fp);
	fclose(fp);
	return 0;
}

int read_from_file(void){
	FILE *fp;
	char buf[1024];
	fp = fopen("hyeonuk","r");
	if (fp == NULL){
		perror("fopen error\n");
		return -1;
	}
	memset(buf, 0, sizeof(buf));
	fgets(buf, sizeof(buf), fp);
	fclose(fp);
	printf("%s\n", buf);
	return 0;
}

int main(){
	write_to_file();
	read_from_file();
	return 0;
}
