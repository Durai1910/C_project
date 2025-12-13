#include<stdio.h>
#include "header.h"
#include<string.h>
#include<stdlib.h>

void roll_no(void);
extern struct st *hptr;
void remove_node()
{
	char op;
	int count=0;
	printf("\n");
	printf("\t*         Choose one to search...          *\n");
	printf("\t*------------------------------------------*\n");
	printf("\t|   R/r   |   Remove by Roll_no...         |\n");
	printf("\t|---------|--------------------------------|\n");
	printf("\t|   N/n   |   Remove by Name...            |\n");
	printf("\t*------------------------------------------*\n");
	printf("\n\tEnter your choice...\t");
	scanf(" %c",&op);
	printf("\n");
	ST*ptr=hptr,*temp;
	if((op=='R')||(op=='r'))
	{
		
		roll_no();
		printf("\tThe given Roll_no's Data is deleted...\n");
		return;
	}
	else if((op=='N')||(op=='n'))
	{
		char s[30];
		printf("\n\tEnter which Name's Data to remove...");
		scanf(" %s",s);
		printf("\n\n");
		while(ptr!=0)
		{
			if((strcmp(ptr->name,s))==0)
			{
				count++;
				temp=ptr;
			}
			ptr=ptr->next;
		}ptr=hptr;
		if(count>1)
		{
			printf("\n\tThe given name occurs more than once in the list...");
			while(ptr!=0)
			{
				if(strcmp(ptr->name,s)==0)
				{
					printf("\n\t%d\t%s\t%f",ptr->roll,ptr->name,ptr->mark);
				}
				ptr=ptr->next;
			}
			roll_no();
			printf("\tThe given Name's Data is deleted...\n");
			return;
		}
		else if(count==1)
		{
			ptr=temp;
			if(ptr->prev==0)
			{
				ptr->next->prev = ptr->prev;
				hptr=ptr->next;
			}
			else if(ptr->next==0)
				ptr->prev->next = ptr->next;
			else
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			free(ptr);
			printf("\tThe given Name's Data is deleted...\n");
			return;
		}
	}
	else
	{
		printf("\tInvalid Operation...\n");
		return;
	}
	printf("\tThe given data is not in the list.....\n");
}
void roll_no()
{	
	ST*ptr=hptr;
	int n;
	printf("\n\tEnter which Roll_no's Data to remove....");
	scanf(" %d",&n);
	printf("\n\n");
	while(ptr!=0)
	{
		if(ptr->roll==n)
		{
			if(ptr->prev==0)
			{
				ptr->next->prev = ptr->prev;
				hptr=ptr->next;
			}
			else if(ptr->next==0)
				ptr->prev->next = ptr->next;
			else
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			free(ptr);
			break;
		}
		else
			ptr=ptr->next;
	}
}
			



