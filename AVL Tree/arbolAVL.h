#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    T dato;
    Node<T>* right;
    Node<T>* left;
    Node(T valor){
        dato = valor;
        right = nullptr;
        left = nullptr;
    }
};

template <typename T>
class ArbolBinario{
private:
    Node<T>* root;
public:
    ArbolBinario(){
        root = nullptr;
    }

    bool inserta(T valor){
        return InsertRecursivo(&root,valor);
    }

    void printInOrder(){
        PrintRecursivoOrder(root);
    }

    void printPreOrder(){
        PrintRecursivoPre(root);
    }

    void printPostOrder(){
        PrintRecursivoPost(root);
    }

    void borrarNodo(int dato){
        borrarNodoRecursivo(root,dato);
    }

    bool borrarArbol(){
        return (&root);
    }

private:
    bool InsertRecursivo(Node<T> **ptr, T valor){
        if (!*ptr){
            *ptr = new(nothrow) Node<T>(valor);
            if (!*ptr){
                return false;
            }
            return true;
        }
        if (valor < (*ptr)->dato){
            return InsertRecursivo(&(*ptr)->left, valor);
        }
        if (valor > (*ptr)->dato){
            return InsertRecursivo(&(*ptr)->right, valor);
        }
        return false;
    }

    void PrintRecursivoOrder(Node<T> *&ptr){
        if (ptr == nullptr){
            return;
        }
        PrintRecursivoOrder(ptr->left);
        cout << ptr->dato << " ";
        PrintRecursivoOrder(ptr->right);
    }

    void PrintRecursivoPre(Node<T> *&ptr){
        if (ptr == nullptr){
            return;
        }
        cout << ptr->dato << " ";
        PrintRecursivoPre(ptr->left);
        PrintRecursivoPre(ptr->right);
    }

    void PrintRecursivoPost(Node<T> *&ptr){
        if (ptr == nullptr){
            return;
        }
        PrintRecursivoPost(ptr->left);
        PrintRecursivoPost(ptr->right);
        cout << ptr->dato << " ";
    }

    void borrarNodoRecursivo(Node<T> *&ptr, T dato){
         if (!ptr){
            return;
        }
        if (dato < ptr->dato){
            borrarNodoRecursivo(ptr->left, dato);
        }
        else if (dato > ptr->dato){
            borrarNodoRecursivo(ptr->right, dato);
        }
        else{
            if (!ptr->left && !ptr->right){
                delete ptr;
                ptr = nullptr;
            }
            else if (!ptr->left){
                Node<T>* tmp = ptr;
                ptr = ptr->right;
                delete tmp;
            }
            else if (!ptr->right){
                Node<T>* tmp = ptr;
                ptr = ptr->left;
                delete tmp;
            }
            else{
                T sustituto = buscaMinRight(ptr->right);
                ptr->dato = sustituto; 
            }
        }
    }

    int buscaMinRight(Node<T> *&nodo){
        int minR = nodo->dato;
        Node<T>* temp;
        while (nodo->right != nullptr)
        {
            temp = nodo;
            minR = nodo->right->dato;
            nodo = nodo->right;
        }
        if (nodo->left){
            temp->right = nodo->left;
        }
        delete nodo;
        return minR;
    }

    int buscaMinLeft(Node<T> *&nodo){
        int minL = nodo->dato;
        Node<T>* temp;
        while (nodo->left != nullptr)
        {
            temp = nodo;
            minL = nodo->left->dato;
            nodo = nodo->left;
        }
        if (nodo->right){
            temp->left = nodo->right;
        }
        delete nodo;
        return minL;
    }

    void borraRecursivo(ArbolBinario<T> **nodo){
        if(*nodo==nullptr){
            return;
        }
        borraRecursivo(&(*nodo)->left);
        borraRecursivo(&(*nodo)->right);
        delete nodo;
        nodo=nullptr;
    }

};