#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"
#include "Edge.h"
using namespace std;

int main()
{
	//fstream fs;

	//fs.open("teste.txt", ios::in); // read
	//if (fs.is_open()) {
	//	string line;
	//	while (getline(fs, line)) { // store every line in the line var
	//		cout << line << endl;
	//	}
	//	fs.close();

	//}

	//Graph g;
	//g.addEdge("A", "B", true, 20);
	//g.addEdge("B", "D", true, 40);
	//g.addEdge("A", "C", true, 10);
	//g.addEdge("C", "D", true, 40);
	//g.addEdge("A", "D", false, 50);

	//g.printAdjList();

	int option, id_1, id_2, w;
    string s_name;
    Graph g;
    Node n1, n2;

    do {
        cout << "What operation do you want to perform? " << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Add Vertex" << endl;
        cout << "2. Update Vertex" << endl;
        cout << "3. Delete Vertex" << endl;
        cout << "4. Add Edge" << endl;
        cout << "5. Update Edge" << endl;
        cout << "6. Delete Edge" << endl;
        cout << "7. Check if 2 Vertices are Neigbors" << endl;
        cout << "8. Print All Neigbors of a Vertex" << endl;
        cout << "9. Print Graph" << endl;
        cout << "10. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option) {
        case 0:

            break;

        case 1:
            cout << "Add Vertex Operation -" << endl;
            cout << "Enter State ID: ";
            cin >> id_1;
            cout << "Enter State Name: ";
            cin >> s_name;

            n1.setID(id_1);
            n1.setStateName(s_name);
            g.addVertex(n1);

            break;

        case 2:
            cout << "Update Vertex Operation -" << endl;

            break;

        case 3:
            cout << "Delete Vertex Operation -" << endl;

            break;

        case 4:
            cout << "Add Edge Operation -" << endl;

            cout << "Enter origin Node ID: ";
            cin >> id_1;
            n1.setID(id_1);
         
            
            cout << "Enter destination Node ID: ";
            cin >> id_2;
            n2.setID(id_2);

            cout << "Enter wight: ";
            cin >> w;

            g.addEdge(n1, n2, w);

            break;

        case 5:
            cout << "Update Edge Operation -" << endl;

            break;

        case 6:
            cout << "Delete Edge Operation -" << endl;

            break;

        case 7:
            cout << "Check if 2 Vertices are Neigbors -" << endl;
            cout << "Enter ID of Source Vertex(State): ";

            break;

        case 8:
            cout << "Print All Neigbors of a Vertex -" << endl;
            break;

        case 9:
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