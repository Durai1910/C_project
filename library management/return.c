// return book function
// Date: 10/12/2025

#include"header.h"

extern iss_rec*iss_hptr;
extern st*hptr;

void return_book()
{
	unsigned int id,usr,count=0;
	unsigned char ch;
	char p,ret_date[30];
issue:
	printf("\n\n");
	printf("\n\t\t*** Return Book Function Called ***\n");
	if(iss_hptr==NULL)
	{
		printf("\n\tThe Issue Book Record is Empty...\n");
		return;
	}
	time_t t;
        struct tm date;

 	t = time(NULL);
        date = *localtime(&t);
	strftime(ret_date, sizeof(ret_date), "%d-%m-%Y", &date);
        
    
	printf("\n\tEnter BooK_ID to return...\t");
	scanf(" %d",&id);
	printf("\n");
	printf("\n\tEnter User_ID to return...\t");
	scanf(" %d",&usr);
	printf("\n");
	
	iss_rec*temp=iss_hptr;
	st*ptr=hptr;
	if(temp!=0)
	{
		while(temp!=0)
		{
			if((temp->bk_id==id)&&(temp->usr_id==usr))
			{
				
				int fine=calculate_fine(temp->due_date,ret_date);
				if(fine>0)
				{	
					printf("\n\tThe fine amount is Rs.%d",fine);
					printf("\n\n\tEnter y-if amount is paid or else you can't return the book...\t");
					scanf(" %c",&p);
					if((p!='y')&&(p!='Y'))
					{
						printf("\n\n\tReturn Function Canceled...\n\n");
						return;
					}
					
					printf("\n\n\tFine Amount paid Successfully...\n");
				}
				strftime(temp->ret_date, sizeof(temp->ret_date), "%d-%m-%Y", &date);
				strcpy(temp->ret_status,"Returned");
				count++;
				printf("\n\tReturned Status Updated...\n");
				break;
			}
			temp=temp->next;
		}
		while((ptr!=0)&&(count!=0))
		{
			if(ptr->bk_id==id)
			{
				ptr->bk_quantity+=1;
				printf("\n\tThe Returned BooK quantity is updated...\n\n");
				break;
			}
			ptr=ptr->next;
		}

	}
	if((count==0))
	{
		printf("\n\tThe Given Book_ID is not found in the list...\n");
		printf("\n\tTo show the Entire Issue Book Record...\n");
		printf("\n\tEnter (y-yes/n-no)...\n");
		scanf(" %c",&ch);
		if((ch=='y')||(ch=='Y'))
		{
			issue_list();
			goto issue;
		}
		else
			return;

	}
}

int calculate_fine(char *due_date, char *ret_date)
{
    struct tm due = {0}, ret = {0};

    string_to_tm(due_date, &due);
    string_to_tm(ret_date, &ret);

    time_t due_time = mktime(&due);
    time_t ret_time = mktime(&ret);

    double diff_seconds = difftime(ret_time, due_time);
    int diff_days = diff_seconds / (60 * 60 * 24);

    if (diff_days <= 0)
        return 0;

    return diff_days * 10;
}

void string_to_tm(const char *date, struct tm *t)
{
    int d, m, y;
    sscanf(date, "%d-%d-%d", &d, &m, &y);

    t->tm_mday = d;
    t->tm_mon  = m - 1;     // months start from 0
    t->tm_year = y - 1900;  // years since 1900
    t->tm_hour = 0;
    t->tm_min  = 0;
    t->tm_sec  = 0;
}




