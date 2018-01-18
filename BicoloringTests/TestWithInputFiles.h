#pragma once
#include <string>
#include "Bicoloring.h"
#include <fstream>

using namespace std;

void TestWithFiles(string inputFile, string outputFile)
{
	ifstream infile(inputFile);
	ofstream outputfile;
	outputfile.open(outputFile);
	bool running = true;
	while (running)
	{
		auto graph = new BicoloringGraph();
		graph->InitGraph(true);
		int nvertices;
		infile >> nvertices;
		if (nvertices == 0) break;
		graph->m_g->nvertices = nvertices;
		graph->InitSearch();
		int nedges;
		infile >> nedges;
		while (nedges > 0)
		{
			int x, y;
			infile >> x >> y;
			graph->InsertEdge(x, y, true);
			nedges--;
		}
		graph->TwoColor();
		if (graph->bipartate)
		{
			outputfile << "BICOLORABLE." << endl;
		}
		else
		{
			outputfile << "NOT BICOLORABLE." << endl;
		}
		delete graph;
	}
}
