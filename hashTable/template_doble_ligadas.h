#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node_DL {
public:
	T dato;
	Node_DL<T>* previous;
	Node_DL<T>* next;
	Node_DL(T info) {
		dato = info;
		next = nullptr;
		previous = nullptr;
	}
};

template <typename T>
class Double_list {
private:
	Node_DL<T>* head;
	Node_DL<T>* tail;
public:
	Double_list() {
		head = nullptr;
		tail = nullptr;
	}
	~Double_list() {
		deleteLista();
	}

	void printListaBeg() {
		Node_DL<T>* tmp = head;
		while (tmp) {
			cout << tmp->dato << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void printListaEnd() {
		Node_DL<T>* tmp = tail;
		while (tmp) {
			cout << tmp->dato << " ";
			tmp = tmp->previous;
		}
		cout << endl;
	}

	bool insertarFinal(T dato) {
		Node_DL<T>* tmp = nullptr, * nuevo = nullptr;
		nuevo = new(nothrow) Node_DL<T>(dato);
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
		Node_DL<T>* tmp = nullptr, * nuevo = nullptr;
		nuevo = new(nothrow) Node_DL<T>(dato);
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
		Node_DL<T>* actual = head;
		while (actual) {
			Node_DL<T>* temp = actual->next;
			delete actual;
			actual = temp;
		}
		head = nullptr;
		tail = nullptr;
	}

	bool busqueda(T dato) {
		Node_DL<T>* tmp = head;
		while (tmp) {
			if (tmp->dato == dato) {
				return true;
			}
			tmp = tmp->next;
		}
		return false;
	}

	bool borrarElemento(T dato) {
		Node_DL<T>* tmp = head;
		while (tmp) {
			if (tmp->dato == dato) {
				if (tmp->previous) {
					tmp->previous->next = tmp->next;
				}
				else {
					head = tmp->next;
				}
				if (tmp->next) {
					tmp->next->previous = tmp->previous;
				}
				else {
					tail = tmp->previous;
				}
				delete tmp;
				return true;
			}
			tmp = tmp->next;
		}
		return false;
	}

	class iterator {
	private:
		Node_DL<T>* current;
	public:
		iterator() {
			current = nullptr;
		}

		iterator(Node_DL<T>* ptr) {
			current = ptr;
		}

		T& operator*() {
			return current->dato;
		}

		iterator& operator++() {
			if (current) {
				current = current->next;
			}
			return *this;
		}

		bool operator==(const iterator& other) const {
			return current == other.current;
		}

		bool operator!=(const iterator& other) const {
			return current != other.current;
		}
	};

	iterator begin() {
		return iterator(head);
	}

	iterator end() {
		return iterator(nullptr);
	}
};