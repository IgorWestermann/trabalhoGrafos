#pragma once
#include <iostream>
#include <list>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <algorithm>
#include "Node.h"
// #include "boost/tuple/tuple.hpp"
using namespace std;

struct NodeList
{
	Node node_1, node_2;
	int weight;
};
struct Nodes
{
	int n1, n2;
};

class Graph
{

public:
	vector<Node> vertice;
	vector<NodeList> nodesList;
	Graph(){

	};
	Graph(vector<NodeList> nodes)
	{
		this->nodesList = nodes;
		criaGraph(nodes);
	}
	void criaGraph(vector<NodeList> nodes)
	{
		for (int i = 0; i < nodes.size(); i++)
		{
			this->addVertex(nodes[i].node_1);
			this->addVertex(nodes[i].node_2);
			this->addEdge(nodes[i].node_1, nodes[i].node_2, nodes[i].weight);
		}
	}
	void montaUniao(vector<NodeList> nodes)
	{
		vector<NodeList> uniaoNodeList;
		uniaoNodeList.insert(uniaoNodeList.end(), nodes.begin(), nodes.end());
		for (int i = 0; i < nodes.size(); i++)
		{
			addVertex(uniaoNodeList[i].node_1);
			addVertex(uniaoNodeList[i].node_2);
			addEdge(uniaoNodeList[i].node_1, uniaoNodeList[i].node_2, uniaoNodeList[i].weight);
		}
	}

	vector<NodeList> teste(vector<NodeList> nodes)
	{
		vector<NodeList> intersecaoList;
		for (int i = 0; i == nodes.size(); i++)
		{
			if (nodes[i].node_1.getStateID() == nodesList[i].node_1.getStateID() && nodes[i].node_2.getStateID() == nodesList[i].node_2.getStateID())
			{
				intersecaoList.push_back(nodes[i]);
			}
		}
		return intersecaoList;
	}

	void montaIntersecao(vector<NodeList> nodes)
	{
		vector<NodeList> intersecaoList = teste(nodes);

		for (int i = 0; i == nodes.size(); i++)
		{
			cout << nodes[i].node_1.getStateID() << " " << nodes[i].node_2.getStateID() << " | " << nodesList[i].node_1.getStateID() << " " << nodesList[i].node_2.getStateID() << endl;
			if (nodesList[i].node_1.getStateID() == intersecaoList[i].node_1.getStateID() && nodesList[i].node_2.getStateID() == intersecaoList[i].node_2.getStateID())
			{
				this->addVertex(intersecaoList[i].node_1);
				this->addVertex(intersecaoList[i].node_2);
				this->addEdge(intersecaoList[i].node_1, intersecaoList[i].node_2, intersecaoList[i].weight);
			}
		}
	}

	bool check_node_id(int n_id)
	{
		for (Node i : vertice)
		{
			if (i.getStateID() == n_id)
			{
				return true;
			}
		}
		return false;
	}

	void addVertex(Node newVertex)
	{
		bool check = check_node_id(newVertex.getStateID());

		if (!check)
		{
			vertice.push_back(newVertex);
		}
	}

	Node getNodeID(int node_id)
	{
		Node temp;
		for (int i = 0; i < vertice.size(); i++)
		{
			temp = vertice.at(i);
			if (temp.getStateID() == node_id)
			{
				return temp;
			}
		}
	}

	bool check_edge_id(int id_1, int id_2)
	{
		Node n = getNodeID(id_1);
		list<Edge> e = n.getEdgeList();

		for (auto it : e)
		{
			if (it.getEdgeDest_id() == id_2)
			{
				return true;
				break;
			}
		}
		return false;
	}

	void addEdge(Node id_1, Node id_2, int w)
	{
		bool check_from_node = check_node_id(id_1.getStateID());
		bool check_to_node = check_node_id(id_2.getStateID());

		if (check_from_node && check_to_node)
		{
			for (int i = 0; i < vertice.size(); i++)
			{
				if (vertice.at(i).getStateID() == id_1.getStateID())
				{
					Edge e(id_2.getStateID(), w);
					vertice.at(i).edgeList.push_back(e);
				}
				else if (vertice.at(i).getStateID() == id_2.getStateID())
				{
					Edge e(id_1.getStateID(), w);
					vertice.at(i).edgeList.push_back(e);
				}
			}
		}
		else
		{
			cout << "Invalid Node ID entered." << endl;
		}
	}

	void printGraph()
	{
		cout << "Graph size: " << nodesList.size() << endl;
		for (int i = 0; i < vertice.size(); i++)
		{
			Node temp = vertice.at(i);
			cout << " (" << temp.getStateID() << ") --> ";
			temp.printEdgeList();
		}
	}

	void printGraphUnion()
	{
		cout << "Graph union size: " << nodesList.size() << endl;
		for (int i = 0; i < vertice.size(); i++)
		{
			Node temp = vertice.at(i);
			cout << " (" << temp.getStateID() << ") --> ";
			temp.printEdgeList();
		}
	}

	void printGraphIntersecao()
	{
		cout << "Graph size: " << nodesList.size() << endl;
		for (int i = 0; i < vertice.size(); i++)
		{
			Node temp = vertice.at(i);
			cout << " (" << temp.getStateID() << ") --> ";
			temp.printEdgeList();
		}
	}

	// Graph montaUniao(Graph g2)
	// {
	// 	nodesList.insert(nodesList.end(), g2.nodesList.begin(), g2.nodesList.end());
	// 	for (int i = 0; i < nodesList.size(); i++)
	// 	{
	// 		g2.addVertex(nodesList[i].node_1);
	// 		g2.addVertex(nodesList[i].node_2);
	// 		g2.addEdge(nodesList[i].node_1, nodesList[i].node_2, nodesList[i].weight);
	// 	}
	// 	return g2;
	// }

	// Graph montaIntersecao(Graph g2)
	// {

	// 	g2.nodesList.clear();
	// 	for (int i = 0; i == g2.nodesList.size(); i++)
	// 	{
	// 		if (vertice[i].state_id == g2.nodesList[i].node_1 && vertice[i].node_2 == g2.nodesList[i].node_2)
	// 		{
	// 			g2.nodesList.push_back(i);
	// 		}

	// 		if (nodesList[i].node_1.getStateID() == g2.nodesList[i].node_1.getStateID() && nodesList[i].node_2.getStateID() == g2.nodesList[i].node_2.getStateID())
	// 		{
	// 			g2.addVertex(g2.nodesList[i].node_1);
	// 			g2.addVertex(g2.nodesList[i].node_2);
	// 			g2.addEdge(g2.nodesList[i].node_1, g2.nodesList[i].node_2, g2.nodesList[i].weight);
	// 		}
	// 	}
	// 	return g2;
	// }
};
