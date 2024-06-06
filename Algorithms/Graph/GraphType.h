#ifndef GRAPHTYPE_H_INCLUDED
#define GRAPHTYPE_H_INCLUDED

#include "StackType.h"
#include "QueueType.h"

template <class VertexType>
class GraphType
{
    public:
        GraphType();
        GraphType(int maxV);
        ~GraphType();
        void MakeEmpty();
        bool IsEmpty();
        bool IsFull();
        void AddVertex(VertexType);
        void AddEdge(VertexType, VertexType, int);
        int WeightIs(VertexType, VertexType);
        void GetToVertices(VertexType, QueueType<VertexType> &);
        void ClearMarks();
        void MarkVertex(VertexType);
        bool IsMarked(VertexType);
        void DepthFirstSearch(VertexType, VertexType);
        int BreadthFirstSearch(VertexType, VertexType);
        int OutDegree(VertexType v);
        bool FoundEdge(VertexType u, VertexType v);
        void Print();

    private:
        int numVertices;
        int maxVertices;
        VertexType *vertices;
        int **edges;
        bool *marks;
};
#endif // GRAPHTYPE_H_INCLUDED