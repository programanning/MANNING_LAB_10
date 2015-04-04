#include <iostream>
#include <fstream>
#include "strfunc.h"
#include "classes.h"
#include <ctime>
#include <cstdlib>

using namespace std;


int menu();
void read(card* );
void shuffle( card* , card* );
void read(player* , int );
void deal( player*, card*, card*, card*, int );
void printUdeck( card*);
void printSdeck(card*);
void printDiscardStock( card*, card*, int );
void printPlayers(player*, int );
void testfoo(card*);



int main(){

	// intialize main program variables
	char val;
	card* uDeck = new card[52];
	card* sDeck = new card[52];
	card* stock = new card[48];
	card* discard = new card[1];
	player* plist = new player[8];
	int pNum;

	srand(time(NULL));

		// print title
		cout << "Five Card Draw" << endl << endl;

	// menu loop

		do{
			val = menu();

			switch( val ){

				case 1:

					read(uDeck);

					break;

				case 2:

					shuffle( uDeck , sDeck);

					break;

				case 3:
					cout << "How many players? ";
					cin >> pNum;
					cout << endl;

					read(plist , pNum );

					break;


				case 4:

					deal( plist, sDeck, discard, stock, pNum );

					break;

				case 5:

					printUdeck(uDeck);

					break;

				case 6:

					printSdeck(sDeck);

					break;

				case 7:

					printDiscardStock( discard, stock, pNum );

					break;

				case 8:

					printPlayers(plist, pNum );

					break;

				case 9:

					testfoo(uDeck);

					break;

				default:
					
					break;
			}

		}while( val != 10 );

		// delete stuff
		delete []uDeck;
		uDeck = NULL;

		delete []sDeck;
		sDeck = NULL;

		delete []stock;
		stock = NULL;

		delete []discard;
		discard = NULL;


return 0;

}


//*****************************FUNCTION IMPLEMENTATIONS************************************

int menu(){ 

	int choice;

	// print menu with options
	cout << "Menu" << endl << endl; 
	cout << "1. Read Deck from File" << endl; 
	cout << "2. Shuffle Deck" << endl;
	cout << "3. Read players From File" << endl;
	cout << "4. Deal Cards" << endl;
	cout << "5. Print Unshuffled Deck" << endl;
	cout << "6. Print Shuffled Deck" << endl;
	cout << "7. Print Discard and Stock" << endl;
	cout << "8. Print Player List" << endl;
	cout << "9. Testing 1,2,3" << endl;
	cout << "10. Quit" << endl;



	// prompt user for response
	cout << "Enter number of selection: ";
	cin >> choice;

	return choice;
}

void read(card* udeck){

	char* fname = new char[20];
	ifstream fin;

	cout << "Enter file name: " ;
	cin >> fname;

	fin.clear();
	fin.open(fname);

	for( int i = 0; i < 52; i++){

		fin >> udeck[i]; 
	}

	fin.close();

	delete fname;
	fname = NULL;
}

void shuffle( card* udeck, card* sdeck){

	int rand1, rand2;
	card temp;

	// copy unshuffled into shuffled
	for(int i = 0; i < 52; i++){

		sdeck[i] = udeck[i];
	}

	for( int i = 0; i < 100; i++){

		rand1 = rand()%52;
		rand2 = rand()%52;

		temp = sdeck[rand1];
		sdeck[rand1] = sdeck[rand2];
		sdeck[rand2] = temp;	
	}
}

void read(player* plist, int numPlayers){

	char* fname = new char[20];
	ifstream fin;

	cout << "Enter file name: " ;
	cin >> fname;

	fin.clear();
	fin.open(fname);

	for( int i = 0; i < numPlayers; i++){

		fin >> plist[i]; 
	}

	fin.close();

	delete fname;
	fname = NULL;
}


void deal( player* plist, card* sdeck, card* discard, card* stock, int numPlayers){

	int index = 0;
	int numCards = numPlayers*5;

	for( int i = 0; i < 5; i++){

		for( int j = 0; j < numPlayers; j++){

			plist[j].sethand(sdeck[index], i);	

			index++;
		}
	}

	discard[0] = sdeck[index];

	index++;

	for( int i = 0; i < 52 - (numCards+1); i++ ){

		stock[i] = sdeck[index];
		index++;


	}

}


void printUdeck( card* udeck){

	cout << "Unshuffled Deck: " << endl;

	for( int i = 0; i < 52; i++){

		cout << udeck[i];
	
	}

	cout << endl;

}

void printSdeck(card* sdeck){

	cout << "Shuffled Deck: " << endl;

	for( int i = 0; i < 52; i++){

		cout << sdeck[i];
	
	}

	cout << endl;

}

void printDiscardStock( card* discard, card* stock, int numPlayers ){

	int stockSize = 51 - (numPlayers*5);

	cout << "Discard: " << endl <<  discard[0] << endl;

	for( int i = 0; i < stockSize; i++){

		cout << stock[i];

	}

	cout << endl;

}

void printPlayers(player* players, int numPlayers){

	cout << "Players: " << endl;

	for( int i = 0; i < numPlayers; i++){

	cout << players[i];

	}

	cout << endl;

}

void testfoo( card* uDeck){

	int rand1, rand2, rand3, rand4, rand5;
	rand1 = rand()%52;
	rand2 = rand()%52;
	rand3 = rand()%52;
	rand4 = rand()%52;
	rand5 = rand()%52;

	cout << "Card 1: " << uDeck[rand1] << endl;
	cout << "Card 2: " << uDeck[rand2] << endl;

	if( uDeck[rand1] >= uDeck[rand2] ){

		cout << "Card 1 is of greater than or equal value than Card 2" << endl;

	}
	else
		cout << "Card 1 is NOT of greater than or equal value than Card 2" << endl;

	cout << "Card 3: " << uDeck[rand3] << endl;
	cout << "Card 4: " << uDeck[rand4] << endl;

	if( uDeck[rand3] <= uDeck[rand4] ){

		cout << "Card 3 is of less than or equal value than Card 4" << endl;

	}
	else
		cout << "Card 3 is NOT of less than or equal value than Card 4" << endl;


	// copy constructor test
	card testCard(uDeck[rand5]);

	cout << "Card from unshuffled deck: " << uDeck[rand5];
	cout << "Test card made from copy constructor: " << testCard << endl;

}














