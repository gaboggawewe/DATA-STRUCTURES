# Estructuras de Datos

Este repositorio contiene implementaciones de varias estructuras de datos en C++. Cada estructura de datos está organizada en su propia carpeta y contiene el código fuente, así como ejemplos de uso.

## Contenido

- **Queue**: Implementación de una cola (FIFO).
- **Stack**: Implementación de una pila (LIFO).
- **Graph**: Implementación de un grafo con métodos para BFS y DFS.
- **Double Linked List**: Implementación de una lista doblemente enlazada.

## Estructuras de Datos

### Queue
La clase `Queue` implementa una cola utilizando nodos enlazados. Incluye métodos para encolar (`Enqueue`), desencolar (`Dequeue`), obtener el elemento al frente (`peek`), verificar si la cola está vacía (`is_empty`) y obtener el tamaño de la cola (`Size`).

### Stack
La clase `Stack` implementa una pila utilizando nodos enlazados. Incluye métodos para apilar (`push`), desapilar (`pop`), obtener el elemento en la cima (`peek`), verificar si la pila está vacía (`is_empty`) y obtener el tamaño de la pila (`Size`).

### Graph
La clase `Graph` implementa un grafo utilizando listas de adyacencia. Incluye métodos para agregar vértices y aristas, eliminar aristas, realizar búsquedas en anchura (BFS) y búsquedas en profundidad (DFS).

### Double Linked List
La clase `Double_list` implementa una lista doblemente enlazada. Incluye métodos para insertar al inicio y al final, eliminar elementos, buscar elementos y recorrer la lista desde el inicio y el final.

## Uso

Cada estructura de datos está implementada en su propio archivo de cabecera (`.h`). Para utilizar una estructura de datos, simplemente incluye el archivo de cabecera correspondiente en tu proyecto y crea instancias de las clases según sea necesario.

```cpp
#include "Queue.h"
#include "Stack.h"
#include "Graph.h"
#include "template_doble_ligadas.h"

int main() {
    // Ejemplo de uso de la cola
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    cout << "Frente de la cola: " << *queue.peek() << endl;
    queue.Dequeue();
    queue.printQueue();

    // Ejemplo de uso de la pila
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Cima de la pila: " << stack.peek() << endl;
    stack.pop();
    stack.printStack();

    // Ejemplo de uso del grafo
    Graph<int> graph;
    graph.createGraph(5);
    graph.setVertex(0, 1);
    graph.setVertex(1, 2);
    graph.insertEdge(0, 1);
    graph.print();

    // Ejemplo de uso de la lista doblemente enlazada
    Double_list<int> list;
    list.insertarInicio(1);
    list.insertarFinal(2);
    list.printListaBeg();

    return 0;

    //comentario de prueba de commit.
}