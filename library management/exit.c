#include"header.h"

int exit_lb()
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
exit:
	printf("\tEnter your choice...(s/w/c)\t");
	scanf(" %c",&op);
	printf("\n");
	if((op=='S')||(op=='s'))
	{
		save();
		save_iss();
		return 1;
	}
	else if((op=='W')||(op=='w'))
	{
		printf("\n\tThe Book Record are not saved...\n");
		return 1;
	}
	else if((op=='C')||(op=='c'))
	{
		return 0;
	}
	else
	{
		printf("\n\tInvalid Operation...\n");
		goto exit;
	}
	
}
