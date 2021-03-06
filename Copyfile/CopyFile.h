#ifndef COPYFILR_H
#define COPYFILE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#define true 1
#define false 0
#define SUCCESS_LINK -2
#define MAX_PATH_LENGTH 512
#define DEBUG_INFO(s,d)  printf("Debug info:"),printf(s,d)

typedef enum file{
  UNKNOWN = -1,
  ENUM_DIR = 0, 
  ENUM_FILE,
  ENUM_SYMLINK,
  ENUM_BLOCKDEVICE,
  ENUM_CHARDEVICE,
  ENUM_FP,
  ENUM_SOCKET
}file;

typedef struct globalArgs {
        int need_archive;                       /*-a option*/
        int need_backup;                        /*-b option*/
        int need_no_derence;                    /*-d option*/
     	int need_force;                         /*-f option*/
  	int need_interactive;                   /*-i option*/
      	int need_link;                          /*-l option*/
 	int need_dereference;                   /*-L option*/
	int need_no_clobber;                    /*-n option*/
	int need_no_deference;                /*-P option*/
        int need_preserve;                      /*-p option*/
	int preserve_ownership;
 	int preserve_mode;
  	int preserve_timestamps;
	int preserve_links;
        int need_recursive;                     
        int need_symbolic_link;                 
	int num_of_files;
	char* input_file;
        char* output_file;                
                
} globalArgs;

file type_of_file(const char* inputFilePath);
int simple_copy_file(const char* inputFilePath,const char* outputFilePath);
void recursive_method(const char* input,const char* output);
int preserve_method(struct stat info, const char* input_file_path, const char* output_file_path);
void argmatch_valid (char const *const *arglist);
int argmatch (const char *arg, const char *const *arglist);
void argmatch_invalid (const char *context, const char *value);
int argument_match_report (const char *context, const char *arg, const char *const *arglist);
#endif
