/************************************************************
** Description: getChoice will return a validated option int.
 * It will validate the input and return the choice.
 * The range of the int must be passed as parameters.
*************************************************************/

#include <iostream>
#include "inputValidation.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int getChoice(int min, int max)
{
	int minumum = min;
	int maximum = max;
	int choice;//for returning
	string goodChoice;//for IV

	do
	{
		std::getline(cin, goodChoice);
		while(!inputValidation(goodChoice,'1'))
		{
			cout << "Error. The only choices are " << min << "-" << max                      << " Choose again." << endl;
			std::getline(cin, goodChoice);
		}	
		choice = std::stoi(goodChoice, NULL, 10);
		//check within range
		if(choice < minumum || choice > maximum)
		{
			cout << "Error. The only choices are " << min << "-" << max                      << " Choose again." << endl;
		}
	
	}while(choice < minumum || choice > maximum);			

	return choice;
}
