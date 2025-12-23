#include"header.h"

extern st*hptr;

void save()
{
	write();
	FILE*fw=fopen("Book_Records","a+");
	st*temp=hptr;
	
	fprintf(fw,"*-------------------------------------------------------------------------------------------------*\n");
	fprintf(fw,"|                                    *** All Book Record ***                                      |\n");
	fprintf(fw,"|-------------------------------------------------------------------------------------------------|\n");
	fprintf(fw,"|   Book ID   |                Title                    |          Author         |    Quantity   |\n");
	fprintf(fw,"*-------------------------------------------------------------------------------------------------*\n");
	
	while(temp!=0)
	{
		fprintf(fw,"|  %-11u| %-40s| %-24s|  %-13u|\n",temp->bk_id,temp->bk_title,temp->bk_author,temp->bk_quantity);
		temp=temp->next;
	}
	fprintf(fw,"*-------------------------------------------------------------------------------------------------*\n");
	printf("\n\tThe Student data's are save in a file Successfully...\n\n\n");
	fclose(fw);
}
void read()
{
	FILE*fr=fopen("Book_Records","r");
	
	st temp;

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
		
		
		if(sscanf(line,"|  %u | %40[^|] | %24[^|] |  %u |",&temp.bk_id,temp.bk_title,temp.bk_author,&temp.bk_quantity)==4)
		{
			for (int i = strlen(temp.bk_title)-1; (i >= 0) && (temp.bk_title[i]==' '); i--)
                		temp.bk_title[i] = '\0';

            		for (int i = strlen(temp.bk_author)-1; (i >= 0) && (temp.bk_author[i]==' '); i--)
                		temp.bk_author[i] = '\0';

			st *ptr=(st*)malloc(sizeof(st));
			if(hptr==0)
			{
				hptr=ptr;
				*ptr=temp;
				ptr->next=0;
			}
			else
			{
				st*last=hptr;
				while((last->next)!=0)
				last=last->next;
				*ptr=temp;
				last->next=ptr;
				ptr->next=0;
			}
		}
	}fclose(fr);
}
void write()
{
	FILE * fn=fopen("Book_Records","w");
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
