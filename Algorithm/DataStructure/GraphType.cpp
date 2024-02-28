#include "GraphType.h"

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
	numVertices = 0;
	maxVertices = maxV;
	vertices = new VertexType[maxV];
	edges = new int[maxV];
	for (int i = 0; i < maxV; i++)
		edges[i] = new int[maxV];
	marks = new bool[maxV];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
	delete[] vertices;
	for (int i = 0; i < maxVertices; i++)
		delete[] edges[i];
	delete[] edges;
	delete[] marks;
}

template<class VertexType>
void GraphType<VertexType>::MakeEmpty()
{}

template<class VertexType>
bool GraphType<VertexType>::IsEmpty() const
{}

template<class VertexType>
bool GraphType<VertexType>::IsFull() const
{}

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
{
	vertices[numVertices] = vertex;

	for (int index = 0; index < numVertices; index++)
	{
		edges[numVertices][index] = NULL_EDGE;
		edges[index][numVertices] = NULL_EDGE;
	}
	numVertices++;
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
{
}

template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex)
{}

template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, QueType<VertexType>& adjvertexQ)
{}