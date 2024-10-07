#include <iostream>
using namespace std;

class Node{
public:
    int dato;
    Node* right;
    Node* left;
    Node(){
        dato = 0;
        right = nullptr;
        left = nullptr;
    }
};

class BinaryTree{
private:
    Node* root;
public:
    BinaryTree(){
        root = nullptr;
    }

    bool Insert(int valor){
        Node* actual;
        InsertFunction(*BinaryTree,valor);
    }

    bool InsertFunction(Node **ptr, int valor){
        while((*ptr)->dato != 0){
            if (valor < (*ptr)->dato){
                InsertFunction(*(ptr->left)), valor);
            }
            if (valor > (*ptr)->dato){
                InsertFunction(*(ptr->left),valor);
            }
        }
    }

    bool Search(int valor){
        
    }
};