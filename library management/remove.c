// remove book function
// Date: 14/12/2025

#include"header.h"

extern st*hptr;

void remove_book()
{
	char s,ch;
	st*pt=NULL;
	printf("\n\n");
	printf("\t*--------------------------------------------------*\n");
	printf("\t|             *** Remove Book ***                  |\n");
	printf("\t|--------------------------------------------------|\n");
	printf("\t|      1     |     By Book_ID                      |\n");
	printf("\t|------------|-------------------------------------|\n");
	printf("\t|      2     |     By Book_Name                    |\n");
	printf("\t|------------|-------------------------------------|\n");
	printf("\t|      3     |     By Book_Author                  |\n");
	printf("\t|------------|-------------------------------------|\n");
	printf("\t|      4     |     Back to Main Menu               |\n");
	printf("\t*--------------------------------------------------*\n");
Pistol:
	printf("\n\tEnter your choice...(1/2/3)\t");
	scanf(" %c",&s);
	printf("\n");
	switch(s)
	{
		case '1': pt=book_sh(1,2);
		          break;
		case '2': pt=book_sh(2,2);
		          break;
		case '3': pt=book_sh(3,2);
			  break;
		case '4':  return;
		default: printf("\tInvalid Operation...\n");
			 goto Pistol;
	}
	if(pt!=NULL)
	{
		printf("\n\n");
		printf("\n\tAre you sure to delete this data permanently...\n");
press:
		printf("\n\tPress (y/Y - for Yes)/(n/N - for No)...\t");
		scanf(" %c",&ch);
		printf("\n");
		if((ch=='N')||(ch=='n'))
		{
			printf("\tDelete Cancelled...\n\n");
			return;
		}
		else if((ch=='Y')||(ch=='y'))
		{
			st*prev=hptr;
			if(pt==hptr)
			{
				hptr=pt->next;
				free(pt);
			}
			else if(pt->next==0)
			{
				while(prev->next!=pt)
					prev=prev->next;
				prev->next=0;
				free(pt);
			}
			else
			{
				while(prev->next!=pt)
					prev=prev->next;
				prev->next=pt->next;
				free(pt);
			}
			printf("\tThe chosen data is Deleted successfully...\n\n");
		}
		else
		{
			printf("\n\tInvalid Operator...\n");
			goto press;
		}
	
	}
}
