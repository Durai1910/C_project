#include<stdio.h>
#include<string.h>
#include"header.h"
extern struct st *hptr;

void modify()
{	int count=0;
	char op;
	struct st *ptr=hptr ,*temp;
	if(ptr==0)
	{
		printf("\t\tThe student record is empty...\n");
		return;
	}
	printf("\n\n\n");
//	printf("\t**enter which record to search for**\n");
	printf("\t*--------------------------------------*\n");
	printf("\t|   R/r   |  Search by Roll number...  |\n");
	printf("\t|---------|----------------------------|\n");
	printf("\t|   N/n   |  Search by Name...         |\n");
	printf("\t*--------------------------------------*\n");
	printf("\n\tEnter your option...");
	scanf(" %c",&op);

	printf("\n");

	if((op=='R')||(op=='r'))
	{
		int roll_no;
	Zoro:
		ptr=hptr;
		printf("\n\tEnter the roll_no...");
		scanf("%d",&roll_no);
		printf("\n");
		while(ptr!=0)
		{
			if(ptr->roll==roll_no)
			{
				modify_data(ptr);
				return;
			}
			ptr=ptr->next;	
		}
	}
	else if((op=='N')||(op=='n'))
	{
		char s[30];
		printf("\n\tEnter the name...");
		scanf("%s",s);
		printf("\n");
		while(ptr!=0)
		{
			if(strcmp(ptr->name,s)==0)
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
			goto Zoro;
		}
		else if(count==1)
		{
			modify_data(temp);
			return;
		}
		
	}
	else
	{
		printf("\n\tInvalid operation...\n");
		return;
	}
	printf("\n\tThe given data is not found in the list...\n");
}
void modify_data(struct st * ptr)
{
	char op;
	printf("\t*--------------------------------------------*\n");
	printf("\t|   N/n   |   To change Name...              |\n");
	printf("\t|---------|----------------------------------|\n");
	printf("\t|   M/m   |   To change Mark...              |\n");
	printf("\t*--------------------------------------------*\n");
	printf("\n\tEnter your choice...");
	scanf(" %c",&op);
	printf("\n");
	if((op=='N')||(op=='n'))
	{
		char s[30];
		printf("\tEnter the new Name to change...");
		scanf("%s",s);
		printf("\n");
		strcpy(ptr->name,s);
		printf("\n\tName successfully changed...\n");
	}
	else if((op=='M')||(op=='m'))
	{
		float f;
		printf("\tEnter the new Mark to change...");
		scanf("%f",&f);
		printf("\n");
		ptr->mark=f;
		printf("\n\tMark successfully changed...\n");
	}
	else
	{
		printf("\n\tInvalid operation...\n");
	}
}



