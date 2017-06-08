/*Word Jumble
 *THis is game that takes a jumble word
 *and user guesses the word to win 
 */
 
 #include <iostream>
 #include <string>
 #include <cstdlib>
 #include <ctime>
 
 using namespace std;
 
 int main()
 {
		enum fields{WORD, HINT, NUM_FIELDS};
		const int NUM_WORDS = 5;
		const string WORDS[NUM_WORDS][NUM_FIELDS]=
		{
			{"wall", "Do you feel you're banging your head against something?"},
			{"glasses","These might help you see the answer."},
			{"labored","Going slowly, is it?"},
			{"persistent","Keep at it."},
			{"jumble","It's what the game is all about."}
		};
		
		srand(static_cast<unsigned int>(time(0)));
		int choice =(rand() % NUM_WORDS);
		string theWord= WORDS[choice][WORD]; // word to guess
		string theHint= WORDS[choice][HINT]; // hint of word
		
		//jumbling the word 
		string jumble= theWord; // jumbled version of word
		int length = jumble.size();
		for(int i=0;i< length;++i)
		{
			int index1=(rand() % length);
			int index2=(rand() % length);
			char temp = jumble[index1];
			jumble[index1]=jumble[index2];
			jumble[index2]=temp;
		}
		
		//  Welcoming the player
		cout<<"\t\tWelcome to the Word Jumble!\n\n";
		cout<<"Unscramble the letters to make a word. \n";
		cout<<"Enter 'hint' for a hint.\n";
		cout<<"Enter 'quit' to quit the game.\n\n";
		cout<<"The Jumble is: "<< jumble;
		
		string guess;
		cout<<"\n\nYour Guess: ";
		cin>> guess;
		
		//enter the game loop
		while((guess!= theWord)&&(guess != "quit"))
		{
			if(guess== "hint")
			{
				cout<<theHint;
			}
			else
			{
				cout<<"Sorry, that's not it.";
			}
			
			cout<<"\n\nYour Guess: ";
			cin>>guess;
		}
		
		//saying Goodbye to the user
		if(guess==theWord)
		{
			cout<<"\nThat's it! You Guessed it!\n";
		}
		
		cout<<"\nThanks for Playing,\n";
		
		return 0;

 }