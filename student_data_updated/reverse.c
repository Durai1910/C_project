#include<stdio.h>
#include<string.h>
#include"header.h"
#include<stdlib.h>

extern ST*hptr;
void reverse()
{
	ST*ptr=hptr;
	if(ptr==0)
	{
		printf("\n\tThe is Empty...\n");
		return;
	}
	while((ptr->next)!=0)
	{
		ptr=ptr->next;
	}
	printf("\n\tReverse the list...\n");
	do
	{
		printf("\n\t%d\t%s\t%f\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->prev;
	}while(ptr!=0);

	/*for(i=0,j=size-1;i<j;i++,j--)
	{
		memcpy(&temp.roll,&ptr->roll,k);
		memcpy(&ptr->roll,&last->roll,k);
		memcpy(&last->roll,&temp.roll,k);
		ptr=ptr->next;
		last=last->prev;
	}*/
	printf("\n\tReversing the list completed successfully...\n");
}

