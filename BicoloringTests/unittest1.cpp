#include "stdafx.h"
#include "CppUnitTest.h"
#include "Bicoloring.h"
#include "fstream"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BicoloringTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			ifstream infile("input1.txt");
			ofstream outputfile;
			outputfile.open("output.txt");
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
		TEST_METHOD(NotBicoloring)
		{
			auto graph = new BicoloringGraph();
			graph->InitGraph(true);
			graph->m_g->nvertices = 5;
			graph->InitSearch();
			graph->InsertEdge(0, 1, true);
			graph->InsertEdge(0, 2, true);
			graph->InsertEdge(0, 3, true);
			graph->InsertEdge(0, 4, true);
			graph->InsertEdge(1, 2, true);
			graph->InsertEdge(1, 3, true);
			graph->InsertEdge(3, 4, true);

			graph->TwoColor();
			Assert::AreEqual(false, graph->bipartate);
			
		}

	};
}