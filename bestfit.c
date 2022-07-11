#include<stdio.h>



#define max 25
int smallest(int file,int b[],int nb,int nf)
{
  int i,j;
int small,index=-1;
   small=b[1];
   
    for(j=2;i<=nb;i++)
    {
       if(b[j]<small)
        {
           small=b[j];
           if(b[j]>=file)
           index=j;

        }  
    }

    
  
 return index;
}
void main()

{

  int frag[max],b[max],f[max],i,j,nb,nf,temp,index[max],s=0,ls,item;
  static int bf[max],ff[max];



printf("\nEnter the number of blocks:");

scanf("%d",&nb);

printf("Enter the number of files:");

scanf("%d",&nf);

printf("\nEnter the size of the blocks:-\n");

for(i=1;i<=nb;i++)

{

printf("Block %d:",i);

scanf("%d",&b[i]);

}

printf("Enter the size of the files:-\n");

for(i=1;i<=nf;i++)

{

printf("File %d:",i);

scanf("%d",&f[i]);

}

for(i=1;i<=nf;i++)

{
    item=f[i];
  ls =smallest(item,b,nb,nf);
   printf("\nvalue of ls is %d",ls);
   if(ls>=0)
   {
      temp=b[ls]-f[i];
      b[ls]=temp;
    if(temp>=0)
     {
      
      ff[i]=j;

      break;

    }
   }
else
{
index[s]=i;
  s=s+1;
}
frag[i]=temp;



}

printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment");

for(i=1;i<=nf;i++)
{
if(ff[i]<=nb||ff[i]<=nf)
{
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
}
}

for(i=0;i<s;i++)
{
 printf("\nfile %d does not alloceted",index[i]);
}
}
