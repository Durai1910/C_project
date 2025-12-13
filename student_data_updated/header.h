struct st
{
	struct st*prev;
	int roll;
	char name[30];
	float mark;
	struct st*next;
};
typedef struct st ST;
//struct st*hptr=0; 
void read();
void write();
void display();
void remove_node();
void sort();
int exit_can();
void save();

void delete();
void reverse();
void insert();
void modify();
void modify_data(struct st*);

