#include <stdio.h>
int i,j,n,bt[20],at[20],wt[20],tt[20],ct[20],p[20],choice,total = 0,sum = 0;
float avg1,avg2;
void sjf()
{
	printf("enter the number of process:");
	scanf("%d",&n);
	printf("\nIs there Arival Time");
	printf("\n 1 = yes , otherwise = no:");
	scanf("%d",&choice);
	printf("\nenter the burst time\n");
	for(i=0;i<n;i++)
	{
		printf("process %d:",i+1);
		scanf("%d",&bt[i]);
		p[i] = i+1;
	}
	if(choice == 1)
	{
		printf("enter the arrival time time\n");
		for(i=0;i<n;i++)
		{
			printf("process %d:",i+1);
			scanf("%d",&at[i]);

			p[i] = i+1;
		}
	}
	if(choice == 1)
		sort(at);
	else
		sort(bt);
	wt[0]=0;
	if(choice != 1)
		for(i=1;i<n;i++)
		{
			wt[i]+=bt[i-1];
			total+=wt[i];
		}
	else
	{
		for(i=1;i<n;i++)
		{
			sum=sum+bt[i-1];
			wt[i]=sum-at[i];
			total+=wt[i];

		}
	}
	avg1 = (float)total/n;
	display();
}
void display()
{
	if(choice ==1)
	{
		total = 0;
		printf("\nProcess\tArival Time\tBurst Time\tWaiting Time Turnaround Time\tCompletion Time");
		for(i=0;i<n;i++)
		{
			tt[i]=bt[i]+wt[i];
			total += tt[i];
			ct[i] = tt[i] + at[i];
			printf("\n p%d\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t%d",p[i],at[i],bt[i],wt[i],tt[i],ct[i]);
		}
	}
	else
	{
		total = 0;

		printf("\nProcess\tBurst Time\tWaiting Time\tTurnaroundTime\tCompletion Time");
		for(i=0;i<n;i++)
		{
			tt[i]=bt[i]+wt[i];
			total += tt[i];
			ct[i] = tt[i];
			printf("\n p%d\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d",p[i],bt[i],wt[i],tt[i],ct[i]);
		}
	}
	avg2 = (float)total/n;
	printf("\naverage waiting time = %f",avg1);
	printf("\naverage turn around time = %f",avg2);
}
void sort(int a[])
{
	int temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j+1]<a[j])
			{

				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				if(choice == 1)
				{
					temp = bt[j];
					bt[j] = bt[j+1];
					bt[j+1] = temp;
				}
			}
		}
	}
}
int main()
{
	sjf();
}
