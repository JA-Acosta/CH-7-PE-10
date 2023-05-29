// JAAR
// 05/29/2023
// C++ Primer Plus 6th Ed
// CH 7 Program Ex 10
// Version 7
 
// Updates:
// +tolower function
// +getFileName funciton

// Future goals:
// TODO: is it possible to extract print to a function?
// update potential pointers to references where possible.
// intake a .txt and calculate the answers for the expressions.

// Potential Use cases/errors:

// ------------------------------ Prompt---------------------------------------
// Design a function that calculates the solution for various arguments using
// a function calculate that is a pointer to other functions.
// 
// !Optional
// Create an array of pointers to add()-style function and use a loop to
// successively apply calculate to a series of functions.
// ------------------------------ Prompt---------------------------------------


// Headers:
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

// Global Constants and Structures:
struct solutions
{
	double x;
	double y;
	double sum;
	double multiply;
	double subtract;
	double divide;
};


// Prototypes:
double calculate(double x, double y, double (*ptr_f)(double x, double y));
// Adds two numbers passed as arguments and returns the value.
inline double add(double x, double y) { return x + y; };
// multiplies two numbers passed as arguments and returns the value.
inline double multiply(double x, double y) { return x * y; };
// subtracts the second number from the first number and returns the value.
inline double subtract(double x, double y){return x - y;};
// divides the first number by the second number and returns the value.
inline double divide(double x, double y){return x / y;};
bool userInput(double* x, double* y);
void printSolutions(const solutions* inputs);
void getFileName(ifstream& file);
string tolower(string word);

int main()
{
	ofstream pout( "Solutions.txt" );
	ifstream file;
	solutions inputs;
	int input_count = 1;
	cout << "Enter consecutive pairs of numbers and I will calculate the solution"
		" for their summation, multiplication, division, and subtraction.\n";
	cout << "\tNote: For the subtraction and division function, the first value will be "
		"acted on by the second value.\n" << endl;
	cout << "To terminate the program input a non-numerical value for either"
		" x or y.\n";

	pout << "Below Are all of the solutions for the pairs you inputted.\n";
	while (userInput(&inputs.x, &inputs.y))
	{
		inputs.sum = calculate(inputs.x, inputs.y, add);
		inputs.multiply = calculate(inputs.x, inputs.y, multiply);
		inputs.subtract = calculate(inputs.x, inputs.y, subtract);
		inputs.divide = calculate(inputs.x, inputs.y, divide);
		printSolutions(&inputs);
		pout << input_count++ << ".\tSOLUTIONS:\n";
		pout << inputs.x << " + " << inputs.y << " = " << inputs.sum << "\n";
		pout << inputs.x << " * " << inputs.y << " = " << inputs.multiply << "\n";
		pout << inputs.x << " - " << inputs.y << " = " << inputs.subtract << "\n";
		pout << inputs.x << " / " << inputs.y << " = " << inputs.divide << "\n\n";	
	}

	while (!cin)
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
	}

	string userResponse;
	do
	{
		cout << "Do you have a file you want to evaluate? (yes/no): ";
		getline(cin, userResponse);
		userResponse = tolower(userResponse);
	} while (userResponse != "yes" && userResponse != "no");

	if (userResponse == "yes")
	{
		getFileName(file);
		
	}
	pout << "DONE";
	cout << "DONE";

}

// Calculates the answer
// Param: double x, double y, double * ptr_f
// Return: double
double calculate(double x, double y, double (*ptr_f)(double x, double y))
{
	return ptr_f(x, y);
}

// Asks the user for two values and if the user doesn't enter a valid number
// will return false otherwise returns true.
// !assume the user won't input a line
// Param: double x, double y
// Return bool
bool userInput(double* x, double* y)
{
	cout << "\tEnter a value for x : ";
	if (!(cin >> *x))
		return false;
	cout << "\tEnter a value for y : ";
	if (!(cin >> *y))
		return false;
	return true;
}

// Prints the solution for each operation to the console for the user to see.
// Param: const solutions* inputs
// TODO: update with pointer
void printSolutions( const solutions* inputs )
{
	cout << "\nSOLUTIONS:\n";
	cout << inputs->x << " + " << inputs->y << " = " << inputs->sum << "\n";
	cout << inputs->x << " * " << inputs->y << " = " << inputs->multiply << "\n";
	cout << inputs->x << " - " << inputs->y << " = " << inputs->subtract << "\n";
	cout << inputs->x << " / " << inputs->y << " = " << inputs->divide << "\n\n";
}


// Asks the user for a file name and verifies that the file exists.
// !Assume the user input file will have pairs separated by a comma.
// Return: string input
void getFileName(ifstream &file)
{
	string input;
	do
	{
		cout << "Input the name of the file: ";
		getline(cin, input);
		file.open(input);
	} while (!file);

}

// Evaluates each letter in a string and converts it to lowercase.
// Param: string word
// return: string word
string tolower(string word)
{
	for (int i = 0; i < word.size(); i++)
	{
		if (!isalpha(word.at(i)))
		{
			continue;
		}
		word.at(i) = tolower(word.at(i));
	}
	return word;
}