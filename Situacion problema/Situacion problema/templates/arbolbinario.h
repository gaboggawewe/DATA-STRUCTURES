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

    ~ArbolBinario() {
        borraRecursivo(root);
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
        borraRecursivo(root);
        root = nullptr;
        return (root = nullptr);
    }

    T* obtainSelection(unsigned int seleccion) {
        unsigned int contador = 0;
        T* resultado;
        bool encontrado = false;
        obtainSelectionRecursive(root, contador, seleccion, resultado, encontrado);

        if (encontrado) {
            return resultado;
        }
        else {
            throw std::out_of_range("No existe un mounstro en esa posicion");
        }
    }

    int contarNodos() {
        int totalNodos = contarNodosRecursivo(root);
        return totalNodos;
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
        else {

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

    void borraRecursivo(Node<T> *&nodo){
        if(nodo==nullptr){
            return;
        }
        borraRecursivo(nodo->left);
        borraRecursivo(nodo->right);
        delete nodo;
        nodo=nullptr;
    }

    void obtainSelectionRecursive(Node<T>* nodo, unsigned int& contador, unsigned int seleccion, T*& resultado, bool& encontrado) {
        if (nodo == nullptr || encontrado) {
            return;
        }
        obtainSelectionRecursive(nodo->left, contador, seleccion, resultado, encontrado);
        contador++;
        if (contador == seleccion) {
            resultado = &(nodo->dato);
            encontrado = true;
            return;
        }
        obtainSelectionRecursive(nodo->right, contador, seleccion, resultado, encontrado);
    }

    int contarNodosRecursivo(Node<T>* ptr) {
        if (ptr == nullptr) {
            return 0;
        }
        return 1 + contarNodosRecursivo(ptr->left) + contarNodosRecursivo(ptr->right);
    }


};