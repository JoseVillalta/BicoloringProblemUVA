#include "stdafx.h"
#include "CppUnitTest.h"
#include "Bicoloring.h"
#include "fstream"
#include "FileCompare.h"
#include "TestWithInputFiles.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BicoloringTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(DebugFile)
		{
			
			TestWithFiles("input.txt", "output.txt");
			bool match = CompareFiles("output.txt", "Expected.txt");
			Assert::AreEqual(true, match);
		}
		TEST_METHOD(DebugFile2)
		{
			TestWithFiles("input2.txt", "output2.txt");
			bool match = CompareFiles("output2.txt", "Expected2.txt");
			Assert::AreEqual(true, match);
		}
		TEST_METHOD(NotBicoloring)
		{
			auto graph = new BicoloringGraph();
			graph->InitGraph(true);
			graph->m_g->nvertices = 5;
			graph->InitSearch();
			graph->InsertEdge(0, 1, false);
			graph->InsertEdge(0, 2, false);
			graph->InsertEdge(0, 3, false);
			graph->InsertEdge(0, 4, false);
			graph->InsertEdge(1, 2, false);
			graph->InsertEdge(1, 3, false);
			graph->InsertEdge(3, 4, false);

			graph->TwoColor();
			Assert::AreEqual(false, graph->bipartate);
			
		}
		TEST_METHOD(NotBicoloring2)
		{
			auto graph = new BicoloringGraph();
			graph->InitGraph(true);
			graph->m_g->nvertices = 3;
			graph->InitSearch();
			graph->InsertEdge(0, 1, false);
			graph->InsertEdge(1, 2, false);
			graph->InsertEdge(2, 0, false);
			
			graph->TwoColor();
			Assert::AreEqual(false, graph->bipartate);
		}
		TEST_METHOD(Bicoloring)
		{
			auto graph = new BicoloringGraph();
			graph->InitGraph(true);
			graph->m_g->nvertices = 3;
			graph->InitSearch();
			graph->InsertEdge(0, 1, false);
			graph->InsertEdge(1, 2, false);

			graph->TwoColor();
			Assert::AreEqual(true, graph->bipartate);
		}
		TEST_METHOD(Bicolorable2)
		{
			auto graph = new BicoloringGraph();
			graph->InitGraph(true);
			graph->m_g->nvertices = 9;
			graph->InitSearch();
			graph->InsertEdge(0, 1, false);
			graph->InsertEdge(0, 2, false);
			graph->InsertEdge(0, 3, false);
			graph->InsertEdge(0, 4, false);
			graph->InsertEdge(0, 5, false);
			graph->InsertEdge(0, 6, false);
			graph->InsertEdge(0, 7, false);
			graph->InsertEdge(0, 8, false);

			graph->TwoColor();
			Assert::AreEqual(true, graph->bipartate);
		}
		TEST_METHOD(Bicolorable3)
		{
			auto graph = new BicoloringGraph();
			graph->InitGraph(true);
			graph->m_g->nvertices = 4;
			graph->InitSearch();
			graph->InsertEdge(0, 1, false);
			graph->InsertEdge(1, 2, false);
			graph->InsertEdge(2, 3, false);
			graph->InsertEdge(0, 3, false);

			graph->TwoColor();
			Assert::AreEqual(true, graph->bipartate);
		}
		TEST_METHOD(DebuggerTest)
		{
			TestWithFiles("input3.txt", "output3.txt");
			bool match = CompareFiles("output3.txt", "Expected3.txt");
			Assert::AreEqual(true, match);
		}
	};
}