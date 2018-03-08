#include "stdafx.h"
#include "Node.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

//default constructor
Node::Node() {
	input = 0;
	output = 0;
}

//paramaterized constructor
Node::Node(double in) {
	input = in;
	output = 0;
}

/*
	@pre	Instance of node is initialized
	@post	input of node is changed
	@param	in - new input for node
*/
void Node::Input(double in) {
	input = in;
}

/*
@pre	Instance of node is initialized
@post	output of node is changed
@param	out - new input for node
*/
void Node::Output(double out)
{
	output = out;
}

/*
	@pre	an instance of node is initialized
	@post	input, output, and weights of node are displayed
*/
void Node::Display() {
	cout << "Input: " << input << endl;
	cout << "Output: " << output << endl;
	cout << "Weights: ";

	for (list<double>::iterator it = weights.begin(); it != weights.end(); it++)
	{
		cout << (*it) << " ";
	}

	cout << endl << endl;
}

/*
	@pre	an instance of node is initialized
	@post	list of weights are created for node
	@param	nextLayer - number of nodes in next layer
*/
void Node::createWeights(int nextLayer) {	
	double temp;

	for (int i = 0; i < nextLayer; i++)
	{
		//range -10 to 10 
		temp = rand() % 21 - 10;
		weights.push_back(temp);
	}
}

/*
	@pre	an instance of node is initialized
	@post	number of weights are returned
	@return	number of weights in node
*/
int Node::numWeights() {
	return weights.size();
}

/*
	@pre	an intance of node is initialized
	@post	a specific weight of node is returned
	@param	n - numbered weight in list to be returned
	@return	the nth weight is returned
*/
double Node::getWeight(int n) {
	list<double>::iterator it = weights.begin();
	
	if (n == 1)
		return (*it);

	for (int i = 1; i < n; i++)
	{
		it++;
	}

	return (*it);
}

/*
	@pre	an instance of node is initialized
	@post	input of node is returned
*/
double Node::getIn()
{
	return input;
}

/*
	@pre	an instance of node is initialized
	@post	output of node is returned
*/
double Node::getOut()
{
	return output;
}
