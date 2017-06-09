//******************************************************************
// Program #: 7
//
// Programmer: Jose Ramirez
//
// Due Date: NA
//
// EGRE 246, Fall 2014       Instructor: Robert Klenke
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: Parser Class, finds 4 types for id from .log file, State machine
//
// Input: none
//
// Output: none
//
//******************************************************************

#include <string>

#include "parser.h"

using namespace std;

parser::parser()									// constructor
{     
	 // sets up strings to find in incoming characters for the message Type
	 $GPGGA="$GPGGA";		
	 $GPGSA="$GPGSA";
	 $GPRMC="$GPRMC";
	 $GPGSV="$GPGSV";
	id = None;	   	  // set initial id to "None"
	this->name=X; //set initial state of name to "X" 
}
parser::~parser()			// destructor
{
}

//state machine for determining if the message type has been received. 
bool parser::parser_id(char c)
{
	if(id == None && c == $GPGGA[0]) {					// found 1st character which is $
		id = $;									// state of the id is $
	}
	else if(id == $)   //if the state is $ continue 
	{
		if(c == $GPGGA[1])	 //if found the second character ,G1 
			id = G1;					 // state of the machine is G1, 
		else if(c == $GPGGA[0]) {		//else if found the $ again 
			id = $;								// go back to state of $
		}
		else					// didn't find the 1st or 2nd character
			id = None;		// go back to the NONE id
			
	}
	else if(id == G1)  // If the state is at G1 , First G
	{
		if(c == $GPGGA[2])   	// found the P character 
		{		
			id = P;						//Set the state to P 
		}
		else if(c == $GPGGA[0]) {	//else if found the $ again 
			id = $;									// go back to state of $
		}
		else						// didn't find 3rd or 1st character
			id = None;			// go back to the NONE id
	}
//the above state machine is for the first 3 characters in all the Message Types $GP 
//if found all 3 in that sequence we can continue to the rest
	//finding the fourth character 
	else if(id == P)				//if the state is at P 
	{
		if(c == $GPGGA[3]) {		 //The next character is a G 
			id = G2;  //#1 set the id to found the G2 in GPGGA 
		}
		else if(c== $GPRMC[3]){  //but if next next character is an R 
			id=R;  // #2 set the id to found the R In GPRMC
		}
		else if(c == $GPGGA[0]) {	//else if found the $ again 
			id = $;								// go back to state of $
		}
		else												// didn't find 4th or 1st character
			id = None;									// go back to the NONE id
	}

//finding the fourth character for GPGGA, GPGSA, GPGSV
	else if(id == G2)  //#1 if the id is at G2 state
	{
		if(c == $GPGGA[4]) {		//if the next character is a G , found the third G GPGGA
			id = G3;   //#1a sets the id state to G3
		}
		else if(c== $GPGSA[4]){  //if the next character is a S , found S in GPGSA
			id=S1;   // #2a sets the id state to S1
		}
		else if(c== $GPGSV[4]){ // if the next character is a S , found S in GPGSV
			id=S2;   //#3a sets the id state to S2
		}
		else if(c == $GPGGA[0]) {	//else if found the $ again 
			id = $;								// go back to state of $
		}
		else						// didn't find 4th or 1st character
			id = None;			// go back to the NONE id
	}
	
	//This is just for the GPRMC message 
	else if(id == R)  //#2 if the previous state is R 
	{
		if(c == $GPRMC[4]) { //and the next character is M 
			id = M;  //#m set the state to M , for GPRMC
		}
		else if(c == $GPGGA[0]) {	//else if found the $ again 
			id = $;								// go back to state of $
		}
		else						// didn't find 5th or 1st character
			id = None;			// go back to the NONE id
	}
	//for the GPRMC 
	else if(id == M)  //#m if the id state is M 
	{
		if(c == $GPRMC[5]) {  //if the next character found is C 
			name=RMC;           //FOUND GPRMC sets the name to the enum type RMC 
			id=None;					//sets the id back to none to reset state machine 
			return true;			//return true 
		}
		else if(c == $GPGGA[0]) {		//else if found the $ again 
			id = $;								// go back to state of $
		}
		else						// didn't find 6th or 1st character
			id = None;			// go back to the NONE id
		
	}
//this is for the GPGGA scenario 
	else if(id == G3)  //#1a if previous state is third G, G3 in GPGGA 
	{ 
		if(c == $GPGGA[5]) {		//and the next chaacter is equal to A, 
			name = GGA;	//FOUND GPGGA sets the name equal to enumerated type GGA
			id=None;			//resets state machine back to NONE 
			return true;	//return true 
		}
		else if(c == $GPGGA[0]) {	//else if found the $ again 
			id = $;								// go back to state of $
		}
		else									// didn't find 6th or 1st character
			id = None;						// go back to the NONE id
			
	}	
//this is for the GPGSA  and GPGSV scenario 
	else if(id == S1)  //#2a //if the previous state is S1 for the GPGSA 
	{ 
		if(c == $GPGSA[5]) {	 //found A , for A2 state in GPGSA 
			name= GSA;		//FOUND GPGSA sets the name to the enumerated type GSA 
			id=None;				//resets state machine back to NONE 
			return true;		//return true 
		}
		else if(c== $GPGSV[5])	//if the next character is a V for GPGSV 
		{
			name= GSV;		//FOUND GPGSV , sets name to enumerated type GSV 
			id=None;				//resets state machine back to NONE 
			return true;		// returns true 
		}
		else if(c == $GPGGA[0]) {	//else if found the $ again 
			id = $;								// go back to state of $
		}
		else							// didn't find 6th or 1st character
			id = None;				// go back to the NONE id
		
	}	
//this is safe for GPGSV state 
	else if(id == S2)  //#2a //if is S2 state 
	{ 
		if(c == $GPGSV[5]) {	 //if the next character is V 
			name=GSV;		//FOUND GPGSV, sets the name to the enumerated type GSV
			id=None;				//resets state machine id to NONE
			return true;		//returns true . 
		}
		else if(c == $GPGGA[0]) {	//else if found the $ again 
			id = $;								// go back to state of $
		}
		else						// didn't find 6th or 1st character
			id = None;			// go back to the NONE id
	}	

return false;       // WHILE not found the next in sequence return false until one of the above conditions are true. 
}


//returns the message type
string parser::messageType()
{  
	if(name==GGA)
	{
		return GPGGA;
	}
	else if (name==GSA)
	{
		return GPGSA;
	}
	else if (name==RMC)
	{
		return GPRMC;
	}
	else if(name==GSV)
	{
		return GPGSV;
	}
}

//returns the message case for the identifier
string parser::messageCase(string identify)
{  
	if(identify==GPGGA)
	{
		return "GPGGA";
	}
	else if (identify==GPGSA)
	{
		return "GPGSA";
	}
	else if (identify==GPRMC)
	{
		return "GPRMC";
	}
	else if(identify==GPGSV)
	{
		return "GPGSV";
	}
}




