#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include "ostream"

template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T>* first;
		int n;

	public:
		ListLinked() : first(nullptr), n(0) {}
		~ListLinked() {
			Node<T>* newNode = new Node(NULL);
			newNode = first;
			while(newNode->next != nullptr){
				Node<T>* todelete = new Node(NULL);
				todelete = newNode;
				newNode = newNode->next;
				delete todelete;
			}
			delete newNode;
		}

		T operator[](int pos){
			if (pos < 0 || pos > n) throw std::out_of_range("Out fo range");
			Node<T>* newNode = new Node(NULL);
			newNode = list.first;
			for (int i = 1; i <= pos; ++i){
				newNode = newNode->next;
			}
			return newNode->data;
		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			Node<T>* newNode = Node(NULL);
			newNode = first;
			while(newNode != nullptr){
				out << newNode->data << " ";
			}
			out << "\n";
			return out;
		}
};

#endif
