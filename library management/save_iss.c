#include"header.h"

extern iss_rec*iss_hptr;

void save_iss()
{
	write_iss();
	FILE*fw=fopen("Issue_Records","a+");
	iss_rec*temp=iss_hptr;
	
	fprintf(fw,"*------------------------------------------------------------------------------------------------------------------------*\n");
	fprintf(fw,"|                                                 *** Issue Book Record ***                                              |\n");
	fprintf(fw,"|------------------------------------------------------------------------------------------------------------------------|\n");
	fprintf(fw,"|  Issue ID  |  Book ID  |  User ID  |      User Name      |  Issue Date  |  Due Date  |  Return Date  |  Return Status  |\n");
	fprintf(fw,"*------------------------------------------------------------------------------------------------------------------------*\n");
	
	while(temp!=0)
	{
		fprintf(fw,"|  %-10u|  %-9u|  %-9u|  %-19s|  %-12s|  %-10s|  %-13s|  %-15s|\n",temp->iss_id,temp->bk_id,temp->usr_id,temp->usr_name,temp->iss_date,temp->due_date,temp->ret_date,temp->ret_status);
		temp=temp->next;
	}
	fprintf(fw,"*------------------------------------------------------------------------------------------------------------------------*\n");
	printf("\n\tThe Student data's are save in a file Successfully...\n\n\n");
	fclose(fw);
}
void read_iss()
{
	FILE*fr=fopen("Issue_Records","r");
	
	iss_rec temp;
	char line[300];
	fgets(line,sizeof(line),fr);
	fgets(line,sizeof(line),fr);
	fgets(line,sizeof(line),fr);
	fgets(line,sizeof(line),fr);
	fgets(line,sizeof(line),fr);
	
	while(fgets(line,sizeof(line),fr)!=NULL)
	{
		if(line[0]=='*')
			break;
		
		if(sscanf(line,"|  %u |  %u |  %u |  %[^|] |  %[^|] |  %[^|] |  %[^|] |  %[^|] |",&temp.iss_id,&temp.bk_id,&temp.usr_id,temp.usr_name,temp.iss_date,temp.due_date,temp.ret_date,temp.ret_status)==8)
		{
			for (int i = strlen(temp.usr_name)-1; (i >= 0) && (temp.usr_name[i]==' '); i--)
                		temp.usr_name[i] = '\0';
			for (int i = strlen(temp.iss_date)-1; (i >= 0) && (temp.iss_date[i]==' '); i--)
                		temp.iss_date[i] = '\0';
			for (int i = strlen(temp.due_date)-1; (i >= 0) && (temp.due_date[i]==' '); i--)
                		temp.due_date[i] = '\0';

            		for (int i = strlen(temp.ret_date)-1; (i >= 0) && (temp.ret_date[i]==' '); i--)
                		temp.ret_date[i] = '\0';

			iss_rec *ptr=(iss_rec*)malloc(sizeof(iss_rec));
			if(iss_hptr==0)
			{
				iss_hptr=ptr;
				*ptr=temp;
				ptr->next=0;
			}
			else
			{
				iss_rec*last=iss_hptr;
				while((last->next)!=0)
				last=last->next;
				*ptr=temp;
				last->next=ptr;
				ptr->next=0;
			}
		}
	}fclose(fr);
}
void write_iss()
{
	FILE * fn=fopen("Issue_Records","w");
	fclose(fn);
}

/*void read()
{
    FILE* fr = fopen("Book_Records", "r");
    if (!fr) { printf("File not found!\n"); return; }

    st temp;
    char line[300];

    // Skip header lines until first data line
    	fgets(line,sizeof(line),fr);
	fgets(line,sizeof(line),fr);
	fgets(line,sizeof(line),fr);
	fgets(line,sizeof(line),fr);
	fgets(line,sizeof(line),fr);

   while(fgets(line, sizeof(line), fr) != NULL)
    {
        if(line[0] == '*') // end of table
            break;

        if(sscanf(line, "| %u | %40[^|] | %24[^|] | %u |",
                  &temp.bk_id, temp.bk_title, temp.bk_author, &temp.bk_quantity))
        {
            // Trim trailing spaces
            for (int i = strlen(temp.bk_title)-1; i >= 0 && temp.bk_title[i]==' '; i--)
                temp.bk_title[i] = '\0';

            for (int i = strlen(temp.bk_author)-1; i >= 0 && temp.bk_author[i]==' '; i--)
                temp.bk_author[i] = '\0';

            // Debug print
            printf("%u | %s | %s | %u read\n", temp.bk_id, temp.bk_title, temp.bk_author, temp.bk_quantity);

            // Insert into linked list
            st *ptr = (st*)malloc(sizeof(st));
            *ptr = temp;
            ptr->next = NULL;

            if(hptr == NULL)
            {
                hptr = ptr;
            }
            else
            {
                st* last = hptr;
                while(last->next != NULL)
                    last = last->next;
                last->next = ptr;
            }
        }
    }
    fclose(fr);
}*/
