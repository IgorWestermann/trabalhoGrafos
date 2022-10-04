#pragma once
#include <iostream>
#include <list>
#include <unordered_map>
#include <cstring>
#include <vector>
#include "Node.h"
using namespace std;

class Graph
{
//	int V;
//	list<int> *l; // array of list
//
//public:
//	Graph(int V) {
//		this->V = V;
//		l = new list<int>[V];
//
//	}
//
//	void addEdge(int x, int y) {
//		l[x].push_back(y);
//		l[y].push_back(x);
//	}
//
//	void printAdjList() {
//
//		for (int i = 0; i < V; i++)
//		{
//			cout << "Vertex " << i <<"->";
//
//			for (int nbr : l[i]) {
//				cout << nbr << ",";
//			}
//			cout << endl;
//		}
//	}

	//unordered_map<string, list<pair<string, int>>> l;

	//public:
	//	void addEdge(string x, string y, bool bidir, int wt) {
	//		l[x].push_back(make_pair(y, wt));
	//		if (bidir) {
	//			l[y].push_back(make_pair(x, wt));
	//		}
	//	}

	//	void printAdjList() {
	//		for (auto p :l) {
	//			string city = p.first;
	//			list<pair<string, int>> nbrs = p.second;


	//			cout << city << "->";
	//			for (auto nbr : nbrs) {
	//				string dest = nbr.first;
	//				int dist = nbr.second;

	//				cout << dest << " " << dist << ",";
	//			}
	//			cout << endl;
	//		}
	//	}
public:
	vector<Node> vertice;

	bool check_node_id(int n_id) {
		for (int i = 0; i < vertice.size(); i++) {
			if (vertice.at(i).getStateID() == n_id) {
				return true;
			}
		}
		return false;
	}

	void addVertex(Node newVertex) {
		bool check = check_node_id(newVertex.getStateID());

		if (check) {
			cout << "Vertex already exists";
		}
		else {
			vertice.push_back(newVertex);
		}
	}

	Node getNodeID(int node_id) {
		Node temp;
		for (int i = 0; i < vertice.size(); i++)
		{
			temp = vertice.at(i);
			if (temp.getStateID() == node_id) {
				return temp;
			}
		}
	}


	bool check_edge_id(int id_1, int id_2) {
		Node n = getNodeID(id_1);
		list<Edge>e = n.getEdgeList();

		for (auto it : e) {
			if (it.getEdgeDest_id() == id_2) {
				return true;
				break;
			}
		}
		return false;
	}

	void addEdge(Node id_1, Node id_2, int w) {
		bool check_from_node = check_node_id(id_1.getStateID());
		bool check_to_node = check_node_id(id_2.getStateID());

		if (check_from_node && check_to_node) {
			bool chech_edge = check_edge_id(id_1.getStateID(), id_2.getStateID());
			if (chech_edge) {
				cout << "Edge already exists";
			}
			else {
				for (int i = 0; i < vertice.size(); i++)
				{
					if (vertice.at(i).getStateID() == id_1.getStateID()) {
						Edge e(id_2.getStateID(), w);
						vertice.at(i).edgeList.push_back(e);
					}
					else if (vertice.at(i).getStateID() == id_2.getStateID()) {
						Edge e(id_1.getStateID(), w);
						vertice.at(i).edgeList.push_back(e);
					}
				}
				cout << "Edge between " << id_1.getStateID() << " and " << id_2.getStateID() << endl;
			}
		}
		else {
			cout << "Invalid Node ID entered." << endl;
		}
	}

	void printGraph() {
		for (int i = 0; i < vertice.size(); i++) {
			Node temp = vertice.at(i);
			cout << temp.getStateName() << " (" << temp.getStateID() << ") --> ";
			temp.printEdgeList();
		}
		
	}




};

