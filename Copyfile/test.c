#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
main()
{
    DIR * dir;
    struct dirent * ptr;
    int i;
    dir = opendir("/home/coco");
    while((ptr = readdir(dir)) != NULL)
    {
        printf("d_name : %s\n", ptr->d_name);
    }
    closedir(dir);
}
