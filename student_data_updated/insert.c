#include<stdio.h>
#include"header.h"
#include<stdlib.h>
/*struct st
{
	struct st*prev;
	int roll;
	char name[30];
	float mark;
	struct st*next;
};
typedef struct st ST;
int main()
{
	char ch;
	do
	{
		insert();
		printf("continue\n");
		scanf(" %c",&ch);
	}while((ch=='y')&&(ch=='Y'));
}*/
ST * hptr=0;
void insert()
{
	ST *temp=(ST*)malloc(sizeof(ST));
	printf("enter name and mark....\n");
	scanf("%s %f",temp->name,&temp->mark);
	if(hptr==0)
	{
		temp->roll=1;
		temp->prev=0;
		temp->next=0;
		hptr=temp;
	}
	else
	{
		ST*last=hptr;
		while(((last->next)!=0)&&((last->next->roll-last->roll)==1)&&(hptr->roll==1))
			last=last->next;
		if((last->prev==0)&&(last->next!=0)&&(last->roll!=1))
		{
			last->prev=temp;
			temp->next=last;
			hptr=temp;
			temp->prev=0;
			temp->roll=1;
			return;
		}

		else if(last->next==0)
			temp->next=0;
		else
		{
			temp->next=last->next;
			last->next->prev=temp;
		}
		temp->roll=(last->roll)+1;
		temp->prev=last;
		last->next=temp;
		
	}
}
