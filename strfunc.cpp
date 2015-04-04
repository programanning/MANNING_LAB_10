#include "strfunc.h"

using namespace std;

void strcopy(char* copy, const char* src){
	
	// copy string
	while ( *src )
		{
			*copy = *src;

			copy++;
			src++;
		}
	*copy = '\0';

}

int strlen(const char* str){
	// function variables
	int i=0;
	
	// get length
	while(*str != '\0'){

		str++;
		i++;
	}
		
	return i;
}

bool strcomp(char* one, char* other){

	// compare characters until null
	while(*one==*other){

		if ( *one == '\0' || *other == '\0' )
			break;
 
			one++;
			other++;
	}

   if( *one == '\0' && *other == '\0' )
      return true;

   else
      return false;

}



void strcat(char* dest, char* src){

	while ( *dest )
		dest++;

	*dest = ' ';
	dest++;

	while ( *src )
		{
			*dest = *src;
			src++;
			dest++;
		}

	*dest = '\0';
}
