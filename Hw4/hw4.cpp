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
// Description: Implementation of linked list that holds a Last name, First name, Account Number
//				and a Balance ,user has menu options, user may
//				(0) Write linked list to an output file 
//				(1) Print The list to the screen 
//			    (2) Add new account at head of the list.
//				(3) Delete account from the list. 
//				(4) Calculate and display Average balance.
//
// Input: command line arguments of input file and output file 
//
// Output: output to output file , or to screen buffer, outs linked list of account members. 
//
//*********************************************************************************

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "hw4.h"

int main(int argc, char *argv[])
{

	fstream infile;
	ofstream outfile;
	char *infilename;
	char *outfilename;
    string duh="/?";

	char last_name_buffer[MAX_LENGTH];
	char first_name_buffer[MAX_LENGTH];
	long double balance;
	int account_no, number,howMany=0, op,pick;

	 account_list *head = 0;
	 account_list *current;

	infilename = new char[MAX_CHAR];
	outfilename = new char[MAX_CHAR];
    infilename=argv[1];
	outfilename=argv[2];
	//command line arguments handlers , if the user does not input the correct usage of program it will 
	// give them a clue 
	cout<< "Program to keep a list of accounts using a linked list"<<endl;
	if(argc<2 || argv[1]==duh) 
	{  
			cout<<"\nUsage: prog4 [input_file_name] [output_file_name]"<<endl;
			return 0;
	}
	// get input file name from the user - change to command line input
		infile.open(infilename,fstream::in);
		if(!infile.is_open()) {
			cout <<"\nERROR: file <" << infilename << "> can not be opened!"<<endl;
			cout <<"Usage: prog4 [input_file_name] [output_file_name]"<<endl;
		  return 0;
		} 
		
	 //out output file
	 outfile.open(outfilename,fstream::out);
	if(!outfile.is_open()) {
		cout<<"\nERROR: output_file_name not found!\n";
	    cout <<"Usage: prog4 [input_file_name] [output_file_name]"<<endl;
		return 0;
		}
	
	// read input file into linked list
	while(!infile.eof()) {
	 infile >> last_name_buffer >> first_name_buffer >> account_no >> balance;
		head = add_to_head(head,last_name_buffer, first_name_buffer, account_no, balance);
	}

	// main menu loop - loop until the user enters a "0" to write output file and exit
	op = 1;
	while(op) {	// check to see if user entered "0" - if so exit loop
		op = menu();
		switch (op) {
			case 1:
				print(head); // case one contains function to print list to the screen 
				break;
			case 2:   // case two prompts user to enter last name and first name , account and balance 
							//creates a new link to linked list , assigns to head. 
				cout<<"Enter new member's last name ?";
				cin >> last_name_buffer;
				cout<<"Enter new member's first name ?";
				cin >> first_name_buffer;
				cout << "Enter new member's account number ?";
				cin >> account_no;
				cout << "Enter new member's balance ?";
				cin >> balance;
				head = add_to_head(head,last_name_buffer, first_name_buffer, account_no, balance);
				break;
			case 3:  //case 3 prompts user to either wanting to delete by account number or by 
						//first and last name.
				cout<<"Delete by account number (0) or name (1)?";
				cin>>pick;
				head= remove_account(head,pick); 
				break;
			case 4:
				balance = 0.0; 
				number = 0;
				//counts the number of members and calculates balance 
				for(current = head; current != NULL; current = current->next) {
					balance += current->balance;
					number++;
				} 
				balance /= (double)number; //calculates average
				if(number==1) //if there is only one member ,singular message,
				{ 
					cout << fixed << "There is "<< number <<" member with a balance of " << (double)balance << endl;
				}
				else if(number==0) //no members , no average 
				{ 
					cout <<"There are no members present, Average Balance not Available!"  << endl;
				}
				else // message for number of members and their average balance 
				cout << fixed << "There are "<< number <<" members with an average balance of " << (double)balance << endl;
		}	// end switch
	}	// end while

	cout<<"Writing output file "<< outfilename << "\n\nProgram exit, Have a Great Day!"<< endl;
	// write output file
	write(outfile, head); 

	// close files
	infile.close();
	outfile.close();
}		/* end main */