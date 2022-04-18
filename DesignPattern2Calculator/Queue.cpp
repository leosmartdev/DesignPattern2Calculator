template <typename T>
inline
uInt Queue <T>::size (void) const 
{
    // The difference between the head and tail + 1 will give the appropriate number of elements in the queue
    return this->_tail - this->_head + 1;
}

// is_empty
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    // empty if head index has surpassed the tail
    return this->_head > this->_tail;
}

// default constructor
template <typename T>
Queue <T>::Queue (void) : _data (new Array <T>()), _head (0), _tail (-1) 
{
    //...
}

// copy constructor
template <typename T>
Queue <T>::Queue (const Queue & queue) : _data (new Array <T>()), _head (0), _tail (-1) 
{
    // if self assignment, ignore
    if (this == &queue)
        return;

    // mimic data members of input stack (by value!)
    *this->_data = *queue._data;
    this->_head  =  queue._head;
    this->_tail  =  queue._tail;
}

// ~Queue
template <typename T>
Queue <T>::~Queue (void) 
{
    delete this->_data;
}

// operator =
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs) 
{
    // check for self assignment
    if (this == &rhs) {
        return * this;
    }

    // mimic data members of input stack (by value!)
    *this->_data = *rhs._data;
    this->_head  =  rhs._head;
    this->_tail  =  rhs._tail;

    return * this;
}

// enqueue
template <typename T>
void Queue <T>::enqueue(T element) 
{

    // if tail has reached end of array
    if (this->_tail + 1 >= this->_data->size()) {

        // if head is 0 (i.e. queue is full)
        if (this->_head == 0) {

            // resize (1 larger than current size)
            this->_data->resize(this->_data->size() + 1);

        // if head is > 0 (head is never < 0)
        } else {

            // shift elements first where head is 0
            int i = 0, j = this->_head;
            for (; j <= this->_tail; i++, j++)
                this->_data->set(i, this->_data->get(j));

            // re-adjust head and tail markers
            this->_head = 0;
            this->_tail = i - 1;
        }
    }

    // increment tail & add element
    this->_data->set(++this->_tail, element);
}

// dequeue
template <typename T>
T Queue <T>::dequeue() 
{
    // exception if empty
    if (this->is_empty())
        throw Queue <T>::empty_exception();

    // increment head after returning element from front of array
    return this->_data->get(this->_head++);
}

// clear
template <typename T>
void Queue <T>::clear() 
{
    // reset head, tail
    this->_head = 0;
    this->_tail = -1;
}
