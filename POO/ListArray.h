#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <ostream>
#include <iostream>

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
	public:
		ListArray() : n(0), max(MINSIZE) {
			arr = new T[MINSIZE]; 
		}

		~ListArray(){
			delete[] arr;
		}

		T operator[](int pos) const {
			if (pos < 0 || pos > n - 1) throw std::out_of_range("Fuera de intervalo\n");
			return arr[pos];
		}

		int size() const {
			return n;
		}

		void resize(int newSize) {
                    if(newSize > MINSIZE){
                        if (max > newSize){
                            T* newArr = new T[newSize];
                            for (int i = 0; i < n; i++) {
                                newArr[i] = arr[i];
                            }
                            delete[] arr;
                            arr = newArr;
                            max = newSize;
			    		n = newSize;
                        }
                        if (max < newSize){
                            T* newArr = new T[newSize];
                            for (int i = 0; i < n; i++) {
                                newArr[i] = arr[i];
                            }
                            delete[] arr;
                            arr = newArr;
                            max = newSize;
                        }
                    }
                    else throw std::length_error("New size must be greater than MINSIZE");
                }

                void insert(int pos, T e){
                        // Si nos dan un dato fuera del rango, lanzamos excepcion.
                        if (pos < 0 || pos > size()){
                                throw std::out_of_range("Index out of range");
                        }
                        // Si estámos en al máximo, agrandamos con resize()
                        if (n == max){
                                resize(max + 10);
                        }
                        for (int i = n; i > pos; i--){
                        arr[i] = arr[i - 1];
                        }
                        arr[pos] = e;
                        n++;
                }


		void append(T e){
			if (n < max){
				arr[n] = e;
				n++;
			}
			else{
				resize(max + 10);
				arr[n] = e;
				n++;
			}
		}

		void prepend(T e){
			if (n < max){
				for (int i = n; i > 0; --i){
					arr[i] = arr[i - 1];
				}
				arr[0] = e;
				n++;
			}
			else{
				resize(max + 10);
				for (int i = n; i > 0; --i){
                                    arr[i] = arr[i - 1];
                                }
                                arr[0] = e;
                                n++;
			}
		}

		T remove(int pos){
			if (pos < 0 || pos > n - 1) throw std::out_of_range("Fuera de intervalo\n");
			if (n < max/2 && max/4 >= MINSIZE){
				resize(max/2);
			}
			if (pos < 0 || pos > n - 1){
			       	throw std::out_of_range("Fuera de intervalo\n");
			}
			T e = arr[pos];
			if (pos == n - 1){
			       	arr[pos] = T();
				n--;
			}
			else{
				for (int i = pos; i < n - 1; i++){
					arr[i] = arr[i + 1];
				}
				arr[n - 1] = T();
				n--;
			}
			return e;
		}

		 T get (int pos){
			if (pos < 0 || pos > n - 1) throw std::out_of_range("Fuera de intervalo\n");
			return arr[pos];
		}

		int search (T e){
			int cont = 0;
			while ( arr[cont] != e && cont < n){
				cont++;
			}
			if (cont == n) return -1;
			else return cont;
		}

		bool empty() const {
			return n == 0;
		}

		friend std::ostream& operator<<(std::ostream& out, const ListArray<T> &list){
			int n = list.size();
			for (int i = 0; i < n; i++){
				out << list.arr[i] << " ";
			}
			return out;
		}


}; 

#endif
			

