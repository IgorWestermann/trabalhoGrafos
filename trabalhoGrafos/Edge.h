#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class Edge
{
public:
	int edge_dest_id;
	int weight;

	Edge(int d_id, int w) {
		edge_dest_id = d_id;
		weight = w;
	}
	void setEdgeValues(int d_id, int w) {
		edge_dest_id = d_id;
		weight = w;
	}
	void setWeight(int w) {
		weight = w;
	}
	int getEdgeDest_id() {
		return edge_dest_id;
	}
	int getWeight() {
		return weight;
	}
};

