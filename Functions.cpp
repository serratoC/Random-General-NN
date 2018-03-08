#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <cmath>
#include "Functions.h"
using namespace std;


/*
	@pre	none
	@post	a random function is chosen and in is entered in the function
	@param	in - number to be entered in random function
	@return	the result of in from one of the functions
*/
double randomFunc(double in)
{
	int temp;
	temp = rand() % 3;

	switch (temp)
	{
	case 0:
		in = tanh(in);
		return in;
	case 1:
		in = logistic(in);
		return in;
	case 2:
		in = threshold(in);
		return in;
	default:
		cout << "Either random number was not in range or fell through switch case\n";
		return 0;

	}
}

/*
	@pre	none
	@post	tanh of in is found
	@param	in - number to be put in tanh function
	@return	tanh function of in
*/
double tanh(double in)
{
	double temp;

	temp = (exp(in) - exp(-in)) / (exp(in) + exp(-in));
	return threshold(temp);
}

/*
	@pre	none
	@post	logistic of in is found
	@param	in - number to be put in logistic function
	@return	logistic function of in
*/
double logistic(double in)
{
	double temp;

	temp = exp(in) / (1 + exp(in));
	return threshold(temp);
}

/*
	@pre	none
	@post	in is put through threshold function
	@param	in - number to be put in threshold function
	@return	threshold function of in
*/
double threshold(double in)
{
	if (in < 0)
		return 0;
	else
		return 1;
}