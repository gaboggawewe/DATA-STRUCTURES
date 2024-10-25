#pragma once
#include <iostream>
using namespace std;

template <typename T>
class NodeDoble {
public:
	T dato;
	NodeDoble<T>* previous;
	NodeDoble<T>* next;
	NodeDoble(T info) {
		dato = info;
		next = nullptr;
		previous = nullptr;
	}
};

template <typename T>
class Double_list {
private:
	NodeDoble<T>* head;
	NodeDoble<T>* tail;
public:
	Double_list() {
		head = nullptr;
		tail = nullptr;
	}
	~Double_list() {
		deleteLista();
	}

	void printListaBeg() {
		NodeDoble<T>* tmp = head;
		while (tmp) {
			cout << tmp->dato << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void printListaEnd() {
		NodeDoble<T>* tmp = tail;
		while (tmp) {
			cout << tmp->dato << " ";
			tmp = tmp->previous;
		}
		cout << endl;
	}

	bool insertarFinal(T dato) {
		NodeDoble<T>* tmp = nullptr, * nuevo = nullptr;
		nuevo = new(nothrow) NodeDoble<T>(dato);
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

	bool insertInOrder(T value) {
		NodeDoble<T>* newNode = nullptr;
		newNode = new (nothrow) NodeDoble<T>(value);

		if (!newNode) {
			return false;
		}

		newNode->next = nullptr;

		if (!head) {
			head = tail = newNode;
			return true;
		}

		if (value < head->dato) {
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
			return true;
		}

		NodeDoble<T>* current = head;
		while (current->next && current->next->dato < value) {
			current = current->next;
		}

		newNode->next = current->next;
		newNode->previous = current;

		if (current->next) {
			current->next->previous = newNode;
		}
		else {
			tail = newNode;
		}

		current->next = newNode;
		return true;
	}

	bool insertarInicio(T dato) {
		NodeDoble<T>* tmp = nullptr, * nuevo = nullptr;
		nuevo = new(nothrow) NodeDoble<T>(dato);
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
		NodeDoble<T>* actual = head;
		while (actual) {
			NodeDoble<T>* temp = actual->next;
			delete actual;
			actual = temp;
		}
		head = nullptr;
		tail = nullptr;
	}

};