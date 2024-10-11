#include <iostream>
using namespace std;

class Node{
public:
    int dato;
    Node* right;
    Node* left;
    Node(int valor){
        dato = valor;
        right = nullptr;
        left = nullptr;
    }
};

class ArbolBinario{
private:
    Node* root;
public:
    ArbolBinario(){
        root = nullptr;
    }

    bool inserta(int valor){
        return InsertRecursivo(&root,valor);
    }

    void imprimeInOrder(){
        PrintRecursivoOrder(root);
    }

    //bool Search(int valor){
        
    //}

private:
    bool InsertRecursivo(Node **ptr, int valor){
        if (!*ptr){
            *ptr = new(nothrow) Node(valor);
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

    void PrintRecursivoOrder(Node *&ptr){
        if (ptr == nullptr){
            return;
        }
        PrintRecursivoOrder(ptr->left);
        cout << ptr->dato << " ";
        PrintRecursivoOrder(ptr->right);
    }
};