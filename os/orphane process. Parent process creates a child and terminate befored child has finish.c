#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
int main()
{ 
int pid;
pid=getpid(); 
printf("Current Process ID is : %d\n",pid); 
printf("\n[Forking Child Process ... ] \n"); 
pid=fork(); 
if(pid < 0) 
{ 
 printf("\nProcess can not be created ");
} 
else
{
 if(pid==0)
 { 
 printf("\nChild Process is Sleeping ..."); 
 sleep(5); 
 printf("\nOrphan Child's Parent ID : %d",getppid()); 
 }
 else
 { /* Parent Process */
 printf("\nParent Process Completed ..."); 
 } 
}
return 0; 
}
