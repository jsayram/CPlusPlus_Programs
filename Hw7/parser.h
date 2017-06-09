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
// Description: parser class - finds a 3-character sequence in a "stream" 
//              of characters
//
// Input: none
//
// Output: none
//
//******************************************************************

using namespace std;

enum nameType{X,GGA,GSA,RMC,GSV};      //enumerated type for the message type return 
enum find_id{None,$,G1,P,G2,R,M,G3,S1,S2,V,C,A1,A2};  //enumerated type for state machine for each MessageType character. 


#define GPGGA	"$GPGGA" //None,G1,P,G2,G3,A1
#define GPGSA	"$GPGSA" //None,G1,P,G2,S1,A2
#define GPRMC	"$GPRMC" //None,G1,P,R,M,C
#define GPGSV	"$GPGSV" //None,G1,P,G2,S2,V

class parser
{
	private:
		enum find_id id;		// Holds current state of the string id 
		enum nameType name; //enumerated type name for the state machine once found message Type. 
		
		string $GPGGA;      // string to GPGGA
		string $GPGSA;		// string to GPGSA
		string $GPRMC;		// string to GPRMC
		string $GPGSV;		// string to GPGSV
		
	public:	
		parser();                      // Constructor
		~parser();					// Destructor
		bool parser_id(char c);			// Main implementation for the state machine for id
		string messageType();   //identifies what message type it is
		string messageCase(string); //finds the message case and returns it clean with no $ sign. 
};
