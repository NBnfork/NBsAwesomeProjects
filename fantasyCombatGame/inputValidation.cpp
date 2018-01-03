// To use this inputValidation function. The program will first pass a string literal to check (ie. "232" or "N") and a string of the type of data it should be. For example "1" for integer and  "C" for char. If correct data was entered Boolean will be returned true. String can then be cast to correct type.
// some code for this function come directly from http://www.cplusplus.com/reference/cctype/isdigit/ and /isalpha
#include<iostream>
#include <ctype.h>
#include <string>
#include <vector>
#include "inputValidation.hpp"

using std::string;
using std::vector;


bool inputValidation(string toCheck, char type)

{
	
	bool goodData = false;
//check for press enter error
	if (toCheck.length() == 0)
	{	return goodData; 
	}	
	if (isdigit(type))
	{		
		vector <char> strtoCheck(toCheck.begin(), toCheck.end());
		int i = 0; //counter
		//trying to fix the junk data issue
		while (strtoCheck.size() !=0)
		{
			if (isdigit(strtoCheck[i]))
			{	goodData = true;
				//should stop the check here for a single digit number
				//before the junk is read
				strtoCheck.erase(strtoCheck.begin());
			}
			else 
			{	
				goodData = false;
				return goodData;
			}
			i++;
		}
	}

	if (isalpha(type))
	{		

		vector <char> strtoCheck(toCheck.begin(), toCheck.end());
		int i = 0;
		while (strtoCheck[i]) 
		{
			if (isalpha(strtoCheck[i]))
			{	goodData = true;
			}
			else 
			{	
				goodData = false;
				return goodData;
			}
			i++;
		}
	}
	return goodData;
}

// to cast to an integer. 
// int goodInt = std::stoi (inputName,NULL,10);
// to convert to a char
// char goodChar = str[0];
