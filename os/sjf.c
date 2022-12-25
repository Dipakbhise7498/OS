 #include<stdio.h>
void main()
{
    int n, bt[20], at[20],p[20],wt[20],tat[20],i,j , total=0, pos, temp;
    
    float avgwt=0, avgtat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
   
    printf("Enter burst time of each process: \n");
    for(i=0;i<n;i++)
    {
        p[i]=i;
        printf("Burst Time of P[%d]: ",i);
        scanf("%d",&bt[i]);
        at[i]=0; 
        
    }
    
    for(i=0;i<n;i++)
    {
        pos = i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
            {
                pos=j;
            }
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
   

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    
    wt[0]=0; 
   
    for(i=1;i<n;i++)    
    {
        wt[i]=0;  
        for(j=0;j<i;j++)
        {
            wt[i] = wt[i] + bt[j];
        }
    }
        
    for(i=0;i<n;i++)
    {
        tat[i] = wt[i] + bt[i];   
    }
   
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
