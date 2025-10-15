#include <ostream>

template <typename T> 
class Node {
    public:
        T data;
	Node<T>* next;
	Node(T data_) : data(data_), next(nullptr) {}
	Node(T data_, Node<T>* next){
		this->data = data_;
		this->next = next;
	}
	
	friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
		Node* newNode = new Node(NULL);
		newNode = node;
		while(newNode->next != nullptr){
			out << newNode->data << " ";
			newNode = newNode->next;
		}
		out << newNode <<"\n";
		return out;
	}
    
};
