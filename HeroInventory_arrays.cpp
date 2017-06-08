/* This is an inventory program 
 *Teaches the notion of arrays
 *Game name: Hero Inventory
 *Demonstrates Arrays
 */
 
#include <iostream>
#include <string>

using namespace std;

int main()
{
		const int MAX_ITEMS =10;
		string inventory[MAX_ITEMS];
	
		int numItems = 0;
		inventory[numItems++] ="Sword"; //populates array with strings 
		inventory[numItems++] ="Armor";
		inventory[numItems++] ="shield";
	
		cout<<"Your Items:\n";    // prints out array 
		for(int i=0;i<numItems;++i)
		{
			cout<<"\t   "<<inventory[i]<<endl;
		}
		
		cout<<"\nYou trade your sword for a battle axe."; // changes an indexed intem in array in this case array[ 0 ]
		inventory[0]= "battle axe";
		cout<< "\nYour items:\n";
		for( int i=0; i < numItems; ++i)
		{
			cout<< inventory[i]<<endl;
		}
		
		cout<<"\nThe item name ' "<<inventory[0]<<" ' has "; // gives the size of string in index array[0] , how many characters it has
		cout<< inventory[0].size() << " Letters in it.\n";
		
		cout<<"\nYou Found a Healing Potion."; // adds another entry to the existing array , but cannot go outside the size of the array MAX_SIZE
		if(numItems < MAX_ITEMS)
		{
			inventory[numItems++]="Healing Potion";
		}
		else
		{
			cout<<"You have too Many items and can't carry another.";
		}
		cout<<"\nYour items: \n";       // prints out the contents of the array at this point. 
		for(int i=0;i<numItems;++i)
		{
			cout<<inventory[i]<<endl;
		}

return 0;
}
 