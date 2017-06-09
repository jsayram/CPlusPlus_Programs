// Program #: 4
//
// Programmer: Jose Ramirez
//
// Due Date: October 23, 2014
//
// EGRE 246, Fall 2014       Instructor: Robert Klenke
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: Function header file , contains defines, structures , and function prototypes 
//
// Input: N/A
//
// Output: N/A
//
//*********************************************************************************

#define MAX_LENGTH 64

#define MAX_CHAR	256
//structure for linked list. 
struct account_list {
	char last_name[MAX_LENGTH];
	char first_name[MAX_LENGTH];
	int account_no;
	double balance;
	struct account_list *next;
};

void write(ofstream& out_file, struct account_list *list); // prints out to a file 

//adds account to list 
struct account_list *add_to_head(struct account_list *list, char *last_name, char *first_name, int account_no, double balance);

struct account_list *remove_account(struct account_list *list, int pick); //removes account from the list based on user input.				 
int menu(); //prints menu
void print(struct account_list *list);  //prints the list to buffer

//prototypes for functions checking account , or name is in the list , before it goes through to delete the list 
int check_account_in_list(struct account_list *list, int acct);
int check_name_in_list(struct account_list *list,string lname,string fname);
