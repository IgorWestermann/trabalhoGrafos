// #include <iostream>
// #include <string>
// #include <list>
// #include "Graph.h"
// #include "Node.h"

// using namespace std;

// class GraphUniao
// {
//     struct NodeList
//     {
//         Node node_1, node_2;
//         int weight;
//     };
//     struct Nodes
//     {
//         int n1, n2;
//     };

// public:
//     vector<Node> vertice;
//     vector<NodeList> nodesList;
//     GraphUniao(){};
//     GraphUniao(Graph nodes)
//     {
//         for (int i = 0; i < nodes.size(); i++)
//         {
//             nodesList.push_back(nodes.nl);
//             addVertex(nodes.nl[i]);
//             addVertex(nodes.nl[i].node_2);
//             addEdge(nodes.nl[i].node_1, nodes.nl[i].node_2, nodes.nl[i].weight);
//         }
//     };

//     GraphUniao montaUniao(Graph g)
//     {
//         nodesList.insert(nodesList.end(), g.nl.begin(), g.nl.end());
//         for (int i = 0; i < nodesList.size(); i++)
//         {
//             g.addVertex(nodesList[i].node_1);
//             g.addVertex(nodesList[i].node_2);
//             g.addEdge(nodesList[i].node_1, nodesList[i].node_2, nodesList[i].weight);
//         }
//         return g;
//     }
//     void printGraphUnion()
//     {
//         cout << "Graph union size: " << nodesList.size() << endl;
//         for (int i = 0; i < vertice.size(); i++)
//         {
//             Node temp = vertice.at(i);
//             cout << " (" << temp.getStateID() << ") --> ";
//             temp.printEdgeList();
//         }
//     }
//     bool check_node_id(int n_id)
//     {
//         for (Node i : vertice)
//         {
//             if (i.getStateID() == n_id)
//             {
//                 return true;
//             }
//         }

//         return false;
//     }

//     void addVertex(Node newVertex)
//     {
//         bool check = check_node_id(newVertex.getStateID());

//         if (!check)
//         {
//             vertice.push_back(newVertex);
//         }
//     }

//     Node getNodeID(int node_id)
//     {
//         Node temp;
//         for (int i = 0; i < vertice.size(); i++)
//         {
//             temp = vertice.at(i);
//             if (temp.getStateID() == node_id)
//             {
//                 return temp;
//             }
//         }
//     }

//     bool check_edge_id(int id_1, int id_2)
//     {
//         Node n = getNodeID(id_1);
//         list<Edge> e = n.getEdgeList();

//         for (auto it : e)
//         {
//             if (it.getEdgeDest_id() == id_2)
//             {
//                 return true;
//                 break;
//             }
//         }
//         return false;
//     }

//     void addEdge(Node id_1, Node id_2, int w)
//     {
//         bool check_from_node = check_node_id(id_1.getStateID());
//         bool check_to_node = check_node_id(id_2.getStateID());

//         if (check_from_node && check_to_node)
//         {
//             for (int i = 0; i < vertice.size(); i++)
//             {
//                 if (vertice.at(i).getStateID() == id_1.getStateID())
//                 {
//                     Edge e(id_2.getStateID(), w);
//                     vertice.at(i).edgeList.push_back(e);
//                 }
//                 else if (vertice.at(i).getStateID() == id_2.getStateID())
//                 {
//                     Edge e(id_1.getStateID(), w);
//                     vertice.at(i).edgeList.push_back(e);
//                 }
//             }
//         }
//         else
//         {
//             cout << "Invalid Node ID entered." << endl;
//         }
//     }
// };