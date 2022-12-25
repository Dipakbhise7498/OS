int main()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
int p, r, i, j, process, count;
count = 0;
 
printf("Enter the no of processes : ");
scanf("%d", &amp;p);
 
for(i = 0; i&lt; p; i++)
completed[i] = 0;
 
printf("\n\nEnter the no of resources : ");
scanf("%d", &amp;r);
 
printf("\n\nEnter the Max Matrix for each process : ");
for(i = 0; i &lt; p; i++)
{
printf("\nFor process %d : ", i + 1);
for(j = 0; j &lt; r; j++)
scanf("%d", &amp;Max[i][j]);
}
 
printf("\n\nEnter the allocation for each process : ");
for(i = 0; i &lt; p; i++)
{
printf("\nFor process %d : ",i + 1);
for(j = 0; j &lt; r; j++)
scanf("%d", &amp;alloc[i][j]);
}
 
printf("\n\nEnter the Available Resources : ");
for(i = 0; i &lt; r; i++)
scanf("%d", &amp;avail[i]);
 
for(i = 0; i &lt; p; i++)
for(j = 0; j &lt; r; j++)
need[i][j] = Max[i][j] - alloc[i][j];
 
do
{
printf("\n Max matrix:\tAllocation matrix:\n");
for(i = 0; i &lt; p; i++)
{
for( j = 0; j &lt; r; j++)
printf("%d ", Max[i][j]);
printf("\t\t");
for( j = 0; j &lt; r; j++)
printf("%d ", alloc[i][j]);
printf("\n");
}
 
process = -1;
 
for(i = 0; i &lt; p; i++)
{
if(completed[i] == 0)//if not completed
{
process = i ;
for(j = 0; j &lt; r; j++)
{
if(avail[j] &lt; need[i][j])
{
process = -1;
break;
}
}
}
if(process != -1)
break;
}
 
if(process != -1)
{
printf("\nProcess %d runs to completion!", process + 1);
safeSequence[count] = process + 1;
count++;
for(j = 0; j &lt; r; j++)
{
avail[j] += alloc[process][j];
alloc[process][j] = 0;
Max[process][j] = 0;
completed[process] = 1;
}
}
}while(count != p &amp;&amp; process != -1);
 
if(count == p)
{
printf("\nThe system is in a safe state!!\n");
printf("Safe Sequence : &lt; ");
for( i = 0; i &lt; p; i++)
printf("%d ", safeSequence[i]);
printf("&gt;\n");
}
else
printf("\nThe system is in an unsafe state!!");
getch();
}
