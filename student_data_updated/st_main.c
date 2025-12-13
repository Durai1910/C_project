#include<stdio.h>
#include"header.h"
int main()
{
	int ex;
	char op,ch;
	read();
mrprince:
	printf("\t*------------------------------------*\n");
	printf("\t|         *student record*           |\n");
	printf("\t*------------------------------------*\n");
	printf("\t|    I/i   |   Insert data           |\n");
	printf("\t*----------|-------------------------*\n");
	printf("\t|    M/m   |   Modify the data       |\n");
	printf("\t*----------|-------------------------*\n");
	printf("\t|    R/r   |   Remove the data       |\n");
	printf("\t*----------|-------------------------*\n");
	printf("\t|    S/s   |   Save the data in file |\n");
	printf("\t*----------|-------------------------*\n");
	printf("\t|    D/d   |   Display the data      |\n");
	printf("\t*----------|-------------------------*\n");
	printf("\t|    O/o   |   Sort the data         |\n");
	printf("\t*----------|-------------------------*\n");
	printf("\t|    C/c   |   Reverse the list      |\n");
	printf("\t*----------|-------------------------*\n");
	printf("\t|    A/a   |   Delete all data       |\n");
	printf("\t*----------|-------------------------*\n");
	printf("\t|    E/e   |   Exit from the process |\n");
	printf("\t*------------------------------------*\n");
	printf("Enter your choice...");
	scanf(" %c",&op);
	
	if((op>='a')&&(op<='z'))
		op^=32;
	switch(op)
	{
		case 'I':	do{
				insert();
				printf("\n\tDO you want to insert another student data...press(y-Yes/n-NO)-\t");
				scanf(" %c",&ch);
				}while((ch=='y')||(ch=='Y'));
				goto mrprince;
				
		case 'M':	modify();
				goto mrprince;
			
		case 'R':	remove_node();
				goto mrprince;
			
		case 'S':	save();
				goto mrprince;

		case 'D':	display();
				goto mrprince;

		case 'O':	sort();
				goto mrprince;

		case 'C':	reverse();
				goto mrprince;

		case 'A':	delete();
				goto mrprince;

		case 'E':	ex=exit_can();
				if(ex==1)
				{
					printf("\n\tSuccessfully Exited...\n\n");
					return 0;
				}
				else if(ex==0)
				{
					printf("\n\tThe exit operation is Canceled...\n\n");
					goto mrprince;
				}
				goto mrprince;

		default :	printf("\n\n\tInvalid Operation...\n");
				goto mrprince;
	}
}
