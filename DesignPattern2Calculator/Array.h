////////////////////////////////////////////////////////////////////////////////

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "Basic_Array.h"

typedef unsigned int uInt;

/**
 * @class Array
 * 
 * Template Pattern
 */
template <typename T>
class Array : public Basic_Array <T> {

public:

	// Default constructor.
	Array(void);

	/**
	* Initializing constructor.
	*
	* @param: length        Initial size
	*/
	Array(uInt length);

	/**
	* Initializing constructor.
	*
	* @param: length        Initial size
	* @param: fill          Initial value for each element
	*/
	Array(uInt length, T fill);

	/**
	* Copy constructor
	*
	* @param: arr         The source array.
	*/
	Array(const Array & arr);

	// Destructor.
	~Array(void);

	/**
	* Assignment operation
	*
	* @param: rhs      second-hand side of equal sign
	* @return: Reference to self
	*/
	const Array & operator = (const Array & rhs);

	/**
	* Retrieve the maximum size of the array.
	*
	* @return: The maximum size
	*/
	uInt max_size(void) const;

	/**
	* Set a new size for the array.
	*
	* @param: new_size              New size of the array
	*/
	void resize(uInt new_size);

private:
	// Maximum size of the array.
	uInt _max_size;

	/**
	 * Doubles the current max size until the current size is smaller.
	 *
	 * @param: maximum size
	 * @param: current size
	 * @return: new maximum size
	 */
	uInt size_limit(uInt max, uInt cur);
};

// max_size
template <typename T>
inline
uInt Array <T>::max_size(void) const 
{
	return this->_max_size;
}

#include "Array.cpp"

#endif   // !defined _ARRAY_H_