#include<stdio.h>
#include <stdlib.h>
int findLRU(int time[], int n)
{
int i, minimum = time[0], pos = 0;
 
 for(i = 1; i < n; ++i)
 {
   if(time[i] < minimum)
    {
         minimum = time[i];
         pos = i;
    }
  }
 return pos;
}


int lru()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    printf("Enter reference string: ");
        for(i = 0; i < no_of_pages; ++i)
         {
             scanf("%d", &pages[i]);
         }
    
        for(i = 0; i < no_of_frames; ++i)
         {
            frames[i] = -1;
         }
    
       for(i = 0; i < no_of_pages; ++i)
       {
          flag1 = flag2 = 0;
    
          for(j = 0; j < no_of_frames; ++j)
          {
               if(frames[j] == pages[i])
                {
                  counter++;
                  time[j] = counter;
                  flag1 = flag2 = 1;
                  break;
                }
          }
    
         if(flag1 == 0)
         {
           for(j = 0; j < no_of_frames; ++j)
           {
              if(frames[j] == -1)
              {
                counter++;
                faults++;
                frames[j] = pages[i];
                time[j] = counter;
                flag2 = 1;
                break;
              }
           }
         }
    
        if(flag2 == 0)
        {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
    
       printf("\n");
    
     for(j = 0; j < no_of_frames; ++j){
     printf("%d\t", frames[j]);
     }
}
printf("\n\nTotal Page Faults = %d", faults);
    
    return 0;
}
int fifo()
{
    int incomingStream[20];
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;
    printf("\nEnter the number of Pages:\t");
    scanf("%d", &pages);
    printf("\nEnter reference string values:\n");
     for( m = 0; m < pages; m++)
     {
        printf("Value No. [%d]:\t", m + 1);
        scanf("%d", &incomingStream[m]);
     }
    printf("\n What are the total number of frames:\t");
    scanf("%d",&frames);
    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3");
    int temp[frames];
    for(m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for(m = 0; m < pages; m++)
    {
        s = 0;

        for(n = 0; n < frames; n++)
        {
            if(incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        
        if((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if(s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
      
        printf("\n");
        printf("%d\t\t\t",incomingStream[m]);
        for(n = 0; n < frames; n++)
        {
            if(temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}

void print(int frameno,int frame[])
{
            int j;
            for(j=0;j<frameno;j++)
            printf("%d\t",frame[j]);
            printf("\n");
}         

int lfu()
{
            int i,j,k,n,page[50],frameno,frame[10],move=0,flag,count=0,count1[10]={0},
                        repindex,leastcount;
            float rate;
            printf("Enter the number of pages\n");
            scanf("%d",&n);
            printf("Enter the page reference numbers\n");
            for(i=0;i<n;i++)
            scanf("%d",&page[i]);
            printf("Enter the number of frames\n");
            scanf("%d",&frameno);
            for(i=0;i<frameno;i++)
            frame[i]=-1;
            printf("Page reference string\tFrames\n");
            for(i=0;i<n;i++)
            {
                        printf("%d\t\t\t",page[i]);
                        flag=0;
                        for(j=0;j<frameno;j++)
                        {
                                    if(page[i]==frame[j])
                                    {
                                                flag=1;
                                                count1[j]++;
                                                printf("No replacement\n");
                                                break;
                                    }
                        }
                        if(flag==0&&count<frameno)
                        {
                                    frame[move]=page[i];
                                    count1[move]=1;
                                    move=(move+1)%frameno;
                                    count++;
                                    print(frameno,frame);
                        }
                        else if(flag==0)
                        {
                                    repindex=0;
                                    leastcount=count1[0];
                                    for(j=1;j<frameno;j++)
                                    {
                                                if(count1[j]<leastcount)
                                                {
                                                            repindex=j;
                                                            leastcount=count1[j];
                                                }
                                    }
                                   
                                    frame[repindex]=page[i];
                                    count1[repindex]=1;
                                    count++;
                                    print(frameno,frame);
                        }
            }
            rate=(float)count/(float)n;
            printf("Number of page faults is %d\n",count);
            printf("Fault rate is %f\n",rate);
            return 0;
}
int main()
{
   
   
    int o, i;
    printf("\n1.fifo\n2.lru\n3.lfu\n4.exit\n");
    do {
 
        printf("\nEnter your choice:");
        scanf("%d", &o);
 
        
        switch (o) {
        case 1:fifo();
 
              break;
 
        case 2:lru();
 
              break;
 
        case 3:lfu();
              break;
        case 4:printf("\nEXTING.........");
               exit(0);
        default: printf("\nyou have enter a wrong option");
             
        
        }
    }while(o!=4);
   
    
    
    
  
    return 0 ;
}
