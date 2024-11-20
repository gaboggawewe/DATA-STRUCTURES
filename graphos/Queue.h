#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T dato;
    Node<T>* next;
    Node(T valor) : dato(valor), next(nullptr) {}
    Node() : next(nullptr) {}
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
        Node<T>* nuevo = new(nothrow) Node<T>(valor);
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
        Node<T>* tmp = head;
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
        Node<T>* actual = head;
        while (actual) {
            cout << actual->dato << " ";
            actual = actual->next;
        }
        cout << endl;
    }

    T* peek() const {
        if (!head) {
            throw runtime_error("La queue esta vacia.");
        }
        return &(head->dato);
    }

    bool is_empty() const {
        return head == nullptr;
    }

    int Size() const {
        return size;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};