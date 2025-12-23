// add new book 
// Date: 09/12/2025
#include"header.h"

extern st*hptr;

void new_book()
{
	char co;
	do
	{
		st *temp = (st*)malloc(sizeof(st));
		printf("\n");
		printf("\tEnter Book ID...\t");
		scanf("%u",&temp->bk_id);
		printf("\n");
		printf("\tEnter Book Title...\t");
		scanf(" %[^\n]",temp->bk_title);
		printf("\n");
		printf("\tEnter Book Author...\t");
		scanf(" %[^\n]",temp->bk_author);
		printf("\n");
		printf("\tEnter Book Quantity...\t");
		scanf("%u",&temp->bk_quantity);
		printf("\n");
		temp->next=0;
		if(hptr==0)
		{
			hptr=temp;
		}
		else
		{
			st*last=hptr;
			while(last->next!=0)
				last=last->next;
			last->next=temp;
		}
		printf("\tDo you want to add another book...(yes-y/no-n)\t");
		scanf(" %c",&co);
	}while((co=='y')||(co=='Y'));
	printf("\n\n");

}
		

