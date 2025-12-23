// view issue records
// Date:15/12/2025

#include"header.h"

extern iss_rec*iss_hptr;

void issue_list()
{
	if(iss_hptr==0)
	{
		printf("\n");
		printf("\t*** Issue Book Record Is Empty ***\n");
		printf("\n");
	}
	else
	{
		printf("\n\n");
		printf("\t*------------------------------------------------------------------------------------------------------------------------*\n");
		printf("\t|                                             *** Issue Book Record ***                                                  |\n");
		printf("\t|------------------------------------------------------------------------------------------------------------------------|\n");
		printf("\t|  Issue ID  |  Book ID  |  User ID  |      User Name      |  Issue Date  |  Due Date  |  Return Date  |  Return Status  |\n");
		printf("\t*------------------------------------------------------------------------------------------------------------------------*\n");
		iss_rec*temp=iss_hptr;
		while(temp!=0)
		{
			printf("\t|  %-10u|  %-9u|  %-9u|  %-19s|  %-12s|  %-10s|  %-13s|  %-15s|\n",temp->iss_id,temp->bk_id,temp->usr_id,temp->usr_name,temp->iss_date,temp->due_date,temp->ret_date,temp->ret_status);
			printf("\t|------------|-----------|-----------|---------------------|--------------|------------|---------------|-----------------|\n");
		
			temp=temp->next;
		}
		printf("\t|                                              ***  End of Record  ***                                                   |\n");
		printf("\t*------------------------------------------------------------------------------------------------------------------------*\n");
		printf("\n\n");
	}

}
