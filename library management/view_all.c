// view all books
// Date:09/12/2025

#include"header.h"

extern st*hptr;

void all_book_list()
{
	if(hptr==0)
	{
		printf("\n");
		printf("\t*** Book Record Is Empty ***\n");
		printf("\n");
	}
	else
	{
		printf("\n\n");
		printf("\t*-----------------------------------------------------------------------------------------------*\n");
		printf("\t|                                  *** All Book Record ***                                      |\n");
		printf("\t|-----------------------------------------------------------------------------------------------|\n");
		printf("\t|   Book ID   |                Title                   |          Author        |    Quantity   |\n");
		printf("\t*-----------------------------------------------------------------------------------------------*\n");
		st*temp=hptr;
		while(temp!=0)
		{
			 printf("\t|   %-9u | %-38s | %-22s | %-13d |\n",temp->bk_id,temp->bk_title,temp->bk_author,temp->bk_quantity);
		//	printf("\t|\t%u\t|%s|%s|%d|\n",temp->bk_id,temp->bk_title,temp->bk_author,temp->bk_quantity);
			printf("\t|-------------|----------------------------------------|------------------------|---------------|\n");
			temp=temp->next;
		}
		printf("\t|                                  ***  End of Record  ***                                      |\n");
		printf("\t*-----------------------------------------------------------------------------------------------*\n");
		printf("\n\n");
	}

}
