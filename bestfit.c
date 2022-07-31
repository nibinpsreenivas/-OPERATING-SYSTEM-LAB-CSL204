#include<stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int i, j;
    int allocation[n];
 
    
    for(i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
   
    
    for (i = 0; i < n; i++)       
    {
        for (j = 0; j < m; j++)        
        {
            if (blockSize[j] >= processSize[i])
            {
               
                allocation[i] = j;
 
               
                blockSize[j] -= processSize[i];
 
                break;  
            }
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i+1);
        printf("%i\t\t\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}
 
void worstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    
    int allocation[processes];
    int j;
   
    for(int i = 0; i < processes; i++)
    {
        allocation[i] = -1;
    }
    
 
    
    for (int i=0; i < processes; i++)
    {
	
	
	   int lar=blockSize[0];
	   int index=-1;
	    for(j=0;j<blocks;j++)
            {
            
              if(blockSize[j]>=processSize[i])
              {
              if(blockSize[j]>=lar)
               {
                 lar=blockSize[j];
                 index=j;
                }
                }
             }        
                
              if(index !=-1)
               {
                   allocation[i]=index;
                  blockSize[index] -= processSize[i];
               }
            }
         
    

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void bestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
    
    int allocation[proccesses];
    int j;
    
   
    for(int i = 0; i < proccesses; i++){
        allocation[i] = -1;
    }
    
   
 
    
     for (int i=0; i < proccesses; i++)
    {
	
	
	   int lar;
	   for(j=0;j<blocks;j++)
	    {
	      if(blockSize[j]>=processSize[i])
	       {
	          lar=blockSize[j];
	          break;
	          
	        }
	      }
	        
	   int index=-1;
	    for(j=0;j<blocks;j++)
            {
            
              if(blockSize[j]>=processSize[i])
              {
              if(blockSize[j]<=lar)
               {
                 lar=blockSize[j];
                 index=j;
                }
                }
             }        
                
              if(index !=-1)
               {
                   allocation[i]=index;
                  blockSize[index] -= processSize[i];
               }
            }
         
    
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < proccesses; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
 


int main()
{
    int blockSize[20];
    int processSize[20];
    int m,n;
    printf("how many block size");
    scanf("%d",&m);
    printf("how many process size");
    scanf("%d",&n);
    printf("enter the block ");
    for(int i=0;i<m;i++)
       scanf("%d",&blockSize[i]);
     printf("enter the process process");
   for(int i=0;i<n;i++)
     scanf("%d",&processSize[i]);
   
      int o, i;
    printf("\n1. Press 1 best fit\n2. Press 2 worst fit\n3. Press 3 firstfit");
 do {
 
        printf("\nEnter your choice:");
        scanf("%d", &o);
 
        
        switch (o) {
        case 1:bestFit(blockSize, m, processSize, n);
 
              break;
 
        case 2:worstFit(blockSize, m, processSize, n);
 
              break;
 
        case 3:firstFit(blockSize, m, processSize, n);
              break;
             
        
        }
    }while(o!=4);
   
    
    
    
  
    return 0 ;
}
