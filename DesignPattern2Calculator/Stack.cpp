#include <stdexcept> 

// size
template <typename T>
inline
uInt Stack <T>::size(void) const {

	// top index + 1 is the number of elements
	//  in the stack
	return this->_top + 1;
}

// top
template <typename T>
inline
T Stack <T>::top(void) const {

	// exception if empty
	if (this->is_empty())
		throw Stack <T>::empty_exception();

	// return last element
	return this->_data->get(this->_top);
}

// is_empty
template <typename T>
inline
bool Stack <T>::is_empty(void) const 
{
	// stack empty when top is -1
	return this->_top < 0;
}

template <typename T>
Stack <T>::Stack(void) : _data(new Array<T>()), _top(-1) 
{
	//...
}

// Stack
template <typename T>
Stack <T>::Stack(const Stack & stack) : _data(new Array<T>(stack._data->size())), _top(-1) 
{
	// if self assignment, ignore
	if (this == &stack)
		return;

	*this->_data = *stack._data;
	this->_top = stack._top;
}

// ~Stack
template <typename T>
Stack <T>::~Stack(void) 
{
	delete this->_data;
}

// operator =
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs) 
{
	// check for self assignment
	if (this == &rhs) {
		return *this;
	}

	*this->_data = *rhs._data;
	this->_top = rhs._top;

	return *this;
}

// push
template <typename T>
void Stack <T>::push(T element) 
{
	// Make space in the array:
	// if top has reached end of array
	if (this->size() >= this->_data->size()) {
		this->_data->resize(this->size() + 1);
	}

	// Add element:
	// increment top & add element
	this->_data->set(++this->_top, element);
}

// pop
template <typename T>
void Stack <T>::pop(void) 
{
	// exception if empty
	if (this->is_empty())
		throw Stack <T>::empty_exception();

	this->_top--;
}

// clear
template <typename T>
void Stack <T>::clear(void) 
{
	this->_top = -1;
}
