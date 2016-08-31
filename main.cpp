/*
INSTRUCTIONS

You must use this file as a starter file, failure to use this file and not adhere to the requirements will Severely affect your grade

RESTRICTIONS
1. you may not use global variables
2. you may not use GOTO statements
3. you may not use strings
4. you may NOT read user input using strings

REQUIREMENTS
1. you must use the following function EXACTLY as it is:
void validateUserInput(char *UserInputCharArray, int &strLength);
strLength is an int whose value is the number of characters in the user input

2. you must use the following pointer:
char *UserInputCharArray = nullptr;

3. You MUST read the user input using *UserInputCharArray

4.  You must use the following global constant to declare the size of your pointer:
int const ARRAY_SIZE = 100;

OPTIONS
1. you have the option to declare your own variables, just DON"T violate the restrictions above

*/
#include <iostream>

using namespace std;
//required function prototype
void validateUserInput(char *UserInputCharArray, int &strLength);
void setInputLength(char *userInputArray, int &inputLength);
void displayEvenDigits(char *userInputArray, int inputLength);
void whiteSpaceCheck(char *userInputArray, int &inputLength);
void horizontalLine();
void userWrong();

//required global constant
int const ARRAY_SIZE = 100;

int main()
{
	//required char pointer
	char *UserInputCharArray = nullptr;
	char inputArray[ARRAY_SIZE];
	char single;
	int counter = 0;
	int inputLength;
	char go = 'y';

	//main program loop
	while (go == 'y' || go == 'Y')
	{
		cout << "Enter a positive number: ";
		cin.get(inputArray, ARRAY_SIZE); //input to array,  char limit is ARRAY_SIZE = 100
		cin.ignore();


		UserInputCharArray = inputArray; //pointer points to inputArray which is ARRAY_SIZE = 100

		 //set length program should work with to input user actually types
		setInputLength(UserInputCharArray, inputLength); 

		//checks for white space and non-positive number input
		validateUserInput(UserInputCharArray, inputLength);

		//Shows even digits
		displayEvenDigits(UserInputCharArray, inputLength);

		horizontalLine();
		cout << "\nWould you like to input another number? y/Y\n"
			<< "Anything else to quit\n";
		cin >> go;
		cin.ignore();
		system("cls");
	}

	return 0;
}//end main

//required function implementation
void validateUserInput(char *UserInputCharArray, int &strLength)
{
	int counter = 0;

	//Separate function that checks for white space
	whiteSpaceCheck(UserInputCharArray, strLength);

	//Iterate over user input
	while (counter < strLength && *(UserInputCharArray + counter) != NULL)
	{
		//If user input is not ASCII value 0 - 9, prompt for other input
		//reset counter
		if(*(UserInputCharArray + counter) < 48 || *(UserInputCharArray + counter) > 57)
		{
			userWrong();
			cout << "That is not a positive number. Please try again: ";
			cin.get(UserInputCharArray, ARRAY_SIZE);
			cin.ignore();
			whiteSpaceCheck(UserInputCharArray, strLength); //check again for white space
			setInputLength(UserInputCharArray, strLength);
			counter = 0 - 1; //minus 1 because counter++ after this will set counter back to 0
		}
		counter++;
	}

	//Display user input
	cout << "\nYou have entered: ";
	for (counter = 0; counter < strLength; counter++)
	{
		cout << *(UserInputCharArray + counter);
	}
	cout << endl;
}//end validateUserInput

//Scans array and sets length of actual input
void setInputLength(char *userInputArray, int &inputLength)
{
	int counter = 0;

	while (counter < ARRAY_SIZE && *(userInputArray + counter) != NULL)
	{
		inputLength = counter + 1;
		counter++;
	}
}//end setInputLength

//Display even digits, or cout that there are no even digits
void displayEvenDigits(char *userInputArray, int inputLength)
{
	int counter;
	bool evenDigitsPresent = false;

	//Iterate over user input and check for even digits
	//Flip bool evenDigits to true if even digits are found
	for (counter = 0; counter < inputLength; counter++)
	{
		if (*(userInputArray + counter) % 2 == 0)
		{
			evenDigitsPresent = true;
		}
	}

	//If even digits are present, display them
	if (evenDigitsPresent == true)
	{
		cout << "The even digits are: ";
	}
	for (counter = 0; counter < inputLength; counter++)
	{
		if (*(userInputArray + counter) % 2 == 0)
		{
			cout << userInputArray[counter] << " ";
		}
	}
	cout << endl;

	//If there are no even digits, display such message
	if (evenDigitsPresent == false)
	{
		cout << "There are no even digits to display.\n";
	}
}//end displayEvenDigits

//Check for white space input by user
//Re-prompt for input if white space found
void whiteSpaceCheck(char *userInputArray, int &inputLength)
{
	int counter = 0;

	//Iterate over input, if space or tab found
	//prompt user for new input
	while (counter < ARRAY_SIZE)
	{
		if (userInputArray[counter] == ' ' || userInputArray[counter] == '\t')
		{
			userWrong();
			cout << "Do not input any blank space. Please try again: ";
			cin.get(userInputArray, ARRAY_SIZE);
			cin.ignore();
			setInputLength(userInputArray, inputLength);
			counter = 0 - 1; //minus 1 because counter++ after will set counter back to 0		
		}
		counter++;
	}
}//end whiteSpaceCheck

//*************************
//Functions below are just
//for aesthetic displays
//*************************

void horizontalLine()
{
	char dotBlock = 176;

	cout << endl;
	cout << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock
		<< dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock
		<< dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock
		<< dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock
		<< dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock
		<< dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock << dotBlock
		<< dotBlock << dotBlock << dotBlock;
	cout << endl;
}

void userWrong()
{
	char block = 176;
	/*char slant = 92;
	char square = 254;*/

	cout << endl;
	cout << block << block << block << block << block << block << "  NO  " << block << block << block << block
		<< block << block << block << block << block << block << "  NO  " << block << block 
		<< block << block << block << block << block << block << block << block << block
		<< "  NO  " << block << block << block << block << block << block << endl;
	
}
