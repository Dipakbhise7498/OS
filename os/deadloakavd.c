#include<stdio.h>
#include<stdlib.h>
int main()
{
	int max[10][10],need[10][10],alloc[10][10],avail[10][10], completed[10], safeSequence[10];
	int p, r, i, j, process, count;
	count = 0;
	printf("Enter the No. of Processes : ");
	scanf("%d", &p);
	for(i = 0; i<p; i++)
		completed[i] = 0;
	printf("\n\nEnter the No. of Resources: ");
	scanf("%d", &r);
	printf("\n\nEnter the Max. matrix for each Process : ");
	for(i = 0; i<p; i++)
	{
		printf("\nFor Process %d : ", i + 1);
		for(j = 0; j<r; j++)
			scanf("%d", &max[i][j]);
	}
	printf("\n\nEnter the Allocation for each process: ");
	for(i = 0; i < p; i++)
	{
		printf("\nFor Process %d : ",i+1);
		for(j = 0; j<r; j++)
		scanf("%d", &alloc[i][j]);
	}
	printf("\n\nEnter the Available Resources : ");
	for(i = 0; i < r; i++)
		scanf("%d", &avail[i][j]);

	for(i=0; i<p; i++)
		for(j=0; j<r; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	do
	{
		printf("\n Max Matrix:\tAllocation Matrix:\t Need matrix\n");
		for(i=0; i<p; i++)
		{
			for(j=0; j<r; j++)
				printf("%d ", max[i][j]);
			printf("\t\t");
			for(j=0; j<r; j++)
				printf("%d ", alloc[i][j]);
			
			printf("\t\t");
			for(j=0; j<r; j++)
				printf("%d ", need[i][j]);
				printf("\n");
		}
		process = -1;
		
		for(i=0; i<p; i++)
		{
			if(completed[i] == 0)
			{
				process = i;
				for(j=0; j<r; j++)
				{
					process = -1;
					break;
				}
			}
		}
		if(process != -1)
		{
			printf("\nProcess %d runs to Completion!", process +1);
			safeSequence[count] = process + 1;
			count++;
			for(j=0; j<r; j++)
			{
				avail[i][j] += alloc[process][j];
				alloc[process][j] = 0;
				max[process][j] = 0;
				completed[process] = 1;
			}
		}
	}
	while(count != p && process != -1);
	if(count == p)
	{
		printf("\nthe Sytem is in a Safe State!!\n\n");
		printf("Safe Sequence: < ");
		for(i=0; i<p; i++)
			printf("%d ", safeSequence[i]);
		printf(">\n");
	}
	else
	printf("\nThe System is in an Unsafe State!\n\n");
}

