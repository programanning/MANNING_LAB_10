#include <iostream>
#include <fstream>
#include "classes.h"

using namespace std;

//*********** card class function implementations *********************
card::card()// Constructor
{
	// default suit
	suit = "suit";

	// default rank
	rank = "rank";

	// default location
	location = "location";

}

card::~card()// destructor
{
	// delete suit
	suit = "suit";

	// delete rank
	rank = "rank";

	// delete location
	location = "location";
}


card::card(const card& c)// Copy constructor
{

	// set suit
	suit = c.suit;

	// set rank
	rank = c.rank;

	// set location
	location = c.location;

}


card& card::operator=(const card& c)// Card overloaded assignment operator (used to copy cards from one deck to another, e.g., unshuffled to shuffled).
{
	if( this != &c )
{
		suit = c.suit;
		rank = c.rank;
		location = c.location;
	}

	return *this;
}

// Card overloaded extraction operator (used to read in cards from file).
ifstream& operator>>(ifstream& is, card& c){

	is >> c.suit >> c.rank;

	return is;

}


//Card overloaded insertion operator (used to print cards to screen).
ostream& operator<<(ostream& os, card& c){

	os << c.suit << ", " << c.rank << ", " << c.location << endl;

	return os;

}

int stringToInt(string inString){
	if(inString == "ace")
		return 14;
	else if(inString == "two")
		return 2;
	else if(inString == "three")
		return 3;
	else if(inString == "four")
		return 4;
	else if(inString == "five")
		return 5;
	else if(inString == "six")
		return 6;
	else if(inString == "seven")
		return 7;
	else if(inString == "eight")
		return 8;
	else if(inString == "nine")
		return 9;
	else if(inString == "ten")
		return 10;
	else if(inString == "jack")
		return 11;
	else if(inString == "queen")
		return 12;
	else if(inString == "king")
		return 13;

	//Return default value if no matching string
	else
		return -1;

}

// Two card overloaded comparison operators (>, <, >=, <=) - one must be a FRIEND function and one a MEMBER function.
bool operator <=(const card& lhs, const card& rhs){

	int leftValue = stringToInt(lhs.rank);
	int rightValue = stringToInt(rhs.rank);

	if( leftValue <= rightValue ){
	
		return true;
	}

	return false;
}

bool card::operator >=(const card& rhs){

	int leftValue = stringToInt(rank);
	int rightValue = stringToInt(rhs.rank);

	if( leftValue >= rightValue ){
	
		return true;
	}

	return false;


}


//*********** player class function implementations *********************
player::player() // Constructor 
{
	// default name
	name = "suit";

	// default hand
	hand = new card[5];

	// default bet
	bet = 0.0;

}


player::~player()// destructor
{
	// delete name
	name = "first last";

	// delete hand
	delete []hand;
	hand = NULL;

	// delete bet
	bet = 0.0;


}


void player::sethand(const card& c, int i){

	hand[i] = c;
}


card* player::gethand()const{

	return hand;

}


// Player overloaded extraction operator (used to read in players from file).
ifstream& operator>>(ifstream& is, player& p){

	string first;
	string last;
	is>>first;
	is>>last;
	p.name = first + " " + last;
	return is;


}


// Player overloaded insertion operator (used to print players’ information to screen).
ostream& operator<<(ostream& os, player& p){

	os << endl << "Name : " << p.name << endl << "Hand: " << endl;
	for( int i = 0; i <5 ; i++){
		os << p.hand[i] << endl;
		
	}

 	os << "Bet: " << p.bet << endl;

	return os;
}



