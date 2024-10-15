#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node_Mounstro {
public:
	T dato;
	Node_Mounstro<T>* previous;
	Node_Mounstro<T>* next;
	Node_Mounstro(T info) {
		dato = info;
		next = nullptr;
		previous = nullptr;
	}
};

template <typename T>
class Calabozo {
private:
	Node_Mounstro<T>* head;
	Node_Mounstro<T>* tail;
public:
	Calabozo() {
		head = nullptr;
		tail = nullptr;
	}
	~Double_list() {
		deleteLista();
	}

	void printListaBeg() {
		Node_Mounstro<T>* tmp = head;
		while (tmp) {
			cout << tmp->dato << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void printListaEnd() {
		Node_Mounstro<T>* tmp = tail;
		while (tmp) {
			cout << tmp->dato << " ";
			tmp = tmp->previous;
		}
		cout << endl;
	}

	bool insertarFinal(T dato) {
		Node_Mounstro<T>* tmp = nullptr, * nuevo = nullptr;
		nuevo = new(nothrow) Node_Mounstro<T>(dato);
		if (!nuevo) {
			return false;
		}
		nuevo->dato = dato;
		if (!head) {
			head = tail = nuevo;
			return true;
		}
		tmp = tail;
		tail->next = nuevo;
		tail = tail->next;
		tail->previous = tmp;
		return true;
	}

	bool insertarInicio(T dato) {
		Node_Mounstro<T>* tmp = nullptr, * nuevo = nullptr;
		nuevo = new(nothrow) Node_Mounstro<T>(dato);
		if (!nuevo) {
			return false;
		}
		nuevo->dato = dato;
		if (!head) {
			head = tail = nuevo;
			return true;
		}
		tmp = head;
		head = nuevo;
		tmp->previous = head;
		head->next = tmp;
		return true;
	}

	void deleteLista() {
		Node_Mounstro<T>* actual = head;
		while (actual) {
			Node<T>* temp = actual->next;
			delete actual;
			actual = temp;
		}
		head = nullptr;
		tail = nullptr;
	}

};