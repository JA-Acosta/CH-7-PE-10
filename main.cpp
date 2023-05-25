// JAAR
// 05/25/2023
// C++ Primer Plus 6th Ed
// CH 7 Program Ex 10
// Version 4
 
// Updates:
// +printSolutions function
// +struct solutions

// Future goals:
// print the questions and solutions to a txt file.

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
double add(double x, double y);
double multiply(double x, double y);
double subtract(double x, double y);
double divide(double x, double y);
bool userInput(double* x, double* y);
void printSolutions(const solutions* inputs);

int main()
{
	cout << "Enter consecutive pairs of numbers and I will calculate the solution"
		" for their summation, multiplication, division, and subtraction.\n";
	cout << "\tNote: For the subtraction and division function, the first value will be "
		"acted on by the second value.\n" << endl;
	cout << "To terminate the program input a non-numerical value for either"
		" x or y.\n";
	
	solutions inputs;

	while (userInput(&inputs.x, &inputs.y))
	{
		inputs.sum = calculate(inputs.x, inputs.y, add);
		inputs.multiply = calculate(inputs.x, inputs.y, multiply);
		inputs.subtract = calculate(inputs.x, inputs.y, subtract);
		inputs.divide = calculate(inputs.x, inputs.y, divide);
		printSolutions(&inputs);
	}
}

// Calculates the answer
// Param: double x, double y, double * ptr_f
// Return: double
double calculate(double x, double y, double (*ptr_f)(double x, double y))
{
	return ptr_f(x, y);
}

// Adds two numbers and returns the solution.
// Param: double x, double y
// Return: double
double add(double x, double y)
{
	return x + y;
}

// Multiplies two numbers and returns the solution.
// Param: double x, double y
// Return: double
double multiply(double x, double y)
{
	return x * y;
}

// Subtracts the second number passed from the first and returns the solution.
// Param: double x, double y
// Return: double
double subtract(double x, double y)
{
	return x - y;
}

// Divides the first number passed by the second number and returns the solution.
// Param: double x, double y
// Return: double
double divide(double x, double y)
{
	return x / y;
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

void printSolutions(const solutions* inputs)
{
	cout << "\nSOLUTIONS:\n";
	cout << inputs->x << " + " << inputs->y << " = " << inputs->sum << "\n";
	cout << inputs->x << " * " << inputs->y << " = " << inputs->multiply << "\n";
	cout << inputs->x << " - " << inputs->y << " = " << inputs->subtract << "\n";
	cout << inputs->x << " / " << inputs->y << " = " << inputs->divide << "\n\n";
}