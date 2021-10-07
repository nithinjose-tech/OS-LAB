#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct process
{
  int id,at,bt,pt;
  int wt,tat,ct;
}temp;
void calc(struct process * startOfArray,int len)
{
  float averagetat=0;
  float averagewt=0;  
  struct process *sjf,*final;
  sjf=(struct process*)malloc(sizeof(struct process)*len);
  final=(struct process*)malloc(sizeof(struct process)*len);
  //make a new sorted array based on burst time
  for(int i=0;i<len;i++)
  {
    sjf[i]=startOfArray[i];
  }
  for(int i=0;i<len;i++)
  {
    for(int j=0;j<len-i-1;j++)
    {
      if(sjf[j].pt>sjf[j+1].pt)
      {
        temp=sjf[j+1];
        sjf[j+1]=sjf[j];
        sjf[j]=temp;
      }
    }
  }
  printf("Sorted based on Burst Time\n");
  printf("Processes     AT     BT  PT\n");
  for(int i=0;i<len;i++)
  {
  printf("%d   %d     %d   %d\n",sjf[i].id,sjf[i].at,sjf[i].bt,sjf[i].pt);
  }
  printf("=====================\n");
  int timer=0;
  int value=0;
  int k=0;
  int i=0;
  while(i<len)
  {
    int flag=0;
    int j=0;
    if(startOfArray[i].at<=timer)
    {
        while(j<len)
        {
          if(sjf[j].ct==0&&startOfArray[i].pt>=sjf[j].pt&&sjf[j].at<=timer)
          {
		sjf[j].ct=1;
		final[k].id=sjf[j].id;
		final[k].at=sjf[j].at;
		final[k].bt=sjf[j].bt;
		if(k==0)
		 final[k].ct=sjf[j].bt+sjf[j].at;
		else
		 final[k].ct=sjf[j].bt+final[k-1].ct;
		final[k].tat=final[k].ct-sjf[j].at+value;
		final[k].wt=final[k].tat-sjf[j].bt;
		timer+=sjf[j].bt;
		k++;
          }
          j++;
        }
    i++; 
   }
   else
   {
     timer++;
     value++;
   }
  }
  printf("====================================\n");
  printf("PROCESS   AT      BT     TAT      WT\n");
  for(int i=0;i<len;i++)
  {
    averagetat+=final[i].tat;
    averagewt+=final[i].wt;    
    printf("%d       %d       %d      %d      %d\n",final[i].id,final[i].at,final[i].bt,final[i].tat,final[i].wt);
  }
  printf("====================================\n");
  printf("Average Turn Around Time = %f\n",averagetat/len);
  printf("Average Waiting Time = %f\n",averagewt/len);
  
  
  
}
int main()
{
  int n;
  printf("enter number of operations : ");
  scanf("%d",&n);
  struct process * start;
  start=(struct process*)malloc(sizeof(struct process)*n);
  for(int i=0;i<n;i++)
  {
    start[i].ct=0;
    printf("enter process name , arrival time,burst time and priority : ");
    scanf("%d %d %d %d",&start[i].id,&start[i].at,&start[i].bt,&start[i].pt);
  }
  printf("Sorted based on Arrival Time\n");
  printf("Processes     AT     BT  PT\n");
  for(int i=0;i<n;i++)
  {
  printf("%d   %d     %d   %d\n",start[i].id,start[i].at,start[i].bt,start[i].pt);
  }
  printf("=====================\n");
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(start[j].at>start[j+1].at)
      {
        temp=start[j+1];
        start[j+1]=start[j];
        start[j]=temp;
      }
    }
  }
  calc(start,n);
  return 0;
}
