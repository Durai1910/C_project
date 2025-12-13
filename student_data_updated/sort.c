#include<stdio.h>
#include"header.h"
#include<string.h>
#include<stdlib.h>
extern ST*hptr;
void sort()
{
	char op;
	printf("\n");
	printf("\t*   By which option it need to sort....   *\n");
	printf("\t*-----------------------------------------*\n");
	printf("\t|   N/n   |   Sort by Name...             |\n");
	printf("\t|-----------------------------------------|\n");
	printf("\t|   M/m   |   Sort by Mark...             |\n");
	printf("\t*-----------------------------------------*\n");
	printf("\n\n\tEnter your choice...");
	scanf(" %c",&op);
	printf("\n\n");
	ST*ptr=hptr ,*p;
	int size=0,i=0,j,k=sizeof(ST);
	while(ptr!=0)
	{
		size++;
		ptr=ptr->next;
	}ptr=hptr;
	p=(ST*)malloc(size*sizeof(ST));
	while(ptr!=0)
	{
		p[i]=*ptr;
		ptr=ptr->next;
		i++;
	}
	if(ptr=0)
	{
		printf("\n\tThere is no Data to sort...\n\n");
		return;
	}
	struct st temp;
	if((op=='N')||(op=='n'))
	{
		
		for(i=0;i<size-1;i++)
		{
			
			for(j=i+1;j<size;j++)
			{
				if((strcmp(p[i].name,p[j].name))>0)
				{
					memcpy(&temp.prev,&p[i].prev,k);
					memcpy(&p[i].prev,&p[j].prev,k);
					memcpy(&p[j].prev,&temp.prev,k);
				}
				
			}
		}
		printf("\t\tAfter sorting the record...\n");
		i=0;
		while(i<size)
		{
			printf("\t\t %d \t %s \t %f \n",p[i].roll,p[i].name,p[i].mark);
			i++;
		}
		printf("\n\tSorting completed by name...\n");
		free(p);		
		return;
	}
	else if((op=='M')||(op=='m'))
	{
		
		for(i=0;i<size-1;i++)
		{
			
			for(j=i+1;j<size;j++)
			{
				if((p[i].mark)>(p[j].mark))
				{
					memcpy(&temp.prev,&p[i].prev,k);
					memcpy(&p[i].prev,&p[j].prev,k);
					memcpy(&p[j].prev,&temp.prev,k);
				}
				
			}
		}
		printf("\t\tAfter sorting the record...\n");
		i=0;
		while(i<size)
		{
			printf("\t\t %d \t %s \t %f \n",p[i].roll,p[i].name,p[i].mark);
			i++;
			
		}
		printf("\n\tSorting completed by mark...\n");
		free(p);
		return;
	}
	else
	{
		printf("\n\tInvalid Operation....\n");
		return;
	}
}






