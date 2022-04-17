////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Queue.cpp
//  Date:           09/26/2017
//  Description:    Main implementation for Queue class.
//
////////////////////////////////////////////////////////////////////////////////
//
//  Honor Pledge:
//
//  I pledge that I have neither given nor received any help on this assignment.
//
//  ibsardar
//
////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2017 Copyright Holder All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////

//
// Queue - default constructor
//
template <typename T>
Queue <T>::Queue (void) :
        data_ (new Array <T>()),
        head_ (0),
        tail_ (-1) {

    //...
}

//
// Queue - copy constructor
//
template <typename T>
Queue <T>::Queue (const Queue & queue) :
        data_ (new Array <T>()),
        head_ (0),
        tail_ (-1) {

    // Ryan: We only need to copy the queue.data_ from one queue
    // to the other here.
    // Fixed: Properly copied over member variables by value.

    // if self assignment, ignore
    if (this == &queue)
        return;

    // mimic data members of input stack (by value!)
    *this->data_ = *queue.data_;
    this->head_  =  queue.head_;
    this->tail_  =  queue.tail_;
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void) {

    // call Array destructor
    delete this->data_;
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs) {

    // check for self assignment
    if (this == &rhs) {

        // return value this is pointing at
        return * this;
    }

    // mimic data members of input stack (by value!)
    *this->data_ = *rhs.data_;
    this->head_  =  rhs.head_;
    this->tail_  =  rhs.tail_;

    // return value this is pointing at
    return * this;
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue(T element) {

    //
    //  Make space in the array:
    //

    // if tail has reached end of array
    if (this->tail_ + 1 >= this->data_->size()) {

        // if head is 0 (i.e. queue is full)
        if (this->head_ == 0) {

            // resize (1 larger than current size)
            this->data_->resize(this->data_->size() + 1);

        // if head is > 0 (head is never < 0)
        } else {

            // shift elements left where head is 0
            int i = 0, j = this->head_;
            for (; j <= this->tail_; i++, j++)
                this->data_->set(i, this->data_->get(j));

            // re-adjust head and tail markers
            this->head_ = 0;
            this->tail_ = i - 1;
        }
    }

    //
    //  Add element:
    //

    // increment tail & add element
    this->data_->set(++this->tail_, element);
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue() {

    // exception if empty
    if (this->is_empty())
        throw Queue <T>::empty_exception();

    // increment head after returning element from front of array
    return this->data_->get(this->head_++);
}

//
// clear
//
template <typename T>
void Queue <T>::clear() {

    // [Note]:  Don't free array memory; chances are the user will
    //          want to put another n elements back into the queue,
    //          and freeing then reallocating n elements every time
    //          clear is called can have heavy impact on performance.

    // Ryan: We still need to resize the underlying data structure.
    // Fixed: I discussed this issue with Dr. Ryan and he allowed me
    // to keep it this way as long as the 'clear' functionality works
    // as expected.

    // reset head, tail
    this->head_ = 0;
    this->tail_ = -1;
}
