#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Edge.h"

using namespace std;

class Node
{
public:
	int state_id;
	string state_name;

	list<Edge> edgeList;

	Node()
	{
		state_id = 0;
		state_name = "";
	}
	Node(int id, string s_name)
	{
		state_id = id;
		state_name = s_name;
	}
	int getStateID()
	{
		return state_id;
	}
	string getStateName()
	{
		return state_name;
	}
	void setID(int id)
	{
		state_id = id;
		state_name = id;
	}
	void setStateName(string s_name)
	{
		state_name = s_name;
	}
	list<Edge> getEdgeList()
	{
		return edgeList;
	}

	void printEdgeList()
	{
		cout << "[";
		for (auto i : edgeList)
		{
			cout << i.getEdgeDest_id() << "(" << i.getWeight() << ") -- ";
		}
		cout << "]" << endl;
	}
};
