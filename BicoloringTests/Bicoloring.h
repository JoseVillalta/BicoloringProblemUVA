#pragma once

#include "stdafx.h"
#include "iostream"
#include <queue>
#define MAXV 200
#define COLOR_UNCOLORED -1
#define COLOR_WHITE 0
#define COLOR_BLACK 1

using namespace std;

struct edgenode
{
	int y;
	edgenode * next;
};

typedef struct
{
	edgenode * edges[MAXV];
	int nvertices;
	int nedges;
	bool directed;

}Graph;

class BicoloringGraph
{
public:
	int color[MAXV + 1];
	bool bipartate;
	Graph * m_g;
	bool discovered[MAXV + 1];
	bool processed[MAXV + 1];
	void InitGraph(bool directed)
	{
		m_g = new Graph();
		m_g->directed = directed;
		m_g->nedges = 0;
		m_g->nvertices = 0;
		bipartate = true;

		for (int i = 0; i < MAXV; i++) m_g->edges[i] = nullptr;
	}
	void InsertEdge(int x, int y, bool directed)
	{
		auto edgeNode = new edgenode();
		edgeNode->y = y;
		edgeNode->next = m_g->edges[x];
		m_g->edges[x] = edgeNode;

		if (!directed)
		{
			InsertEdge(y, x, true);
		}
		else
		{
			m_g->nedges++;
		}
	}
	void InitSearch()
	{
		for (int i = 0; i <= m_g->nvertices; i++)
		{
			discovered[i] = false;
			processed[i] = false;
		}
	}

	void BreadthFirstSearch(int start)
	{
		auto q = new queue<int>();
		q->push(start);
		discovered[start] = true;
		int y;

		while (!q->empty())
		{
			int p = q->front();
			q->pop();
			auto edge = m_g->edges[p];
			processed[p] = true;
			while (edge != nullptr)
			{
				y = edge->y;
				if (processed[y] == false || m_g->directed)
				{
					ProcessEdge(p, y);
				}
				if (discovered[y] == false)
				{
					q->push(y);
					discovered[y] = true;

				}
				edge = edge->next;
			}

		}
	}
	void ProcessEdge(int x, int y)
	{
		if (color[x] == color[y])
		{
			bipartate = false;
		}
		color[y] = complement(color[x]);
	}

	int complement(int color)
	{
		if (color == COLOR_BLACK) return COLOR_WHITE;
		if (color == COLOR_WHITE) return COLOR_BLACK;

		return COLOR_UNCOLORED;
	}
	void TwoColor()
	{
		int i;
		for (i = 0; i < m_g->nvertices; i++)
		{
			color[i] = COLOR_UNCOLORED;
		}

		bipartate = true;

		for (i = 0; i < m_g->nvertices; i++)
		{
			if (discovered[i] == false)
			{
				color[i] = COLOR_WHITE;
				BreadthFirstSearch(i);
			}
		}

	}

};