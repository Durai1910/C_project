// update book function
// Date: 14/12/2025

#include"header.h"

extern st*hptr;

void update_book()
{
	char s,ch;
	st*pt=NULL;
	printf("\n\n");
	printf("\t*--------------------------------------------------*\n");
	printf("\t|             *** Update Book by ***               |\n");
	printf("\t|--------------------------------------------------|\n");
	printf("\t|      1     |     By Book_ID                      |\n");
	printf("\t|------------|-------------------------------------|\n");
	printf("\t|      2     |     By Book_Name                    |\n");
	printf("\t|------------|-------------------------------------|\n");
	printf("\t|      3     |     Back to Main Menu               |\n");
	printf("\t*--------------------------------------------------*\n");
Pistol:
	printf("\n\tEnter your choice...(1/2/3)\t");
	scanf(" %c",&s);
	printf("\n");
	switch(s)
	{
		case '1': pt=book_sh(1,1);
		        break;
		case '2': pt=book_sh(2,1);
		        break;
		case '3': return;
		default: printf("\tInvalid Operation...\n");
			 goto Pistol;
	}
	if(pt!=NULL)
	{
		printf("\n\n");
		printf("\t*--------------------------------------------------*\n");
		printf("\t|             *** Options to change***             |\n");
		printf("\t|--------------------------------------------------|\n");
		printf("\t|      1     |     To change Book ID               |\n");
		printf("\t|------------|-------------------------------------|\n");
		printf("\t|      2     |     To change Book name             |\n");
		printf("\t|------------|-------------------------------------|\n");
		printf("\t|      3     |     To change Authors name          |\n");
		printf("\t|--------------------------------------------------|\n");
		printf("\t|      4     |     To change quantity              |\n");
		printf("\t|--------------------------------------------------|\n");
		printf("\t|      5     |     To Cancel/Back to main menu     |\n");
		printf("\t*--------------------------------------------------*\n");
dawn:
		printf("\n\tEnter your Options(1/2/3/4/5)...\t");
		scanf(" %c",&ch);
		printf("\n");
		
		switch(ch)
		{
			case '1': printf("\tEnter Book_ID...\t");
				  scanf(" %u",&pt->bk_id);
				  printf("\n\tSuccessfully ID changed...");
			          goto dawn;
			case '2': printf("\tEnter Book_Title...\t");
				  scanf(" %[^\n]",pt->bk_title);
				  printf("\n\tSuccessfully Title changed...");
			          goto dawn; 
			case '3': printf("\tEnter Book_Author...\t");
				  scanf(" %[^\n]",pt->bk_author);
				  printf("\n\tSuccessfully Author name changed...");
			          goto dawn;
			case '4': printf("\tEnter Book_Quantity...\t");
				  scanf(" %u",&pt->bk_quantity);
				  printf("\n\tSuccessfully Quantity changed...");
			          goto dawn;
			case '5': return;
			default: printf("\tInvalid Operation...\n");
				 goto dawn;
		}
	}
}
