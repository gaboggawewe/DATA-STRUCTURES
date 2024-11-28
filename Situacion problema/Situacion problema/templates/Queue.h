#include <iostream>
using namespace std;

template<typename T>
class Node_Queue {
public:
    T dato;
    Node_Queue<T>* next;
    Node_Queue(T valor) : dato(valor), next(nullptr) {}
    Node_Queue() : next(nullptr) {}
};

template<typename T>
class Queue {
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}
    
    ~Queue() {
        while (head) {
            Dequeue();
        }
    }

    bool Enqueue(T valor) {
        Node_Queue<T>* nuevo = new(nothrow) Node_Queue<T>(valor);
        if (!nuevo) {
            return false;
        }
        if (!head) {
            head = tail = nuevo;
        } else {
            tail->next = nuevo;
            tail = nuevo;
        }
        size++;
        return true;
    }

    T Dequeue() {
        if (!head) {
            throw runtime_error("La queue esta vacia.");
        }
        Node_Queue<T>* tmp = head;
        T retorno = head->dato;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete tmp;
        size--;
        return retorno;
    }

    void printQueue() const {
        Node_Queue<T>* actual = head;
        while (actual) {
            cout << actual->dato << " ";
            actual = actual->next;
        }
        cout << endl;
    }

    T peek() const {
        if (!head) {
            throw runtime_error("La queue esta vacia.");
        }
        return (head->dato);
    }

    bool is_empty() const {
        return head == nullptr;
    }

    int Size() const {
        return size;
    }

private:
    Node_Queue<T>* head;
    Node_Queue<T>* tail;
    int size;
};