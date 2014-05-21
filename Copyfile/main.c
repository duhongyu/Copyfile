#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<getopt.h>

typedef struct globalArgs {
        int archive;                       /*-a option*/
        int backup;                        /*-b option*/
        int no_derence;                    /*-d option*/
     	int force;                         /*-f option*/
  	int interactive;                   /*-i option*/
      	int link;                          /*-l option*/
 	int dereference;                   /*-L option*/
	int no_clobber;                    /*-n option*/
	int no_dereference;                /*-P option*/
        int preserve;                      /*-p option*/
        int recursive;                     /*-r or R option*/
        int symbolic_link;                  /*-s option*/
	int numOfFiles;
	char* inputFile;
        char* outputFile;                
                
} globalArgs;
globalArgs ga;
static const char *optString = "rR";
int simpleCopyFile(char* inputFilePath,char* outputFilePath);
void recursiveMethod(char* input,char* output);

/* xianshi yongfa bingqie tuichu.
 */
void display_usage( void )
{
	puts( "the useage is: cp [OPTION]... [-T] SOURCE DEST\
             cp [OPTION]... SOURCE... DIRECTORY\
       cp [OPTION]... -t DIRECTORY SOURCE..." );
	exit( EXIT_FAILURE );
}

void arguActionExcute()
{
	int i;
	if(1 == ga.recursive)
	{
		recursiveMethod(ga.inputFile,ga.outputFile);
	}else{
		simpleCopyFile(ga.inputFile,ga.outputFile);
	}
}

int main( int argc, char *argv[] )
{
	int opt = 0;
	ga.recursive = 0;		/* false */
	char* optString = "rR";
	opt = getopt( argc, argv, optString );
	while( opt != -1 ) {
		switch( opt ) {
			case 'r':
				ga.recursive = 1;    /* true */
				break;
			case 'R':
				ga.recursive = 1;    /* true */
				break;


		}
		
		opt = getopt( argc, argv, optString );
	}
	ga.numOfFiles = argc - optind;
	ga.outputFile = argv[argc-1];
        for(int i = optind; i < argc-1 ; i++)
	{
		ga.inputFile = argv[optind];
  		arguActionExcute(ga.inputFile);
	}
        
	
	exit(EXIT_SUCCESS);
}