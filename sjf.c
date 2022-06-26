#include<stdio.h>
void  swap(int *a,int *b)
{
   int temp;
   temp=*a;
   *a=*b;
   *b=temp;
} 
void findWaitingTime(int processes[], int n,int bt[], int wt[])
{
   
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}
   

void findTurnAroundTime( int processes[], int n, 
                  int bt[], int wt[], int tat[])
{
    
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
   

void findavgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
   
  
    findWaitingTime(processes, n, bt, wt);
   
   
    findTurnAroundTime(processes, n, bt, wt, tat);
   
   
    printf("Processes   Burst time   Waiting time   Turn around time \n");
   
 
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("       %d ",processes[i]);
        printf("       %d ", bt[i] );
        printf("             %d",wt[i] );
        printf("       %d\n",tat[i] );
       
    }
    float s=(float)total_wt / (float)n;
    float t=(float)total_tat / (float)n;
    printf("Average waiting time = %f sec",s);
    printf("\n");
    printf("Average turn around time = %f sec ",t);
}
  
void input(int a[],int n)
{
  for(int i=0;i<n;i++)
   scanf("%d",&a[i]);
}

int main()
{

    int processes[10];
    int n;
    int  burst_time[10];
   
    printf("\n ENTER THE NUMBER OF PROCESS");
    scanf("%d",&n);
    printf("\n ENTER THE PROCESS one by one");
    input(processes,n);
    printf("\n ENTER THE Burst time one by one");
    input(burst_time,n);
   
    
   
   for(int i=0;i<n-1;i++)
   {
     int small=burst_time[i];
     int index=i;
     for(int j=i+1;j<n;j++)
      {
        if(small>=burst_time[j])
          {
           small=burst_time[j];
           index=j;    
          }
       }
  
     
     swap(&processes[index],&processes[i]);
     swap(&burst_time[index],&burst_time[i]);
    }
   for(int i=0;i<n;i++)
    {
      printf("\n%d",processes[i]);
    } 
   
   findavgTime(processes, n,  burst_time);
    return 0;
}
