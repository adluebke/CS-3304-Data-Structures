/*
* Class: CS 3304/section07
* Term: Fall 2016
* Name: Andrew Luebke
* Instructor: Monisha Verma
* Assignment: Lab 6
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>

using namespace std;


double Eval_and_Read(string entry);
// Uses the IsOperator, IsNumber, and Operate functions to evaluate the string
// and return the result.

double Operate(char operation, double operand1, double operand2);
// Takes the given operator and operands, and depending on the operator,
// will divide, multiply, add, or subtract. If there is no operator +,-,/, or *
// then it will return an error and exit.

bool IsOperator(char entry);
// Checks to see if the given element is an operator: +, -, /, or *.

bool IsNumber(char entry);
// // Checks to see if the given element is a valid number: 0-9.

int main(int argc, char** argv)
{
	// Declare string.
	string postFix;

	// Where to enter in any new expression. Needs to be in the same format where operands have spaces between them, otherwise
	// it will be recognized as a two-digit number.
	postFix = "5 4 3 2 + / *";

	// Print the string.
	cout << "The post-fix expression is: \n";
	cout << postFix << endl;

	// Pass postFix string into Eval_and_read function.
	double answer = Eval_and_Read(postFix);
	cout << "The result is: " << answer << endl;

	return 0;
}

double  Eval_and_Read(string entry)
{
	// Declare temporary stack, temp.
	stack<double> temp;

	// Loop through the entry string.
	for (int i = 0; i < entry.length(); i++)
	{
		// Check for spaces to signify a new number.
		if(entry[i] == ' ' || entry[i] == ',')
			continue;

		// Checking if the element is a number.
		else if(IsNumber(entry[i]))
		{
			double operand = 0;

			// Loops through the string and checks for numbers with more than two digits.
			while(i < entry.length() && IsNumber(entry[i]))
			{
				// Converts char to double and multiplies first number by ten, then
				// adds in the second number. Thus creating a two digit number.
				operand = (operand*10) + (entry[i] - '0');
				i++;
			}
			i--;

			// Push the value of operand onto the stack, temp.
			temp.push(operand);
		}

		// Checking if the element is a valid operator.
		else if(IsOperator(entry[i]))
		{
			// Pop two off of the top, then use Operate to calculate the result with the given operator.
			double operand2 = temp.top();
			temp.pop();
			double operand1 = temp.top();
			temp.pop();

			double answer = Operate(entry[i], operand1, operand2);
			temp.push(answer);
		}
	}
	return temp.top();
}

// Return true if the value passed is a valid operator, return false if not.
bool IsOperator(char entry)
{
	if (entry == '+' || entry == '-' || entry == '*' || entry == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Return true if the value passed is a valid number, return false if not.
bool IsNumber(char entry)
{
	if (entry >= '0' && entry <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Use the given operator to perform a mathmatical operation for the two operands.
double Operate(char operation, double operand1, double operand2)
{
	// Check the operation value and perform the operation that matches the passed-in value.
	// Then, return the result.
	switch (operation)
	{
		case '+':
			return operand1 + operand2;
			break;

		case '-':
			return operand1 - operand2;
			break;

		case '*':
			return operand1 * operand2;
			break;

		case '/':
			return operand1 / operand2;
			break;

		// If the passed in value in not a valid operator, print an error and exit.
		default:
			cout << "Expected an operater, but did not receive one!" << endl;
			return -1;
			break;
	}
}
