#include<stdio.h>
#include "header.h"
extern struct st *hptr;
void display()
{
	struct st*temp=hptr;
	if(temp==0)
	{
		printf("\t\tThe student record is empty...\n");
	}
	else
	{
		printf("\t\tdisplay the record...\n");

		while(temp!=0)
		{
			printf("\t\t %d \t %s \t %f \n",temp->roll,temp->name,temp->mark);
			temp=temp->next;
		}
	}
}



