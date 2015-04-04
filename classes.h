#include <iostream>
#include <fstream>

using namespace std;


class card{

		public:

			card();// Constructor
			~card();// destructor
			card(const card&);// Copy constructor
			card& operator=(const card&);// Card overloaded assignment operator (used to copy cards from one deck to another, 				e.g., unshuffled to shuffled).

			// Card overloaded extraction operator (used to read in cards from file).
			friend ifstream& operator>>(ifstream&, card&);
			//Card overloaded insertion operator (used to print cards to screen).
			friend ostream& operator<<(ostream&, card&);
			
			// Two card overloaded comparison operators (>, <, >=, <=) - one must be a FRIEND function and one a MEMBER function.
			friend bool operator <=(const card&, const card&);
			bool operator >=(const card&);

		private:

			string suit;//suit, a string (heart, diamond, club, spade; default value = "suit").
			string rank;// rank a string (two , three, ..., ace; default value = "rank").
			string location; // a string (unshuffled, shuffled, [player name], discard, stock; default value = "location").

};


class player{

		public:

			player(); // Constructor 
			~player();// destructor
			void sethand(const card&, int);
			card* gethand()const;
			// Player overloaded extraction operator (used to read in players from file).
			friend ifstream& operator>>(ifstream&, player&);
			// Player overloaded insertion operator (used to print players’ information to screen).
			friend ostream& operator<<(ostream&, player&);

		private:

  			string name; // name, a string (default value = "first last").
			card* hand; // hand, a card pointer to an array of 5 cards.
			float bet; // bet, a float (default value = 0.0).


};
