#include<stdio.h>

int lru(int time[10],int nf)
{
    int min = time[0];
    int position=0;
    for(int i=1;i<nf;i++)
    {
        if(time[i]<min)
        {
           min = time[i];
           position=i;
        }
    }
      return position;
}
int main()
{
    int i,j,n,ref_str[50],frame[10],no,k,avail,fcount=0,time[10],count=0,flag1=0,flag2=0;  
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d",&n);                                        
    printf("\n ENTER THE PAGE NUMBER :\n");
        for(i=1;i<=n;i++)                                  
            scanf("%d",&ref_str[i]);
    printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d",&no);
        for(i=0;i<no;i++)
                    frame[i]= -1;  
    j=0;                           
    printf("\n ref string  \t page frames     \tHit/Fault\n");
        for(i=1;i<=n;i++)
        {
            
            printf("%d\n",ref_str[i]);
            flag1=flag2=0;         
            for(k=0;k<no;k++)
            if(frame[k]==ref_str[i]) 
            {
                          
                   
                    count++;
                    time[k]=count;
                    flag1=flag2=1;
                    printf("\t");
                     for(k=0;k<no;k++)
                            printf("%d\t",frame[k]);   
                    printf("H"); 
                    printf("\n");
                    break;
            }
           
            if(flag1==0)
            {
                  for(k=0;k<no;k++)
                  {
                      if (frame[k]==-1)
                      {
                        
                       
                          count++;
                          fcount++;
                          frame[k] = ref_str[i];
                          time[k] = count;
                          flag2 = 1;
                            printf("\t");
                     for(k=0;k<no;k++)
                            printf("%d\t",frame[k]);   
                    printf("PF"); 
                    printf("\n"); 
                          break;
                      }
                  }
            }
            if(flag2==0)
            {
                int loc = lru(time,no);
                count++;
                fcount++;
                frame[loc] = ref_str[i];
                time[loc] = count;
                  printf("\t");
                     for(k=0;k<no;k++)
                            printf("%d\t",frame[k]);   
                    printf("PF"); 
                    printf("\n");
                
            }
        }
    printf("Page Fault Is %d",fcount);
   
    
                            
    
    return 0;
}

