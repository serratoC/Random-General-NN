#ifndef _NODE
#define _NODE

#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Node
{
public:
	Node();

	Node(double);

	void Input(double);
	void Output(double);
	void Display();
	void createWeights(int);
	int numWeights();
	double getWeight(int);
	double getIn();
	double getOut();

private:
	double input;
	double output;
	list<double> weights;
};

#endif // !_LAYER
