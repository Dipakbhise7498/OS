

#include<stdio.h>
int turnarroundtime(int p[], int n,
int bt[], int wt[], int tat[])
 {
    int i;
   for (i = 0; i < n ; i++)
   tat[i] = bt[i] + wt[i];
   return 1;
}
int waitingtime(int p[], int n,
int bt[], int wt[], int quantum) 
{
   int rem_bt[n];  
   for (int i = 0 ; i < n ; i++)
   rem_bt[i] = bt[i];
   int t = 0; 
  
   while (1) {
      int finished = 1;
      for (int i = 0 ; i < n; i++) 
      {
 
         if (rem_bt[i] > 0)  
         {   
            finished = 0;  
            if (rem_bt[i] > quantum) { 
               t = t+quantum;  
               rem_bt[i] = rem_bt[i] - quantum; 
            }
            else     
            {
               t = t + rem_bt[i];    
               wt[i] = t - bt[i];      
               rem_bt[i] = 0;   
            }
         }
      }
     
      if (finished == 1)
       {  break; }
   }
   return 1;
}
void main()
{
    int n, bt[20], at[20],p[20],wt[20],tat[20] ,i, total=0, time_quantum; 
    int x;
    float avgwt=0, avgtat=0;
    
  
    printf("Enter number of processes: ");
    scanf("%d",&n);
    
  
    printf("Enter the Burst time value of each process: \n");
    for(i=0;i<n;i++)
    {
        p[i]=i;
        at[i]=0;
        printf("Burst Time of P[%d]: ",i);
        scanf("%d",&bt[i]);
    }
    
 
    printf("Enter the Time Quantum: ");
    scanf("%d",&time_quantum);
    

    waitingtime(p, n, bt, wt, time_quantum);
    turnarroundtime(p, n, bt, wt, tat);
    
   
    printf("\n\tPID\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    }
    
    for(i=0;i<n;i++)
    {
        avgwt = avgwt + wt[i];
        avgtat = avgtat + tat[i];
    }
    avgwt = avgwt/n;
    avgtat = avgtat/n;
    
    printf("\nAverage WT = %f\n", avgwt);
    printf("\nAverage TAT = %f\n", avgtat);
}
// tat= completiontime- arrivaltime
// wt= tat+bt

