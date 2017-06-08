/*Guess My Number
 *A Computer Generated Number is made
 *The User has to guess it 
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand(int (time(0)));
	
	int secretNumber =rand()%100+1; //Generates Secret Number between 1 -100
	int tries=0;
	int guess;
	
	cout<<"\tWelcome to the Guessing Game!!\n"<<endl;
	
	do{
	     cout<< "\tType in Your Guess = ";
		 cin>>guess;
		 ++tries;
		if(guess<secretNumber){
			cout <<"\t"<< guess <<" is too Low!!\n"<< endl;
		}
		else if(guess>secretNumber){
			cout <<"\t"<< guess <<" is too High!!\n"<< endl;
		}
		else if(guess==secretNumber){
			cout<<"\tGood JOB! You guess it!! The Secret Number is = " << secretNumber<<"\n\n\tIt took you "<<tries<<" tries\n"<<endl;
		}
	}while(guess!=secretNumber);

return 0;

}

  