#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFSIZE  131072

int simpleCopyFile(char* inputFilePath,char* outputFilePath)
{
	int n;
	int fileHandSrc,fileHandDst;
	char buf[BUFFSIZE];
	if(ga.preserve == true)
	{
		
	}
	fileHandSrc = open(inputFilePath,O_RDONLY);
	if((fileHandDst = open(outputFilePath,O_WRONLY|O_CREAT, 0775)) < 0)
	{
		perror("open dest file error");
		exit(EXIT_FAILURE);
	}
        while((n = read(fileHandSrc,buf,BUFFSIZE)) > 0)
		if (write(fileHandDst,buf,n) != n)
			perror("write error");
  	if(n < 0)
	{
		perror("read error");
		exit(EXIT_FAILURE);
	}		
        return 1;
}

