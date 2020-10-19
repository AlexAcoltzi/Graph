#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Graph<string> grafo;
    string node;
    string nodeDestination;
    int distancia;
    int opc;

    do
    {

        cout << "\t\t\t Maps\n";
        cout << "1. Crear Grafo\n";
        cout << "2. Agregar Nodo\n";
        cout << "3. Agregar Nodo y conectar\n";
        cout << "4. Agregar coneccion entre nodos\n";
        cout << "5. Eliminar Nodo\n";
        cout << "6. Eliminr una coneccion\n";
        cout << "7. Imprimir Grafo\n";
        cout << "8. Calcular camino mas corto\n";
        cout << "9. Verificar si hay trafico\n";
        cout << "0. Salir\n";
        cin >> opc;
        switch (opc)
        {
        case 1:
            system("cls");
            cout << "Ingresa el Nodo Principal\n";
            cin >> node;
            grafo.CreateGraph(node);
            break;
        case 2:
            system("cls");
            cout << "Ingrese el nodo a agregar\n";
            cin >> node;
            grafo.AddNodeSimple(node);
            break;
        case 3:
            system("cls");
            cout << "ingrese el nodo a agregar\n";
            cin >> node;
            cout << "ingrese el nodo destino\n";
            cin >> nodeDestination;
            cout << "ingresa la distancia\n";
            cin >> distancia;
            grafo.AddNode(node,nodeDestination,distancia);
            break;
        case 4:
            system("cls");
            cout << "Ingrese el nodo de Origen\n";
            cin >> node;
            cout << "Ingrese el nodo destino\n";
            cin >> nodeDestination;
            cout << "Ingrese la distancia entre los nodos\n";
            cin >> distancia;
            grafo.AddEdgeP(node,nodeDestination,distancia);
            break;
        case 5:
            system("cls");
            cout << "Ingrese El nodo a eliminar\n";
            cin >> node;
            grafo.DeleteNode(node);
            break;
        case 6:
            system("cls");
            cout << "Ingrese el Nodo de Origin\n";
            cin >> node;
            cout << "Ingrese la distacia\n";
            cin >> distancia;
            grafo.DeleteEdge(node,distancia);
            break;
        case 7:
            system("cls");
            grafo.PrintGraph();
            break;
        case 8:
            system("cls");
            cout << "Ingrese el nodo de origen\n";
            cin >> node;
            cout << "Ingrese el nodo de desrino\n";
            cin >> nodeDestination;
            grafo.DijkstratWayFromTo(node,nodeDestination);
            break;
        case 9:
            system("cls");
            cout << "Espere mientras calculamos el trafico\n";
            grafo.CalculateTrafic();
            grafo.PrintGraph();
            break;
        }

    }while(opc != 0);


    return 0;
}
