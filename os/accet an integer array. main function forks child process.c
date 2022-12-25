#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
 pid_t pid;
 pid=fork();
 char *args[]={"./ass1_1",NULL};
 if(pid==0)
 execv(args[0],args); 
 else
printf("\nI am parent\n");
return 0;
}