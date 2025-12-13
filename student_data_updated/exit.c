#include<stdio.h>
#include"header.h"

int exit_can()
{
	char op;
	printf("\n\n");
	printf("\t*------------------------------------------*\n");
	printf("\t|   S/s   |   Save and Exit...             |\n");
	printf("\t|------------------------------------------|\n");
	printf("\t|   W/w   |   Don't Save and Exit...       |\n");
	printf("\t|------------------------------------------|\n");
	printf("\t|   C/c   |   Cancel and Don't exit...     |\n");
	printf("\t*------------------------------------------*\n");
	printf("\n");
	printf("\tEnter your choice...");
	scanf(" %c",&op);
	printf("\n");
	if((op=='S')||(op=='s'))
	{
		save();
		return 1;
	}
	else if((op=='W')||(op=='w'))
	{
		printf("\n\tThe student Data's are not saved...\n");
		return 1;
	}
	else if((op=='C')||(op=='c'))
	{
		return 0;
	}
	else
		printf("\n\tInvalid Operation...\n");
	return -1;
}
