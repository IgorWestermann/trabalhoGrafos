#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.h"
#include "Edge.h"
#include "Uniao.h"
#include "Intersecao.h"
#include <unistd.h>
using namespace std;

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

void printProgress(double percentage)
{
    int val = (int)(percentage * 100);
    int lpad = (int)(percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

Graph loadGraph(string path, bool isDirected, bool isWeighted)
{
    Node n1, n2;
    vector<NodeList> nodeList;
    vector<Nodes> nodes;
    float progress = 0.0;

    ifstream fs(path);
    int numberOfVertex;
    int id_1, id_2, weight;

    if (fs >> numberOfVertex)
    {
        cout << "Graph added: " << endl;
        cout << "Loading" << flush;

        while (fs >> id_1 >> id_2 >> weight)
        {

            // sleep(1);
            // cout << "." << flush;
            // sleep(1);
            // cout << "." << flush;
            // sleep(1);
            // cout << "." << flush;
            // sleep(1);
            // cout << "\b\b\b   \b\b\b" << flush;
            // cout << endl;

            n1.setID(id_1);
            n2.setID(id_2);
            nodeList.push_back({n1, n2, weight});
            progress += 0.16; // for demonstration only
        }
        while (progress < 1.0)
        {
            int barWidth = 70;

            std::cout << "[";
            int pos = barWidth * progress;
            for (int i = 0; i < barWidth; ++i)
            {
                if (i < pos)
                    std::cout << "=";
                else if (i == pos)
                    std::cout << ">";
                else
                    std::cout << " ";
            }
            std::cout << "] " << int(progress * 100.0) << " %\r";
            std::cout.flush();
        }
        std::cout << std::endl;
    }
    Graph g1(nodeList);

    cout << "------" << endl;
    cout << "is Directed?: " << isDirected << " - "
         << "is Weighted?: " << isWeighted << endl;
    cout << "------" << endl;
    n1.printEdgeList();
    return g1;
}

int main(int argc, char *argv[])
{

    int option;
    Graph g;
    Graph graphUniao;
    Graph graphIntersecao;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Load Graph" << endl;
        cout << "2. Print Graph" << endl;
        cout << "3. Monta Uniao" << endl;
        cout << "4. Printa Uniao" << endl;
        cout << "5. Monta Intersecao" << endl;
        cout << "6. Printa Intersecao" << endl;
        cout << "0. Exit Program" << endl;
        cout << "0. Exit Program" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option)
        {
        case 0:

            break;

        case 1:
            g = loadGraph(argv[1], argv[2], argv[3]);
            break;

        case 2:
            cout << "Print Graph Operation -" << endl;
            g.printGraph();
            break;

        case 3:
            cout << "Union Graph Operation -" << endl;
            graphUniao = loadGraph("teste2.txt", 0, 0);
            graphUniao.montaUniao(g.nodesList);
            break;
        case 4:
            cout << "Print Union Graph Operation -" << endl;
            graphUniao.printGraphUnion();
            break;
        case 5:
            cout << "Print Union Graph Operation -" << endl;
            graphIntersecao = loadGraph("teste2.txt", 0, 0);
            graphIntersecao.teste(g.nodesList);
            graphIntersecao.montaIntersecao(g.nodesList);
            break;
        case 6:
            cout << "Print Union Graph Operation -" << endl;
            graphIntersecao.printGraphIntersecao();
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }
        cout << endl;

    } while (option != 0);

    return 0;
}
