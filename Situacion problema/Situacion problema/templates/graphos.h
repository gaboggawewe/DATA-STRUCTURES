#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "template_doble_ligadas.h"

using namespace std;

template <typename T>
class Vertex{
public:
    T data;
    Double_list<unsigned int> edges;
    bool visited;
    Vertex() {
    }
    Vertex(T data){
        this->data = data;
        visited = false;
    }
    ~Vertex(){
    }
};

template <typename T>
class Graph{
public:
    Graph(){
        size = 0;
        graph = nullptr;
    }
    ~Graph(){
        deleteGraph();
    }

    bool createGraph(unsigned int size){
        if(size == 0 || graph){
            return false;
        }
        graph = new(nothrow) Vertex<T>[size];
        if (!graph){
            return false;
        }
        this->size = size;
        return true;
    }

    void deleteGraph(){
        if (graph){
            delete[] graph;
            graph = nullptr;
            size = 0;
        }
    }

    bool setVertex(unsigned int vertex, T info) {
        graph[vertex].data = info;
        return true;
    }

    T getVertexData(unsigned int vertex) {
        return graph[vertex].data;
    }

    bool insertEdge(unsigned int origin, unsigned int destination){
        if (!graph){
            return false;
        }
        if (origin < size && destination < size){
            if(!graph[origin].edges.busqueda(destination)){
                if (graph[origin].edges.insertarFinal(destination)){
                    return true;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool deleteEdge(unsigned int origin, unsigned int destination){
        if (!graph){
            return false;
        }
        if (origin < size && destination < size){
            if (graph[origin].edges.busqueda(destination)){
                if (graph[origin].edges.borrarElemento(destination)){
                    return true;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    void print(){
        for(unsigned int i = 0; i < size; i++){
            cout << i << ": ";
            graph[i].edges.printListaBeg();
        }
        cout << endl;
    }

    void printEdges(unsigned int i) {
        graph[i].edges.printListaBeg();
        cout << endl;
    }

    bool loadFile(string filename) {
        ifstream        file(filename);
        string          line;
        unsigned int vertex = 0, nSize = 0;

        if (!file.is_open()) {
            cerr << "Could not open file " << filename << endl;
            return false;
        }
        if (!getline(file, line)) {
            cout << "No header" << endl;
            file.close();
            return false;
        }
        if (line != "Grafo") {
            file.close();
            return false;
        }
        if (!getline(file, line)) {
            cout << "There is no size for the graph" << endl;
            file.close();
            return false;
        }
        if (!checkNum(line)) {
            cout << "The size is not a numeric value" << endl;
            file.close();
            return false;
        }
        nSize = stoi(line);
        if (nSize <= 0) {
            cout << "Size not valid" << endl;
            file.close();
            return false;
        }
        deleteGraph();
        if (!createGraph(nSize)) {
            cout << "Graph could not be created" << endl;
            file.close();
            return false;
        }
        for (vertex = 0; vertex < size; vertex++) {
            if (!getline(file, line)) {
                file.close();
                return false;
            }
            if (line.length()) {
                stringstream ss(line);
                string cell;
                while (getline(ss, cell, ' ')) {
                    int destination = 0;
                    if (!checkNum(cell)) {
                        file.close();
                        return false;
                    }
                    destination = stoi(cell);
                    if (!insertEdge(vertex, destination)) {
                        file.close();
                        return false;
                    }
                }
            }
        }
        file.close();
        return true;
    }
    void DFS_recursive(unsigned int vertex) {
        graph[vertex].visited = true;
        cout << vertex << " ";
        Node_DL<unsigned int>* actual;
        actual = graph[vertex].edges.head;
        while (actual) {
            if (!graph[*actual].visited) {
                DFS_recursive();
            }
            actual = actual->next;
        }
    }

    unsigned int getSize() {
        return size;
    }


private:
    Vertex<T>* graph;
    unsigned int size;

    bool checkNum(string str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
};