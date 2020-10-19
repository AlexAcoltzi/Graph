#ifndef EDGE_H
#define EDGE_H
#include "Node.h"
template <typename T>
class Edge
{
private:
    int weight;
    Node<T> *NextNode;
    Edge<T> *NextEdge;

public:
    Edge(int);
    template <typename U>
    friend class Graph;
};
template <typename T>
Edge<T>::Edge(int weight)
{
    this->weight = weight;
    NextNode = nullptr;
    NextEdge = nullptr;
}
#endif // EDGE_H
