#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include"Edge.h"
#include"Node.h"
#define max 1000
using namespace std;
template <typename T>
class Graph
{
private:
    Node<T> *First;
    Node<T> *node[max];
    Node<T> *predecessor[max];
    int distance[max];
    bool visited[max];
    int num(Node<T> *);
    void init();
    void DijkstratWayFromTo(Node<T> *, Node<T> *);
    void print(Node<T> *, Node<T> *);

public:
    Graph();
    void AddNode(T, T, int);
    void AddNodeSimple(T);
    void AddEdgeP(T, T, int);
    void CreateGraph(T);
    void DeleteNode(T);
    void DeleteEdge(T,int);
    void PrintGraph();
    void DijkstratWayFromTo(T, T);
    void CalculateTrafic();
};

template <typename T>
Graph<T>::Graph()
{
    First = nullptr;
}
template <typename T>
void Graph<T>::CreateGraph(T Element)
{
    if (First == nullptr)
    {
        First = new Node<T>(Element, max);
    }
    else
    {
        cout << "Ya exite un grafo\n";
    }
}
template <typename T>
void Graph<T>::AddNode(T ElementAdd, T ElementDestination, int weight)
{
    AddNodeSimple(ElementAdd);
    AddEdgeP(ElementAdd, ElementDestination, weight);
}
template <typename T>
void Graph<T>::AddNodeSimple(T Element)
{
    Node<T> *aux = new Node<T>(Element, max);
    Node<T> *auxS = First;
    while (auxS->NextNode != nullptr)
    {
        auxS = auxS->NextNode;
    }
    auxS->NextNode = aux;
    aux->PreviusNode = auxS;
}
template <typename T>
void Graph<T>::AddEdgeP(T ElementOrigin, T ElementDestination, int weight)
{
    Node<T> *auxOrigin = First;
    Edge<T> *auxEdge = new Edge<T>(weight);
    Node<T> *auxDestination = First;
    while (auxOrigin != nullptr && auxOrigin->Object != ElementOrigin)
    {
        auxOrigin = auxOrigin->NextNode;
    }
    while (auxDestination != nullptr && auxDestination->Object != ElementDestination)
    {
        auxDestination = auxDestination->NextNode;
    }
    if (auxOrigin != nullptr && auxDestination != nullptr)
    {
        if (auxOrigin->NextEdge == nullptr)
        {
            auxOrigin->NextEdge = auxEdge;
        }
        else
        {
            Edge<T> *auxEdge2 = auxOrigin->NextEdge;
            while (auxEdge2->NextEdge != nullptr)
            {
                auxEdge2 = auxEdge2->NextEdge;
            }
            auxEdge2->NextEdge = auxEdge;
        }
        auxEdge->NextNode = auxDestination;
    }
    else
    {
        cout << "Uno de los elemento no fue encontrado, vuelva a intentarlo\n";
    }
}
template <typename T>
void Graph<T>::PrintGraph()
{
    Node<T> *aux = First;
    while (aux != nullptr)
    {
        cout << aux->Object;
        if (aux->NextEdge != nullptr)
        {
            Edge<T> *auxEdge = aux->NextEdge;
            int n = 0;
            while (auxEdge != nullptr)
            {
                if (n >= 1)
                {
                    cout << aux->Object;
                    cout << "----(" << auxEdge->weight << ")----";
                    cout << ">" << auxEdge->NextNode->Object << "\n";
                }
                else
                {
                    cout << "----(" << auxEdge->weight << ")----";
                    cout << ">" << auxEdge->NextNode->Object << "\n";
                }
                auxEdge = auxEdge->NextEdge;
                n++;
            }
            cout << "\n";
        }
        else
        {
            cout << "\n";
        }
        aux = aux->NextNode;
    }
}
template <typename T>
void Graph<T>::init()
{
    int i = 0;
    Node<T> *aux = First;
    while (aux != nullptr)
    {
        node[i] = aux;
        predecessor[i] = nullptr;
        distance[i] = max;
        visited[i] = false;
        aux = aux->NextNode;
        i++;
    }
}
template <typename T>
int Graph<T>::num(Node<T> *nodeRef)
{
    int i = 0;
    Node<T> *aux = First;
    while (aux != nullptr)
    {
        if (node[i] == nodeRef)
        {
            return i;
        }
        else
        {
            aux = aux->NextNode;
            i++;
        }
    }
}
template <typename T>
void Graph<T>::DijkstratWayFromTo(T origin, T destino)
{
    Node<T> *nodeOrigin;
    Node<T> *nodeDestination;
    Node<T> *aux = First;
    while (aux != nullptr && aux->Object != origin)
    {
        aux = aux->NextNode;
    }
    if (aux != nullptr)
    {
        nodeOrigin = aux;
    }
    else
    {
        cout << "Origen no encontrado\n";
    }

    aux = First;
    while (aux != nullptr && aux->Object != destino)
    {
        aux = aux->NextNode;
    }
    if (aux != nullptr)
    {
        nodeDestination = aux;
    }
    else
    {
        cout << "destino no encontrado\n";
    }
    DijkstratWayFromTo(nodeOrigin, nodeDestination);
    print(nodeOrigin, nodeDestination);
}
template <typename T>
void Graph<T>::DijkstratWayFromTo(Node<T> *nodeOrigin, Node<T> *Destination)
{
    priority_queue<Node<T> *, deque<Node<T> *>, greater<Node<T> *>> queue;
    init();
    int i, n;
    i = num(nodeOrigin);
    queue.push(nodeOrigin);
    distance[i] = 0;
    Node<T> *aux, *nextNode;
    Edge<T> *auxEdge;
    int peso;
    while (!queue.empty())
    {
        aux = queue.top();
        i = num(aux);
        queue.pop();
        if (visited[i] != true)
        {
            visited[i] = true;
            auxEdge = aux->NextEdge;
            while (auxEdge != nullptr)
            {
                nextNode = auxEdge->NextNode;
                n = num(nextNode);
                peso = auxEdge->weight;
                if (visited[n] != true)
                {
                    if (distance[i] + peso < distance[n])
                    {
                        distance[n] = distance[i] + peso;
                        predecessor[n] = aux;
                        queue.push(auxEdge->NextNode);
                    }
                }
                auxEdge = auxEdge->NextEdge;
            }
        }
    }
}
template <typename T>
void Graph<T>::print(Node<T> *nodeOrigin, Node<T> *nodeDestination)
{
    int i = num(nodeDestination);
    Node<T> *aux, *aux2;
    if (predecessor[i] != nullptr)
    {
        aux = node[i];
        cout << aux->Object << " <--- ";
        if (predecessor[i] != nodeOrigin)
        {
            aux2 = predecessor[i];
            print(nodeOrigin, aux2);
        }
        else
        {
            cout << nodeOrigin->Object;
        }
    }
}
template <typename T>
void Graph<T>::DeleteNode(T Element)
{
    Node<T> *aux = First;
    Edge<T> *auxEdge;
    while(aux != nullptr && aux->Object != Element)
    {
        aux = aux->NextNode;
    }
    if(aux != nullptr)
    {
        aux->PreviusNode->NextNode = aux->NextNode;
        auxEdge = aux->NextEdge;
        while (auxEdge != nullptr)
        {
            auxEdge->NextNode = nullptr;
            auxEdge = auxEdge->NextEdge;
        }
    }
    else
    {
        cout << "No se encontro el elemento a eliminar\n";
    }
}
template  <typename T>
void Graph<T>::DeleteEdge(T Element, int weight)
{
    Node<T> *node = First;
    Edge<T> *EdgeAct, *EdgeAnt;
    while (node != nullptr && node->Object != Element)
    {
        node = node->NextNode;
    }
    if (node != nullptr)
    {
        EdgeAct = node->NextEdge;
        EdgeAnt = node->NextEdge;
        while (EdgeAct != nullptr && EdgeAct->weight != weight)
        {
            EdgeAnt = EdgeAct;
            EdgeAct = EdgeAct->NextEdge;
        }
        if(EdgeAct != nullptr)
        {
            EdgeAnt->NextEdge = EdgeAct->NextEdge;
            EdgeAct->NextNode = nullptr;
        }
    }
}
template <typename T>
void Graph<T>::CalculateTrafic()
{
    int n,s;
    Node<T> *aux = First;
    while(aux!= nullptr)
    {
        Edge<T> *auxEdge = aux->NextEdge;
        while(auxEdge != nullptr)
        {
            srand(time(nullptr));
            s =1+rand() % 3;
            n = rand() % 4;
            if(s == 1)
            {
                auxEdge->weight = auxEdge->weight + n;
            }
            else
            {
                if(auxEdge->weight < n)
                {
                    auxEdge->weight = auxEdge->weight + n;
                }
                else
                {
                    auxEdge->weight = auxEdge->weight - n;
                }
            }
            auxEdge = auxEdge->NextEdge;
        }
        aux = aux->NextNode;
    }
}
#endif // GRAPH_H
