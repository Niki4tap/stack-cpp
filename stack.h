
#ifndef STACK_H
#define STACK_H
#include <optional>
#include <cstddef>

template<typename T>
class stack {
private:
	T* start = nullptr;
	T* end = nullptr;
	T* occupied = nullptr;
	size_t bump_size;
public:
	void push(T val);
	std::optional<T> pop();
	void realloc();
	size_t size();
	size_t occupied_size();
	bool empty();

	stack();
	stack(size_t size);
	stack(size_t size, size_t bump_size);

	~stack();
};

#include "stack.cpp"
#endif
