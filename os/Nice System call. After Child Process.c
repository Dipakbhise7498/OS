#include <stdio.h>
void main()
{
int pid,i;
 printf("Enter CTR+Z to stop...\n");
 pid=fork();
 for(i=0;i<3;i++)
 {
if(pid==0)
 {
 printf("Child gets higher priority %d\n",nice(-5));
 sleep(1);
 }
else
{
 printf("Parent gets lower priority %d\n",nice(4));
 sleep(1);
 }
 }
}