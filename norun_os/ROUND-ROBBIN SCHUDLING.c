//ROUND-ROBBIN SCHUDLING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
float avg_wait_time(int wt[], int n)
{
float x = 0;
int i,sum=0;
for(i=0;i<n;i++)
sum = sum + wt[i];
x = sum * 1.0;
x = x / n;
return x;
}
float avg_turnaround_time(int tat[], int n)
{
float x = 0;
int i,sum = 0;
for(i=0;i<n;i++)
sum = sum + tat[i];
x = sum * 1.0;
x = x / n;
return x;
}
void fill_gantt(int gantt[],int from,int to,int process)
{
int i;
for(i=from;i<=to;i++)
gantt[i] = process;
}
void rearrange_process_queue(int pq[],int n,int running_processes)
{
int i;
int temp = pq[0];
for(i=p;i<running_processes;i++)
{
pq[i] = pq[i+1];
}
}
int main()
{
int count,i,j;
int time_quantum,n;
int time = 0;
int t-check =0;
FILE *fp;
printf("\t-----------------------------------\n");
printf("\t\tROUND ROBIN SCHEDULING ALGORITHM\n");
printf("\t-------------------------------------------\n");
fp = fopen("data.txt", "r");
if (fp == NULL)
{
printf("File could not be accessed!\n");
return 0;
}
fscanf(fp, "%d\n%d" ,&n&time_quantum);
if(n<= 0 || time_quantum <= 0)
{
printf("Invalid data!");
return 0;
}
printf("the number of processes ar set to: %d\nThe time quantum is set to:%d\n" , n,time_quantum);
int at[10],bt[10],rt[10],pq[10],pflag[10],tat[10],wt[10];
for(j=0;j<n;j++)
{
pq[j] = 0;
pflag[j] = 0;
}
printf("The scanned process data is:\n\n");
printf("\t-----------------------------------\n");
printf("|\tINDEX\tAT\t|\tBT\t|\n");
for(count=0;count<n;count++)
{
fscanf(fp,"%d\t%d",&at[count],&bt[count]);
printf("|\t%d\t|\t%d\t|\n",count+1,at[count],bt[count]);
rt[count]=bt[count];
t+check +=bt[count];
if(at[count] < 0 || bt[count] <= 0)
{
printf("Invalid Data!");
return 0;
}
}
}
printf("\t-----------------------------------\n");
int gantt[200];
for(i=0;i<200;i++)
gantt[i] = 0;
int current = 0;
printf("\nThe order of execution:\n\n");
int running_processes = 0;
pq[0] = 1;
running_processes = 1;
pflag[0] = 1;
int flag = 0;
while(running_processes!=0)
{
flag = 0;
printf("process queue: ");
for(i=0;i<running_processes;i++)
printf("%d ",pq[i]);
printf("\t");
printf("Remaining Time: ");
for(i=0;i<n;i++)
printf("%d ",rg[i]);
printf("\tRunnning processes: %d\n",running_processes);
if(rt[pq[0]-1]>time_quantum)
{
rt[pq[0]-1] = rt[pq[0]-1] - time_quantum;
time = time + time_quantum;
printf("Process %d executed for %d bursts till time%d\n",pq[0],time_quantum,time);
fill_gantt(gantt,current,time,pq[0]);
}
else
{
time time + rt[pq[0]-1];
printf("Process %d executed for %d bursts till time%d\n,pq[0],rt[pq[0]-1],time);
rt[pq[0]-1] = 0;
flag = 1;
fill_gantt(gantt,current,time,pq[0]);
current = time;
tat[pq[0]-1] = time - at[pq[0]-1];
wt[pq[0]-1 = tat[pq[0]-1] - b[pq[0]-1];
}
for(i=0;i<n;i++)
{
if at[i] <= time && pflag[i] == 0)
{
pq[running_processess] = i+1;
running_processes = running_processes + 1;
}
}
rearrange_process-queue(pq,n,running_processes);
if(flag == 1)
running_processes = running_processes - 1;
}
printf("\n\nExecution Data:\n");
printf("\t----------------------------------------------\n");
printf("|\tProcess\t|\tAT\t|\tBT\t|\tWT\t|\n");
for(i=0;i<n;i++)
{
printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",i+1,at[i],bt[i],tat[i],wt[i]);
}
printf("\t----------------------------------------------\n");
printf("\n\nAverage Waiting time= %f\n",avg_wait-time(wt,n));
printf("Average Turnaround Time = %f\n",avg_turnaround_time(tat,n);
return 0;
}
