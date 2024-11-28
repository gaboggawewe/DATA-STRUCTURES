#include <iostream>
using namespace std;

template<typename T>
class Node_Stack {
public:
    T dato;
    Node_Stack<T>* next;
    Node_Stack(T valor) {
        dato = valor;
        next = nullptr;
    }
};

template<typename T>
class Stack {
public:
    Stack() {
        top = nullptr;
        size = 0;
    }
    ~Stack() {
        while (top) {
            pop();
        }
    }
    bool push(T valor) {
        Node_Stack<T>* nuevo;
        nuevo = new(nothrow) Node_Stack<T>(valor);
        if (!nuevo) {
            return false;
        }
        if (!top) {
            top = nuevo;
            size++;
            return true;
        }
        nuevo->next = top;
        top = nuevo;
        size++;
        return true;
    }

    T pop() {
        Node_Stack<T>* actual;
        T retorno;
        if (!top) {
            throw runtime_error("El stack esta vacio.");
        }
        actual = top;
        retorno = top->dato;
        top = top->next;
        delete actual;
        return retorno;
    }

    void printStack() {
        Node_Stack<T>* actual;
        actual = top;
        while (actual) {
            cout << actual->dato << " ";
            actual = actual->next;
        }
        cout << endl;
    }

    T peek() {
        if (!top) {
            throw runtime_error("El stack esta vacio.");
        }
        return top->dato;
    }

    bool is_empty() {
        if (!top) {
            cout << "La lista no existe" << endl;
            return false;
        }
        return true;
    }

    int Size() {
        return size;
    }

    T *getTop(){
        if(!top){
            return nullptr;
        }
        return &top->dato;
    }

private:
    Node_Stack<T>* top;
    int size;
};
