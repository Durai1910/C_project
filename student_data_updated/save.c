#include<stdio.h>
#include"header.h"
#include<stdlib.h>

extern ST*hptr;
void save()
{
	write();
	FILE*fw=fopen("student_data","a+");
	ST*ptr=hptr;
	
	while(ptr!=0)
	{
		fprintf(fw,"%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;
	}
	printf("\n\tThe Student data's are save in a file Successfully...\n");
	fclose(fw);
}
void read()
{
	FILE*fr=fopen("student_data","a+");
	ST temp;
	char ch;
	while(fscanf(fr,"%d %s %f",&temp.roll,temp.name,&temp.mark)!=EOF)
	{
		ST *ptr=(ST*)malloc(sizeof(ST));
		if(hptr==0)
		{
			hptr=ptr;
			*ptr=temp;
			ptr->prev=0;
			ptr->next=0;
		}
		else
		{
			ST*last=hptr;
			while((last->next)!=0)
				last=last->next;
			*ptr=temp;
			ptr->roll=(last->roll)+1;
			ptr->prev=last;
			last->next=ptr;
			ptr->next=0;
		}
		ch=fgetc(fr);
	}fclose(fr);
}
void write()
{
	FILE * fn=fopen("student_data","w");
	fclose(fn);
}
