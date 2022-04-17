
#include <stdexcept>         // for std::out_of_bounds exception

// default length
#define DEFAULT_SIZE 10

// Basic_Array - default constructor
template <typename T>
Basic_Array <T>::Basic_Array(void) : _data(new T[DEFAULT_SIZE]), _cur_size(DEFAULT_SIZE) 
{
	//...
}

// Basic_Array - length constructor
template <typename T>
Basic_Array <T>::Basic_Array(uInt length) : _data(new T[DEFAULT_SIZE]), _cur_size(DEFAULT_SIZE) 
{
	// if length is valid, adjust size
	if (length > 0) {

		delete[] this->_data;
		this->_data = new T[length];

		this->_cur_size = length;
	}
}

// Basic_Array - fill constructor
template <typename T>
Basic_Array <T>::Basic_Array(uInt length, T fill) : _data(new T[DEFAULT_SIZE]), _cur_size(DEFAULT_SIZE) 
{
	// if length is valid, adjust size
	if (length > 0) {

		delete[] this->_data;
		this->_data = new T[length];

		this->_cur_size = length;
	}

	this->fill(fill);
}

// Basic_Array - copy constructor
template <typename T>
Basic_Array <T>::Basic_Array(const Basic_Array & array) : _data(new T[array.size()]), _cur_size(array.size()) 
{
	for (uInt i = 0; i < this->_cur_size; i++) {
		this->_data[i] = array[i];
	}
}

// ~Array
template <typename T>
Basic_Array <T>::~Basic_Array(void) 
{
	delete[] this->_data;
}

// operator []
template <typename T>
T & Basic_Array <T>::operator [] (uInt index) 
{
	// exception if out of bound
	if (index < 0 || index >= this->_cur_size) {
		throw(std::out_of_range("Error: Invalid index"));
	}

	return this->_data[index];
}

// operator []
template <typename T>
const T & Basic_Array <T>::operator [] (uInt index) const 
{
	// exception
	if (index < 0 || index >= this->_cur_size) {
		throw(std::out_of_range("Error: Invalid index"));
	}

	return this->_data[index];
}

// get
template <typename T>
T Basic_Array <T>::get(uInt index) const 
{
	if (index < 0 || index >= this->_cur_size) {
		throw(std::out_of_range("Error: Invalid index"));
	}

	return this->_data[index];
}

// set
template <typename T>
void Basic_Array <T>::set(uInt index, T value) 
{
	if (index < 0 || index >= this->_cur_size) {
		throw(std::out_of_range("Error: Invalid index"));
	}

	this->_data[index] = value;
}

// find (value)
template  <typename T>
int Basic_Array <T>::find(T value) const 
{
	return this->find(value, 0);
}

// find (value, uInt)
template <typename T>
int Basic_Array <T>::find(T value, uInt start) const 
{
	if (start < 0 || start >= this->_cur_size) {
		throw(std::out_of_range("Error: Invalid index"));
	}

	for (uInt i = start; i < this->_cur_size; i++) {

		if (this->_data[i] == value) {
			return i;
		}
	}

	return -1;
}

// operator ==
template <typename T>
bool Basic_Array <T>::operator == (const Basic_Array & rhs) const 
{
	// check for point address
	if (this == &rhs) {
		return true;
	}

	if (rhs.size() != this->size()) {
		return false;
	}

	for (uInt i = 0; i < this->_cur_size; i++) {

		if (this->_data[i] != rhs[i]) {
			return false;
		}
	}

	return true;
}

// operator !=
template <typename T>
bool Basic_Array <T>::operator != (const Basic_Array & rhs) const 
{
	// check for pointer
	if (this == &rhs) {
		return false;
	}

	if (rhs.size() != this->size()) {
		return true;
	}

	for (uInt i = 0; i < this->_cur_size; i++) {

		if (this->_data[i] != rhs[i]) {
			return true;
		}
	}

	return false;
}

// fill array
template <typename T>
void Basic_Array <T>::fill(T value) 
{
	
	for (uInt i = 0; i < this->_cur_size; i++) {
		this->_data[i] = value;
	}
}