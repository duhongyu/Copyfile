#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "CopyFile.h"
#define BUFFSIZE  131072
extern globalArgs ga;
int simple_copyfile(char* input_file_path,char* output_file_path)
{
	int n;
	int filehand_src,filehand_dst;
	char buf[BUFFSIZE];
	if(ga.need_preserve == true)
	{
		
	}
	filehand_src = open(input_file_path,O_RDONLY);
	if((filehand_dst = open(output_file_path,O_WRONLY|O_CREAT, 0775)) < 0)
	{
		perror("open dest file error");
		exit(EXIT_FAILURE);
	}
        while((n = read(filehand_src,buf,BUFFSIZE)) > 0)
		if (write(filehand_dst,buf,n) != n)
			perror("write error");
  	if(n < 0)
	{
		perror("read error");
		exit(EXIT_FAILURE);
	}		
        return 1;
}

