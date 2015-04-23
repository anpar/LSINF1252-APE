#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
 
int main()
{
    int filedesc = open("testfile.txt", O_WRONLY | O_APPEND);
    if(filedesc < 0)
        return 1;
	 
    if(write(filedesc,"This will be output to testfile.txt\n", 36) != 36)
    {
        write(2,"There was an error writing to testfile.txt\n",43);
        return 1;
    }

    printf("return value of open(): %d.\n", filedesc);
    
    filedesc = open("testfile2.txt", O_WRONLY | O_APPEND);
    if(filedesc < 0)
        return 1;
            
    if(write(filedesc,"This will be output to testfile.txt\n", 36) != 36)
    {
        write(2,"There was an error writing to testfile.txt\n",43);
        return 1;
    }

    printf("return value of open(): %d.\n", filedesc);

    return 0;
}
