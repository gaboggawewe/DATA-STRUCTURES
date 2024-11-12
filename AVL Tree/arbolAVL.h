#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    T dato;
    int altura;
    Node<T>* right;
    Node<T>* left;
    Node(T valor){
        dato = valor;
        right = nullptr;
        left = nullptr;
    }
};

template <typename T>
class ArbolAVL{
private:
    Node<T>* root;
public:
    ArbolAVL(){
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

    int getAltura(Node<T>* ptr){
        if(!ptr){
            return -1;
        }
        return ptr->altura;
    }

    int revisaBalance(Node<T>* ptr){
        if(!ptr){
            return -1;
        }
        return getAltura(ptr->left) - getAltura(ptr->right);
    }

    void calculaAltura(Node<T>* ptr){
        if(ptr){
            ptr->altura = 1 + max(getAltura(ptr->left),getAltura(ptr->right));
        }
    }

    void balancea(Node<T> *&ptr){
        int balance = revisaBalance(ptr);
        if (balance > 1){
            int FE_left = revisaBalance(ptr->left);
            if (FE_left >= 0){
                ptr = rotacionDerecha(ptr);
            }
            else{
                ptr = rotacionDobleDerecha(ptr);
            }
        }
        if (balance < -1){
            int FE_right = revisaBalance(ptr->right); 
            if (FE_right <= 0){
                ptr = rotacionIzquierda(ptr);
            }
            else{
                ptr = rotacionDobleIzquierda(ptr);
            }
        }
    }

    Node<T>* rotacionDerecha(Node<T>* ptr){
        Node<T>* nuevoRaiz,* tmp;
        nuevoRaiz = ptr->left;
        tmp = ptr->left->right;
        nuevoRaiz->right = ptr;
        ptr->left = tmp;
        
        calculaAltura(ptr);
        calculaAltura(nuevoRaiz);

        return nuevoRaiz;
    }

    Node<T>* rotacionIzquierda(Node<T>* ptr){
        Node<T>* nuevoRaiz,* tmp;
        nuevoRaiz = ptr->right;
        tmp = ptr->right->left;
        nuevoRaiz->left = ptr;
        ptr->right = tmp;

        calculaAltura(ptr);
        calculaAltura(nuevoRaiz);

        return nuevoRaiz;
    }

    Node<T>* rotacionDobleDerecha(Node<T>* ptr){
        ptr->left = (rotacionIzquierda(ptr->left));
        return rotacionDerecha(ptr);
    }

    Node<T>* rotacionDobleIzquierda(Node<T>* nodo){
        ptr->right = (rotacionDerecha(ptr->right));
        return rotacionIzquierda(ptr);
    }


private:
    bool InsertRecursivo(Node<T> **ptr, T valor){
        if (!*ptr){
            *ptr = new(nothrow) Node<T>(valor);
            calculaAltura(*ptr);
            if (!*ptr){
                return false;
            }
            return true;
        }
        if (valor < (*ptr)->dato){
            if(InsertRecursivo(&(*ptr)->left, valor)){
                calculaAltura(*ptr);
                balancea(*ptr);
                return true;
            }
        }
        if (valor > (*ptr)->dato){
            if (InsertRecursivo(&(*ptr)->right, valor)){
                balancea(*ptr);
                return true;
            }
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
        if(ptr){
            calculaAltura(ptr);
            
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

    void borraRecursivo(ArbolAVL<T> **nodo){
        if(*nodo==nullptr){
            return;
        }
        borraRecursivo(&(*nodo)->left);
        borraRecursivo(&(*nodo)->right);
        delete nodo;
        nodo=nullptr;
    }

};