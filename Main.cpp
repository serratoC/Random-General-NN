// General NN Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Node.h"
#include "Functions.h"
#include <list>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
using namespace std;

list<Node> createLayer(int);
list<Node> calculateInput(list<Node>, list<Node>);
list<Node> calculateOutput(list<Node>);

int main()
{
	srand(time(NULL));

	vector<list<Node>> NN;
	list<Node> temp;
	int layers, nodes, count = 1;
	int size[10];

	//randomly creates NN with UP TO 3 HIDDEN LAYERS
	layers = rand() % 3 + 3;

	cout << "Enter number of nodes for first layer: ";
	cin >> nodes;
	cout << endl;

	//Randomly create UP TO 5 LEVELS for each hidden layer
	for (int i = 0; i < layers; i++)
	{
		if (i == layers - 1)
			nodes = size[0];

		temp = createLayer(nodes);
		NN.push_back(temp);
		size[i] = nodes;

		nodes = rand() % 5 + 1;
	}

	//creates weights for each layer	i- counter for each layer
	for (int i = 0; i < layers - 1; i++)
	{
		//it is iterator for each node
		for (list<Node>::iterator it = NN[i].begin(); it != NN[i].end(); it++)
		{
			(*it).createWeights(NN[i + 1].size());
		}
	}

	//user enters input for nodes in layer 1
	for (list<Node>::iterator it = NN[0].begin(); it != NN[0].end(); it++)
	{
		double in;
		cout << "Enter input for Node " << count << ": ";
		cin >> in;
		(*it).Input(in);
		(*it).Output(in);
		count++;
	}
	cout << endl;

	//calculates inputs of 2nd layer
	NN[1] = calculateInput(NN[0], NN[1]);

	//performs calculations for the rest of NN
	for (int i = 1; i < NN.size() - 1; i++)
	{
		NN[i] = calculateOutput(NN[i]);

		NN[i + 1] = calculateInput(NN[i], NN[i + 1]);
	}

	//calculates the output of final layer
	NN[NN.size() - 1] = calculateOutput(NN[NN.size() - 1]);


	//Outputs results
	cout << "There were " << layers << " layers in the NN\n\n";
	for (int i = 0; i < layers; i++)
		cout << "Layer " << i + 1 << " had " << size[i] << " node(s)\n";

	cout << endl << endl;
	count = 1;

	for (list<Node>::iterator it = NN[layers - 1].begin(); it != NN[layers - 1].end(); it++)
	{
		cout << "Node " << count << ": " << (*it).getOut() << endl;
		count++;
	}
	cout << "\n\nDetails of NN:\n";


	//Displays general info of NN
	//Shows Input, Ouput, and Weights for each Node in each Layer
	for (int i = 0; i < layers; i++)
	{
		cout << "Layer " << i + 1 << endl;
		for (list<Node>::iterator it = NN[i].begin(); it != NN[i].end(); it++)
		{
			(*it).Display();
		}
	}

	return 0;
}

/*
@pre	a list of Node exist
@post	a layer of nodes are created based on input
@param	n - number of nodes to be initialized in layer
@return	head - the list containing the initialized list of nodes
*/
list<Node> createLayer(int n)
{
	list<Node> head;
	Node temp;

	for (int i = 0; i < n; i++)
	{
		head.push_back(temp);
	}

	return head;
}

/*
@pre	a list of nodes exist
@post	the inputs of layer2 are calculated
@param	layer1 - list of nodes for current layer
@param	layer2 - list of nodes that input will be calculated for
@return	layer2 - new layer2 that contains new inputs
*/
list<Node> calculateInput(list<Node> layer1, list<Node> layer2)
{
	double temp = 0;
	int i = 1;


	for (list<Node>::iterator it = layer2.begin(); it != layer2.end(); it++)
	{
		temp = 0;

		for (list<Node>::iterator j = layer1.begin(); j != layer1.end(); j++)
		{
			temp += (*j).getOut() * (*j).getWeight(i);
		}

		(*it).Input(temp);
		i++;
	}

	return layer2;
}


/*
@pre	a list of nodes are initialized
@post	outputs are calculated for nodes in layer
@param	layer - list of nodes that will be put through function
@return	layer - new layer that contains calculated outputs
*/
list<Node> calculateOutput(list<Node> layer)
{
	for (list<Node>::iterator it = layer.begin(); it != layer.end(); it++)
	{
		(*it).Output(randomFunc((*it).getIn()));
	}

	return layer;
}
