#include "stack.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>

const size_t DEFAULT_STACK_SIZE = 8;

template<typename T>
std::optional<T> stack<T>::pop() {
	if (this->occupied == this->start) {
		return {};
	}
	this->occupied--;
	return *this->occupied;
}

template<typename T>
void stack<T>::push(T val) {
	if (this->occupied == this->end) {
		this->realloc();
	}
	*this->occupied = val;
	this->occupied++;
}

template<typename T>
void stack<T>::realloc() {
	size_t prev_size = this->occupied_size();
	size_t to_bump_default = this->size();
	T* prev_data = this->start;
	if (this->bump_size != 0)
		this->start = (T*)malloc(prev_size * sizeof(T) + this->bump_size * sizeof(T));
	else
		this->start = (T*)malloc(prev_size * sizeof(T) + to_bump_default * sizeof(T));
	memmove(this->start, prev_data, prev_size * sizeof(T));
	free(prev_data);
	if (this->bump_size != 0)
		this->end = this->start + prev_size + this->bump_size;
	else
		this->end = this->start + prev_size + to_bump_default;
	this->occupied = this->start + prev_size;
}

template<typename T>
size_t stack<T>::size() {
	return this->end - this->start;
}

template<typename T>
size_t stack<T>::occupied_size() {
	return this->occupied - this->start;
}

template<typename T>
bool stack<T>::empty() {
	return this->start == this->occupied;
}

template<typename T>
stack<T>::stack() : bump_size{0} {
	this->start = (T*)malloc(sizeof(T) * DEFAULT_STACK_SIZE);
	this->end = this->start + DEFAULT_STACK_SIZE;
	this->occupied = this->start;
}

template<typename T>
stack<T>::stack(size_t size) : bump_size{0} {
	this->start = (T*)malloc(sizeof(T) * size);
	this->end = this->start + size;
	this->occupied = this->start;
}

template<typename T>
stack<T>::stack(size_t size, size_t bump_size){
	this->start = (T*)malloc(sizeof(T) * size);
	this->end = this->start + size;
	this->occupied = this->start;
	this->bump_size = bump_size;
}

template<typename T>
stack<T>::~stack() {
	free(this->start);
}
