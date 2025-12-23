// search book function
// Date: 10/12/2025

#include"header.h"

extern st*hptr;

void search_book()
{
	char s;
	printf("\n\n");
	printf("\t*--------------------------------------------------*\n");
	printf("\t|             *** Search by ***                    |\n");
	printf("\t|--------------------------------------------------|\n");
	printf("\t|      1     |     By Book_ID                      |\n");
	printf("\t|------------|-------------------------------------|\n");
	printf("\t|      2     |     By Book_Name                    |\n");
	printf("\t|------------|-------------------------------------|\n");
	printf("\t|      3     |     By Book_Author                  |\n");
	printf("\t|--------------------------------------------------|\n");
	printf("\t|      4     |     Back to Main Menu               |\n");
	printf("\t*--------------------------------------------------*\n");
Pistol:
	printf("\n\tEnter your choice...(1/2/3/4)\t");
	scanf(" %c",&s);
	printf("\n");
	switch(s)
	{
		case '1': book_sh(1,0);
		        break;
		case '2': book_sh(2,0);
		        break;
		case '3': book_sh(3,0);
		        break;
		case '4': return;
		default: printf("\tInvalid Operation...\n");
			 goto Pistol;
	}
}
st* book_sh(int a,int b)
{
	unsigned int id,count=0;
	unsigned char name[100];
	unsigned char author[70];
	st* ptr=hptr,*temp=NULL;
eren:
	if(a==1)
	{

		printf("\n\tEnter The Book_ID...\t");
		scanf(" %d",&id);
		printf("\n\n");
		printf("\t*-----------------------------------------------------------------------------------------------*\n");
		printf("\t|   Book ID   |                Title                   |          Author        |    Quantity   |\n");
		printf("\t*-----------------------------------------------------------------------------------------------*\n");
		while(ptr!=0)
		{
			if(ptr->bk_id==id)
			{
				printf("\t|   %-9u | %-38s | %-22s | %-13d |\n",ptr->bk_id,ptr->bk_title,ptr->bk_author,ptr->bk_quantity);
				printf("\t|-------------|----------------------------------------|------------------------|---------------|\n");
				count++;
				temp=ptr;
			}
			ptr=ptr->next;
		}
	}
	else if(a==2)
	{
		printf("\n\tEnter The Book_Name...\t");
		scanf(" %[^\n]",name);
		printf("\n\n");
		printf("\t*-----------------------------------------------------------------------------------------------*\n");
		printf("\t|   Book ID   |                Title                   |          Author        |    Quantity   |\n");
		printf("\t*-----------------------------------------------------------------------------------------------*\n");
		while(ptr!=0)
		{
			if(strstr(ptr->bk_title,name)!=0)
			{
				printf("\t|   %-9u | %-38s | %-22s | %-13d |\n",ptr->bk_id,ptr->bk_title,ptr->bk_author,ptr->bk_quantity);
				printf("\t|-------------|----------------------------------------|------------------------|---------------|\n");
			
				count++;
				temp=ptr;
			}
			ptr=ptr->next;
		}
	}
	else if(a==3)
	{
		printf("\n\tEnter The Book_Author...\t");
		scanf(" %[^\n]",author);
		printf("\n\n");
		printf("\t*-----------------------------------------------------------------------------------------------*\n");
		printf("\t|   Book ID   |                Title                   |          Author        |    Quantity   |\n");
		printf("\t*-----------------------------------------------------------------------------------------------*\n");
		while(ptr!=0)
		{
			if(strstr(ptr->bk_author,author)!=0)
			{
				printf("\t|   %-9u | %-38s | %-22s | %-13d |\n",ptr->bk_id,ptr->bk_title,ptr->bk_author,ptr->bk_quantity);
				printf("\t|-------------|----------------------------------------|------------------------|---------------|\n");
			
				count++;
				temp=ptr;
			}
			ptr=ptr->next;
		}
	}
	printf("\t|                                  ***  End of Record  ***                                      |\n");
	printf("\t*-----------------------------------------------------------------------------------------------*\n");
	if(((b==1)||(b==2)||(b==3))&&(count>1))
	{
		printf("\n\tThe given data is present more than one time...\n");
		if(b==1)
			printf("\n\tTo Update correct data...\n");
		else if(b==2)
			printf("\n\tTo Remove correct data...\n");
		else if(b==3)
			printf("\n\tTo Issue correct book...\n");

		printf("\n\tEnter (1 -for ID/2 -for Title/3 -for Author) to search again...\t");
		scanf(" %d",&a);
		printf("\n");
		count=0;
		ptr=hptr;
		goto eren;
	}
	if((count==0)&&(a==1))
	{
		printf("\n\tThe Given Book_ID is not found in the list...\n");
		return NULL;

	}
	else if((count==0)&&(a==2))
	{
		printf("\n\tThe Given Book_Name is not found in the list...\n");
		return NULL;

	}
	else if((count==0)&&(a==3))
	{
		printf("\n\tThe Given Book_Author is not found in the list...\n");
		return NULL;

	}
	printf("\n\n");
	return temp;
}




