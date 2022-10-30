// Jacob Greer and Jonathan Wilson - Lab 5 - MST
// This program processes an input graph file and stores it in an output graph file after
// applying MST functionality to it.

#include <iostream>
#include "AMGraph.h"

using namespace std;

int main()
{
    cout << "Jacob Greer and Jonathan Wilson - Lab 5 - MST";
    cout << endl;
    cout << endl;

    // Read in input graph file and 
    unique_ptr<AMGraph> graph = make_unique<AMGraph>("input.graphfile");

    // Print "number of..." dialog, marked by false boolean
    graph->print(false);

    // Output to output graphfile
    graph->write("output.graphfile");

    // Initiate different adjacency matrix graphs with different starting vertice points
    AMGraph* mcst1 = graph->MCST(0);
    AMGraph* mcst2 = graph->MCST(4);
    AMGraph* mcst3 = graph->MCST(2);

    // Write all three different outputs to different graph files
    mcst1->write("mcst1.graphfile");
    mcst2->write("mcst2.graphfile");
    mcst3->write("mcst3.graphfile");

    system("pause");
    return 0;
}
