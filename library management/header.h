#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


//user defined function
typedef struct new
{
	unsigned int bk_id;
	unsigned char bk_title[100];
	unsigned char bk_author[100];
	unsigned int bk_quantity;
	struct new *next;
} st;

typedef struct issue
{
	unsigned int iss_id;
	unsigned int bk_id;
	unsigned int usr_id;
	unsigned char usr_name[100];
	unsigned char iss_date[30];
	unsigned char due_date[30];
	unsigned char ret_date[30];
	unsigned char ret_status[30];
	struct issue *next;
} iss_rec;

void new_book();
void all_book_list();
void save();
void read();
void write();
int exit_lb();
void search_book();
st* book_sh(int,int);
void update_book();
void remove_book();
void issue_book();
void save_iss();
void read_iss();
void write_iss();
void issue_list();
void return_book();
void string_to_tm(const char *,struct tm*);
int calculate_fine(char*,char*);





