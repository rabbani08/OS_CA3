#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,temp;
    char p[10][10],t[10];
    int beg[10],end[10];
    int burst_time[20],arrival_time[10],wait_time[10],turnaround_time[10];
    int sum_wait_time=0,sum_turnaround_time=0;
    float avg_wait_time,avg_turnaround_time;
    
    
    printf("Enter the number of processes:");
    scanf("%d",&n);
    
    for(i=0; i<n; i++)
    {
        printf("Enter The Process Number, Arrival time and Burst time:");
        scanf("%s%d%d",p[i],&arrival_time[i],&burst_time[i]);
    }
    
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(burst_time[i]<burst_time[j])
            {
                temp=arrival_time[i];
                arrival_time[i]=arrival_time[j];
                arrival_time[j]=temp;
                temp=burst_time[i];
                burst_time[i]=burst_time[j];
                burst_time[j]=temp;
                strcpy(t,p[i]);
                strcpy(p[i],p[j]);
                strcpy(p[j],t);
            }
        }
        
    for(i=0; i<n; i++)
    {
        if(i==0)
            beg[i]=arrival_time[i];
        else
            beg[i]=end[i-1];
        	end[i]=beg[i]+burst_time[i];
			wait_time[i]=beg[i]-arrival_time[i];
        	turnaround_time[i]=end[i]-arrival_time[i];
        	sum_wait_time+=wait_time[i];
        	sum_turnaround_time+=turnaround_time[i];
    }
    
    avg_wait_time=(float)sum_wait_time/n;
    avg_turnaround_time=(float)sum_turnaround_time/n;
    
    printf("\nProcess\tArrival_Time\tBurst_Time\tWait_Time\tTurnaround_Time");
    
	for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",p[i],arrival_time[i],burst_time[i],wait_time[i],turnaround_time[i]);
   		printf("\n The average waiting time is:%f",avg_wait_time);
    	printf("\n The average turnaroundtime is:%f",avg_turnaround_time);
}
