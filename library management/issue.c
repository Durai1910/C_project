// issue book 
// Date: 09/12/2025
#include"header.h"

extern iss_rec *iss_hptr;
extern st*hptr;
void issue_book()
{
	time_t t;
	struct tm date;
	if(hptr==0)
	{
		printf("\n\tThe Book Record is Empty\n");
		return;
	}
	printf("\n\t\t***** To Issue Book *****\n");
	st*ptr=NULL;

	ptr=book_sh(1,3);
	if((ptr!=NULL)&&(ptr->bk_quantity==0))
	{
		printf("\n\tThere is no Book Available in the Library for the given Book_ID...\n");
		return;
	}
	
	if(ptr!=NULL)
	{
		iss_rec *temp = (iss_rec*)malloc(sizeof(iss_rec));
		printf("\n");

		temp->bk_id=ptr->bk_id;

		printf("\tEnter Issue ID...\t");
		scanf(" %u",&temp->iss_id);
		printf("\n");

		printf("\tEnter User ID...\t");
		scanf("%u",&temp->usr_id);
		printf("\n");


		printf("\tEnter User Name...\t");
		scanf(" %[^\n]",temp->usr_name);
		printf("\n");
		
		time_t t;
	        struct tm date;

    		t = time(NULL);
	        date = *localtime(&t);

	        strftime(temp->iss_date, sizeof(temp->iss_date), "%d-%m-%Y", &date);
    
    		date.tm_mday += 7;
	        mktime(&date);   

    		strftime(temp->due_date, sizeof(temp->iss_date), "%d-%m-%Y", &date);

/*		printf("\tEnter Issue Date...\t");
		scanf(" %[^\n]",temp->iss_date);
		printf("\n");
		
		printf("\tEnter Due Date...\t");
		scanf(" %[^\n]",temp->due_date);
		printf("\n");

*/		strcpy(temp->ret_status,"No");
		strcpy(temp->ret_date,"-");
		temp->next=0;
		if(iss_hptr==0)
		{
			iss_hptr=temp;
		}
		else
		{
			iss_rec*last=iss_hptr;
			while(last->next!=0)
				last=last->next;
			last->next=temp;
		}
		ptr->bk_quantity-=1;	
	}
	printf("\n\tBook Issued Successfully...\n");
	printf("\n\n");

}
		
