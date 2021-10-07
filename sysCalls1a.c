#include <stdio.h>

#include <unistd.h>
int main()
{
int t1=0,t2=1,n,i,j,count=1,flag,nextTerm,k=2;
pid_t temp;
nextTerm=t1+t2;
printf("Enter size n -------");
scanf("%d",&n);
temp=fork();

if(temp==0)
{
printf("(Child)Fibonacci Series:%d,%d,",t1,t2);

for(i=3;i<=n;++i){
printf("%d,",nextTerm);
t1=t2;
t2=nextTerm;
nextTerm=t1+t2;
}

printf("\n");
}
else if(temp>0){
wait(NULL);
printf("(Parent)Prime numbers :");
while(count<=n){
flag=0;

for (j = 2; j <= k / 2; j++)
{
	if (k % j == 0)
	{
		flag = 1;
		break;
	}
}
if (flag == 0)
{
	printf("%d\t", k);
	count++;
}
k++;
}
printf("\n");
}
return 0;
}
