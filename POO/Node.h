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
		while(node->next != nullptr){
			out << node->data << " ";
			node = node->next;
		}
		out << node <<"\n";
		return out;
	}
    
};
