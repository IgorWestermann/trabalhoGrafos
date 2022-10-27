#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "graph.h"
#include "Edge.h"
using namespace std;

Graph loadGraph(string path, bool isDirected, bool isWeighted) {
    Node n1, n2;
    Graph g;

    ifstream fs(path);
    int numberOfVertex;
    int id_1, id_2, weight;

    if (fs >> numberOfVertex) {
        cout << "Graph added: " << endl;
        while (fs >> id_1 >> id_2 >> weight) {
            cout << id_1 << " " << id_2 << " " << weight << endl;
            n1.setID(id_1);
            n2.setID(id_2);
            g.addVertex(n1);
            g.addVertex(n2);
            g.addEdge(n1, n2, weight);
        }
    }
    cout << "------" << endl;
    cout << "is Directed?: " << isDirected << " - " << "is Weighted?: " << isWeighted << endl;

    return g;
}

int main(int argc, char* argv[])
{

    int option;
    Graph g;


    do {
        cout << "What operation do you want to perform? " << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Load Graph" << endl;
        cout << "2. Print Graph" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option) {
        case 0:

            break;

        case 1:
            g = loadGraph("teste.txt", argv[1], argv[2]);
            
            break;

        case 2:
            cout << "Print Graph Operation -" << endl;
            g.printGraph();
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }
        cout << endl;

    } while (option != 0);



    return 0;
}

