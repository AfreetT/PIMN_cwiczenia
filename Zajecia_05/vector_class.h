#pragma once

#include <memory>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <initializer_list>

template <class T>
class ND_Vector{
private:
	size_t vec_size;
	size_t real_size;
	//T* arr_pntr;
	std::unique_ptr<T[]> arr_pntr;

public:
	ND_Vector();
	ND_Vector(size_t in_size);
	ND_Vector(size_t in_size, T item);
	ND_Vector(std::initializer_list<T> values);
	~ND_Vector();
	const size_t& size() const;
	void push_back(T item);
	void print();
	void print() const;
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

	template <class U>
	friend std::ostream& operator<<(std::ostream& os, const ND_Vector<U>& vec);

	class iterator{
	private:
	    T* data;
	public:
		using iterator_category = std::random_access_iterator_tag;
		using value_type = T;
		using reference = T&;
		using pointer = T*;
		using difference_type = std::ptrdiff_t;

		iterator(T* p){ data = p;}

		reference operator*() const { return *data; }
		pointer operator->() const { return data; }
		iterator& operator++() { ++data; return *this; }
		iterator operator++(int) { iterator tmp(*this); ++tmp; return tmp; }
		bool operator==(const iterator& other) const { return data == other.data; }
		bool operator!=(const iterator& other) const { return data != other.data; }

		iterator& operator--() { --data; return *this; }
		iterator operator--(int) { iterator tmp(*this); --data; return tmp; }
		iterator& operator+=(difference_type n) { data += n; return *this; }
		iterator operator+(difference_type n) const { return iterator(data + n); }
		iterator& operator-=(difference_type n) { data -= n; return *this; }
		iterator operator-(difference_type n) const { return iterator(data - n); }
		reference operator[](difference_type n) const { return data[n]; }

		bool operator<(const iterator& other) const { return data < other.data; }
		bool operator<=(const iterator& other) const { return data <= other.data; }
		bool operator>(const iterator& other) const { return data > other.data; }
		bool operator>=(const iterator& other) const { return data >= other.data; }

	    };

	// iterator begin() { return iterator(arr_pntr); }
    // iterator end() { return iterator(arr_pntr + vec_size); }

	iterator begin() { return iterator(arr_pntr.get()); }
    iterator end() { return iterator(arr_pntr.get() + vec_size); }
};

template <class T>
ND_Vector<T>::ND_Vector(){
	vec_size = 0;
	real_size = 0;
	//arr_pntr = new T[real_size];
	arr_pntr = std::make_unique<T[]>(real_size);
}

template <class T>
ND_Vector<T>::ND_Vector(size_t in_size){
	vec_size = in_size;
	real_size = in_size;

	//arr_pntr = new T[real_size];
	arr_pntr = std::make_unique<T[]>(real_size);
}

template <class T>
ND_Vector<T>::ND_Vector(size_t in_size, T item){
	vec_size = in_size;
	real_size = in_size;

	//arr_pntr = new T[real_size];
	arr_pntr = std::make_unique<T[]>(real_size);

	for (int i = 0; i < vec_size; i++)
	{
		arr_pntr[i] = item;
	}

}

template <class T>
ND_Vector<T>::ND_Vector(std::initializer_list<T> values){
	vec_size = values.size();
	real_size = values.size();

	//arr_pntr = new T[real_size];
	arr_pntr = std::make_unique<T[]>(real_size);

	for (int i = 0; i < vec_size; i++)
	{
		arr_pntr[i] = *(values.begin() + i);
	}

}
template <class T>
ND_Vector<T>::~ND_Vector(){
	//delete[] arr_pntr;
}

template <class T>
const size_t& ND_Vector<T>::size() const{
	return vec_size;
}

template <class T>
T& ND_Vector<T>::operator[](size_t idx){
	if(idx >= vec_size){
		throw std::out_of_range("Index out of range");
	}
	return arr_pntr[idx];
}

template <class T>
const T& ND_Vector<T>::operator[](size_t idx) const{
	if(idx >= vec_size){
		throw std::out_of_range("Index out of range");
	}
	return arr_pntr[idx];
}

template <class T>
void ND_Vector<T>::push_back(T item){

	if(vec_size < real_size){
		arr_pntr[vec_size] = item;
		vec_size++;
	}
	else{

		if(real_size == 0){
			real_size = 1;
		}
		else{
			real_size = 2*real_size;
			std::cout << "New vetor created with size " << real_size << '\n';
		}

		//T* new_arr = new T[real_size];
		std::unique_ptr<T[]> new_arr(new T[real_size]);

		for (int i = 0; i < vec_size; i++)
		{
			new_arr[i] = arr_pntr[i];
		}

		//delete[] arr_pntr;
		//arr_pntr = new_arr;

		//arr_pntr = std::move(new_arr);
		std::swap(arr_pntr, new_arr);

		arr_pntr[vec_size] = item;
		vec_size++;
	}
}


template <class T>
void ND_Vector<T>::print(){
	std::cout << "[ ";
	for (int i = 0; i < vec_size; i++)
	{
		std::cout << arr_pntr[i] << " ";
	}
	std::cout << "]\n";
}

template <class T>
std::ostream& operator<<(std::ostream& os, const ND_Vector<T>& vec){
	os << "[ ";
	for (int i = 0; i < vec.size(); i++)
	{
		os << vec[i] << " ";
	}
	os << "]\n";

	return os;
}

