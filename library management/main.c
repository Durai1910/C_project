#include"header.h"
st *hptr=0;
iss_rec *iss_hptr=0;

int main()
{
	read();
	read_iss();
	char op;
	int ex;
Nika:
	printf("\t*-----------------------------------------------*\n");
	printf("\t|         ***Book Management Menu***            |\n");
	printf("\t|-----------------------------------------------|\n");
	printf("\t|        1     |      Add New Book              |\n");
	printf("\t|--------------|--------------------------------|\n");
	printf("\t|        2     |      Update Book Details       |\n");
	printf("\t|--------------|--------------------------------|\n");
	printf("\t|        3     |      Search Book               |\n");
	printf("\t|--------------|--------------------------------|\n");
	printf("\t|        4     |      Issue Book                |\n");
	printf("\t|--------------|--------------------------------|\n");
	printf("\t|        5     |      Return Book               |\n");
	printf("\t|--------------|--------------------------------|\n");
	printf("\t|        6     |      Remove Book               |\n");
	printf("\t|--------------|--------------------------------|\n");
	printf("\t|        7     |      List Issued Books         |\n");
	printf("\t|--------------|--------------------------------|\n");
	printf("\t|        8     |      View All Books            |\n");
	printf("\t|--------------|--------------------------------|\n");
	printf("\t|        9     |      Save                      |\n");
	printf("\t|--------------|--------------------------------|\n");
	printf("\t|       E/e    |      Exit                      |\n");
	printf("\t*-----------------------------------------------*\n");
Sungod:
	printf("\n\n\tEnter your choice...\t");
	scanf(" %c",&op);
	printf("\n");
	if(op=='E')
		op^=32;
	switch(op)
	{
		case '1':new_book();
		       goto Nika;

		case '2':update_book();
		       goto Nika;

		case '3':search_book();
		       goto Nika;

		case '4':issue_book();
		       goto Nika;

		case '5':return_book();
		       goto Nika;

		case '6':remove_book();
		       goto Nika;

		case '7':issue_list();
		       goto Nika;

		case '8':all_book_list();
		       goto Nika;

		case '9':save();
			 save_iss();
		       goto Nika;

		case 'e':ex=exit_lb();
			if(ex==1)
			{
				printf("\n\tSuccessfully Exited...\n\n");
				return 0;
			}
			else if(ex==0)
			{
				printf("\n\tThe exit operation is Canceled...\n\n");
				goto Nika;
			}
			goto Nika;

		default:printf("\n\tInvalid choice...\n");
		       goto Sungod;
	}
}

		 
