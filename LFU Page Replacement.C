#include<stdio.h>
int LFU(int frequent[], int n)
{
	int min=20,pos,i;
	for(i=0;i<n;i++)
	{
		if(frequent[i]<min)
		{
			min=frequent[i];
			pos=i;
		}
	}
	return pos;
}
int main()
{
	int refstring[10], no_of_frames, no_of_pages, flag1, flag2, frames[20],i,j,counter=0,pos,faults=0,fault[10],frequent[10],time[10];
	printf("Enter the number of pages");
	scanf("%d",&no_of_pages);
	printf("Enter the frame size:\n");
	scanf("%d",&no_of_frames);
	printf("Enter the reference string");
	printf("\n");
	for(i=0;i<no_of_pages;i++)
	{
		scanf("%d",&refstring[i]);
	}
	for(i=0;i<no_of_frames;i++)
	{
		frames[i]=-1;
	}
	for(i=0;i<no_of_frames;i++)
	{
		frequent[i]=0;
	}
	for(i=0;i<no_of_pages;i++)
	{
		flag1=0;
		flag2=0;
		for(j=0;j<no_of_frames;j++)
		{
			if(frames[j]==refstring[i])
			{
				counter++;
				frequent[j]=frequent[j]+1;
				time[j]=counter;
				flag1=1;
				flag2=1;
			}
		
			if(flag1==0)
			{
				if(frames[i]==-1)
				{
					frames[j]=refstring[i];
					counter++;
					
					printf("The page fault occured at page:%d\n",refstring[i]);
					faults++;
					time[j]=counter;
					flag2=1;
				}
			}
			if(flag2==0)
			{
				printf("The page fault occured at page:%d\n",refstring[i]);
				
				pos=LFU(frequent,no_of_frames);
				printf("The page replaced is :%d\n",frames[pos]);
				frames[pos]=refstring[i];
				counter++;
				printf("The page fault occured at page:%d\n",refstring[i]);
				faults++;
				time[j]=counter;
				
				flag2=1;
			}
		}
	}	
	printf("The no of faults:%d",faults);
	return 0;
}
			
			
																					
			


	
	
