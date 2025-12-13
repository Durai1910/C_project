#include<stdio.h>
#include"header.h"
#include<stdlib.h>
extern ST*hptr;
void delete()
{
	ST*ptr=hptr,*last;
	while(ptr!=0)
	{
		last=ptr;
		ptr=ptr->next;
		free(last);
	}
	write();
	hptr=0;
	printf("\n\t All Data's are Deleted...\n");
}
