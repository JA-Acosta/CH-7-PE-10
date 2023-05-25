// JAAR
// 05/25/2023
// C++ Primer Plus 6th Ed
// CH 7 Program Ex 10
// Version 2
 
// Updates:
// +calculate function
// +add function
// +divide function
// +subtract function
// +multiply function

// Future goals:
// print out the question and will then print out the solution.

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


// Prototypes:
double calculate(double x, double y, double* ptr_f(double x, double y));
double add(double x, double y);
double multiply(double x, double y);
double subtract(double x, double y);
double divide(double x, double y);

int main()
{
}

// Calculates the answer
// Param: double x, double y, double * ptr_f
// Return: double
double calculate(double x, double y, double* ptr_f(double x, double y))
{
	return *ptr_f(x, y);
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
