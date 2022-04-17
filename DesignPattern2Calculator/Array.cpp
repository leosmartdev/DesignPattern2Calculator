#include <stdexcept>        

// default max length
#define DEFAULT_MAX_SIZE 10

// Array - default constructor
template <typename T>
Array <T>::Array(void) : Basic_Array <T>(), _max_size(DEFAULT_MAX_SIZE) 
{
	delete[] this->_data;
	this->_data = new T[DEFAULT_MAX_SIZE];
	this->_cur_size = 0;
}

// Array - length constructor
template <typename T> 
Array <T>::Array(uInt length) : Basic_Array <T>(DEFAULT_MAX_SIZE), _max_size(DEFAULT_MAX_SIZE) 
{
	// resize
	if (length >= 0)
		this->resize(length);
}

// Array (uInt, value)
template <typename T>
Array <T>::Array(uInt length, T fill) : Basic_Array <T>(DEFAULT_MAX_SIZE), _max_size(DEFAULT_MAX_SIZE) 
{
	// resize
	if (length >= 0)
		this->resize(length);

	
	this->fill(fill);
}

// Array (const Array &)
template <typename T>
Array <T>::Array(const Array & array) : Basic_Array <T>(), _max_size(array.max_size()) 
{
	delete[] this->_data;
	this->_data = new T[array.max_size()];
	this->_cur_size = array.size();

	for (uInt i = 0; i < this->_cur_size; i++) {
		this->_data[i] = array[i];
	}
}

// ~Array
template <typename T>
Array <T>::~Array(void) 
{
	// Basic_Array destructor will be implemented
}

// operator =
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs) 
{
	// check the point address
	if (this == &rhs) {
		return *this;
	}

	delete[] this->_data;

	this->_data = new T[rhs.max_size()];
	this->_cur_size = rhs.size();
	this->_max_size = rhs.max_size();

	for (uInt i = 0; i < this->_cur_size; i++) {
		this->_data[i] = rhs[i];
	}

	return *this;
}

// resize
template <typename T>
void Array <T>::resize(uInt new_size) 
{
	// if new size is less than zero
	if (new_size < 0) {
		return;
	}

	// if new size is larger than max
	if (new_size > this->_max_size) {
		
		int new_max = this->size_limit(this->_max_size, new_size);

		T * tmp = new T[new_max];

		uInt i = 0;
		for (i = 0; i < this->_cur_size; i++) {
			tmp[i] = this->_data[i];
		}

		delete[] this->_data;

		this->_data = tmp;
		this->_cur_size = new_size;
		this->_max_size = new_max;
		return;
	}

	// if new size is different from the current
	if (new_size != this->_cur_size) {
		this->_cur_size = new_size;
	}
}

// size_limit (private)
template <typename T>
uInt Array <T>::size_limit(uInt max, uInt cur) {

	// double the current max size until the new size fits
	uInt new_max = max;
	while (cur > new_max) {
		new_max *= 2;
	}

	return new_max;
}
