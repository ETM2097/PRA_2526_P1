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
			Node<T>* current = first;
			while (current != nullptr) {
				Node<T>* todelete = current;
				current = current->next;
				delete todelete;
			}
		}

		T operator[](int pos){
			if (pos < 0 || pos >= n) throw std::out_of_range("Out of range");
			Node<T>* current = first;
			for (int i = 0; i < pos; ++i){
				current = current->next;
			}
			return current->data;
		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			Node<T>* current = list.first;
			while(current != nullptr){
				out << current->data << " ";
				current = current->next;
			}
			out << "\n";
			return out;
		}

		void insert(int pos, T e){
			if (pos < 0 || pos > n) throw std::out_of_range("Out of range");
			if (pos == 0){
				first = new Node<T>(e, first);
			}
			else{
				Node<T>* current = first;
				for (int i = 0; i < pos - 1; ++i){
					current = current->next;
				}
				current->next = new Node<T>(e, current->next);
			}
			n++;
		}

		void append(T e){
			insert(n, e);
		}

		void prepend(T e){
			insert(0, e);
		}

		T remove(int pos){
			if (pos < 0 || pos >= n) throw std::out_of_range("Out of range");
			Node<T>* todelete;
			T data;
			if (pos == 0){
				todelete = first;
				data = first->data;
				first = first->next;
			}
			else{
				Node<T>* current = first;
				for (int i = 0; i < pos - 1; ++i){
					current = current->next;
				}
				todelete = current->next;
				data = todelete->data;
				current->next = todelete->next;
			}
			delete todelete;
			n--;
			return data;
		}

		T get(int pos){
			if (pos < 0 || pos >= n) throw std::out_of_range("Out of range");
			Node<T>* current = first;
			for (int i = 0; i < pos; ++i){
				current = current->next;
			}
			return current->data;
		}

		int search(T e){
			Node<T>* current = first;
			int pos = 0;
			while (current != nullptr){
				if (current->data == e){
					return pos;
				}
				current = current->next;
				pos++;
			}
			return -1;
		}

		bool empty() const {
			return n == 0;
		}

		int size() const {
			return n;
		}
};

#endif
