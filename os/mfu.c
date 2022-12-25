#include<stdio.h>

struct node
{
  int pno,freq;
}frames[20];
int n;

int page_found(int pno)
{
  int fno;
  for(fno=0;fno<n;fno++)
    if(frames[fno].pno==pno)
       return fno;
    return -1;
}

int get_free_frame()
{  int fno;
  for (fno=0; fno<=n; fno++)
    if (frames[fno].pno==-1)
        return(fno);
   return(-1);
}

int get_mfu_frame()
{
  int fno;
  int selfno=0;
  for (fno=1; fno<n; fno++)
    if(frames[fno].freq>frames[selfno].freq)
    selfno=fno;
  return selfno;
}
void main()
{
   int p_request[]={5,8,10,14,10,9,5,10,8,5,1,10,9,12,10};
   int size=15;
   int page_falts=0,i,j,fno;
   clrscr();
   printf("\nHow many frames:");  scanf("%d",&n);
   //initialize frames
   for (i=0; i<n; i++)
   { frames[i].pno=-1;
     frames[i].freq=0;
   }

   printf("\nPageNo     Page Frames              Page Fault");
   printf("\n---------------------------------------------------");
   for(i=0;i<size;i++)
   {
     j=page_found(p_request[i]);
     if(j==-1)  //page fault occurs
     {
       j=get_free_frame();
       if (j==-1) //no free frame - do page replacement
         j=get_mfu_frame();
       page_falts++;
       frames[j].pno=p_request[i];
       frames[j].freq=1;
       printf("\n%4d\t ",p_request[i]);
       for (fno=0; fno<n; fno++)
         printf("%4d:%2d",frames[fno].pno,frames[fno].freq);
       printf(" : YES");
     }
    else //page found in frame j
    {
       printf("\n%4d\t ",p_request[i]);
       frames[j].freq++;
       for (fno=0; fno<n; fno++)
         printf("%4d:%2d",frames[fno].pno,frames[fno].freq);
       printf(" : NO");
    }
   }
  printf("\n-------------------------------------------------------");
  printf("\n Number of Page_Falts=%d",page_falts);
  getch();
}
