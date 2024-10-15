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

    void PrintRecursivoPre(Node *&ptr){
        if (ptr == nullptr){
            return;
        }
        cout << ptr->dato << " ";
        PrintRecursivoPre(ptr->left);
        PrintRecursivoPre(ptr->right);
    }

    void PrintRecursivoPost(Node *&ptr){
        if (ptr == nullptr){
            return;
        }
        PrintRecursivoPost(ptr->left);
        PrintRecursivoPost(ptr->right);
        cout << ptr->dato << " ";
    }

    void borrarNodoRecursivo(Node *&ptr,int dato){
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
                Node* tmp = ptr;
                ptr = ptr->right;
                delete tmp;
            }
            else if (!ptr->right){
                Node* tmp = ptr;
                ptr = ptr->left;
                delete tmp;
            }
            else{
                int sustituto = buscaMinRight(ptr->right);
                ptr->dato = sustituto;
                delete ptr;
                ptr = nullptr; 
            }
        }
    }

    int buscaMinRight(Node *&nodo){
        int minR = nodo->dato;
        Node* temp;
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

    int buscaMinLeft(Node *&nodo){
        int minL = nodo->dato;
        Node* temp;
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
};