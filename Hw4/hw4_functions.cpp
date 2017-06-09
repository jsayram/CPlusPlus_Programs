//*********************************************************************************
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
// Description: cpp source file that contains the implementation of all the functions
// 				used in program, functions populate a linked list, or delete form a list
//				   smaller functions implemented to simplify the flow of main. 
// Input: NA
//
// Output: Linked list return to be used in main 
//
//*********************************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#include "hw4.h"

// function to print a linked list of account_list
// structures to a file
void write(ofstream& out_file, struct account_list *list) {

	 account_list *current;

	//loops through list and prints out the accounts to output file. 
	for(current=list;current!=NULL;current=current->next) 
		out_file << fixed <<current->last_name<<"\t"<< current->first_name<<"\t"
		        <<current->account_no <<"\t"<< setprecision(2) << current->balance << endl;

}		// end write*/

/*Function populates a NuLL liked list with a first name , last name , account number, and balance 
  passed as arguments to the function*/
 struct account_list *add_to_head(account_list *list, char *last_name, char *first_name, int account_no, double balance) {

	 account_list *current;//initializes a temporary variable used to add to head of the list
	//this will only be called once at the beginning

	if(list == NULL) 
	{//this if statement is only executed if the list when passed is empty 
						 //and it will populate the list with the first entry. 
		list = new account_list;
		strcpy(list->last_name,last_name);//adds last name to the list 
		strcpy(list->first_name,first_name); //adds first name to the list
		list->account_no = account_no;//adds account number to the list
		list->balance = balance;//adds balance to the list
		list->next = NULL;//sets the next pointer equal to null 
		return(list);//returns updated list to main. 
	}
	else
	{  //when the list is not empty this will be executed populating the list
		current = new account_list;
		strcpy(current->last_name,last_name);
		strcpy(current->first_name,first_name);
		current->account_no = account_no;
		current->balance = balance;
		current->next = list;
		return(current);
	}
	
}	
//function used for user option to delete a member
struct account_list *remove_account(struct account_list *list, int pick){
   
    account_list *current;
	account_list *temp;
	
	int acct,i;
	
	//declares strings variables for first and last name
	string lname;
	string fname;
	int count;  //counter for finding by account error
	int count1; //counter for finding by name error

	current=list;
	if(pick==0)  //enters here if the user chooses to delete by account number (0)
	{
        cout<<"Enter account number to delete:";
		cin>>acct;
		//checks if the user is even in the list before removing 
		count=check_account_in_list(list,acct);
		if(count==0)
		{
		  cout<<"\nERROR: account number "<<acct<<" cannot be found in the list!\n"<<endl;
		  return list;
		}
	    //if the account is at the head just delete it 	
		if(list->account_no==acct)
		{      
			cout<<"\nAccount for "<< list->last_name<< ", " << list->first_name<<" Successfully deleted"<<endl;
		    temp=list;
			list=list->next;
			delete temp;
		    return list;
		}
		//iterates through list till it find the account it needs to delete and deletes it 
	    for(current=list;current!=NULL;current=current->next)
		{  
		    if(current->next->account_no==acct)
			{  
			   cout<<"\nAccount for "<< current->next->last_name<< ", " << current->next->first_name<<" Successfully deleted"<<endl;
			   
			   temp=current->next;
			   current->next=current->next->next;
			   delete temp;
			   return list;
			}
		}
	}
	if(pick==1) //enters here if the user chooses to delete by last name and first name (1)
	{   
		cout<<"Enter Last Name and First Name of account to delete:"; //prompts user for LastName then FirstName.
		cin>>lname;
		cin>>fname;
		
		//checks if user is even in the list before deleting
		//if the person name found it returns a 1 if not found returns 0
		count=check_name_in_list(list,lname,fname);
		
		//if is not first and last name entered not in the list it lets
		//the user know and returns the list unchanged back to main using the 
		//return of count
		if(count==0)
		{
		   cout<<"\nERROR: account for "<<lname<<", "<<fname<<" cannot be found!\n"<<endl;
		   return list;
		}	
		// if the name to delete is at the head, just delete it 
		if((list->last_name==lname) && (list->first_name==fname))
		{  cout<<"\nAccount number "<< list->account_no<<" Successfully deleted."<<endl;
		    temp=list;
			list=list->next;
			delete temp;
		    return list;
		}
		//iterates through list to find the pointer to delete 
	    for(current=list;current!=NULL;current=current->next)
		{  
		    if((current->next->last_name==lname) && (current->next->first_name==fname))
			{ 
			   cout<<"\nAccount number "<< current->next->account_no<<" Successfully deleted."<<endl;
	
			   temp=current->next;
			   current->next=current->next->next;
			   delete temp;
			   return list;
			}  
		}
	}
}  //end account_list
// function to print out a linked list of account_list structures
void print(account_list *list) {

	account_list *current;

	//print the list again
	cout<< "Member List\n";
	cout<<"Last name\tfirst name\taccount no.\tbalance\n";
	cout<<"----------------------------------------------------------\n";
	for(current=list;current!=NULL;current=current->next) 
		cout<< fixed << current->last_name<<"\t\t"<<current->first_name<<"\t\t"<<
		current->account_no<<"\t\t"<< setprecision(2) <<current->balance<<endl;

}		// end print


//check if the account numbered entered is actually in the list
int check_account_in_list(struct account_list *list, int acct)
{  
	account_list *current;
	int count=0;
	//searches  through the list if the member is found it will then increment count to one and return it to main
	    for(current=list;current!=NULL;current=current->next)
		{  
		    if(current->account_no==acct)
			{ 
			   count++;
			   return count;
			}  
		}
		return count;	
}  //end check_account_in_list

//check if the last name and first name entered is actually in the list
int check_name_in_list(struct account_list *list, string lname, string fname)
{ 
	account_list *current;
	int count=0;
	//searches  through the list if the member is found it will then increment count to one and return it to main
	    for(current=list;current!=NULL;current=current->next)
		{  
		    if((current->last_name==lname) && (current->first_name==fname))
			{ 
			   count++;
			   return count;
			}  
		}
	return count;
}

// function to print out the menu for the main program and
// return the user's option
int menu()
{
	int choice;

	cout<<"\nEnter option:\n";
	cout<<"\t(0) Write output file and exit\n";
	cout<<"\t(1) Print the list\n";
	cout<<"\t(2) Add new account at head of the list\n";
	cout<<"\t(3) Delete account from the list\n";
	cout<<"\t(4) Calculate and display average balance\n";
	cout<<"\t\tChoice ?";

	cin>> choice;
	cin.ignore();
	cout<<endl;
	return(choice);
	
}	// end menu
