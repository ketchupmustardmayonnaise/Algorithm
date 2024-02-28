#pragma once
#include "QueType.h"
const int NULL_EDGE = 0;

template<class VertexType>
class GraphType
{
public:
	GraphType(int maxV);
	~GraphType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void AddVertex(VertexType vertex);
	void AddEdge(VertexType fromVertex, VertexType toVertex, int weight);
	int WeightIs(VertexType fromVertex, VertexType toVertex);
	void GetToVertices(VertexType vertex, QueType<VertexType>& adjvertexQ);
private:
	int numVertices;
	int maxVertices;
	VertexType* vertices;
	int** edges;
	bool* marks;
};