#ifndef NODE_H
#define NODE_H
#include"Edge.h"
template<typename T>
class Edge;
template <typename T>
class Node
{
private:
       T Object;
       int weight;
       Edge<T> *NextEdge;
       Node<T> *NextNode;
       Node<T> *PreviusNode;
public:
       Node(T, int);
       template <typename U>
       friend class Graph;
};
template <typename T>
Node<T>::Node(T Object, int weight)
{
    this->Object = Object;
    this->weight = weight;
    NextEdge = nullptr;
    NextNode = nullptr;
    PreviusNode = nullptr;
}
#endif // NODE_H
