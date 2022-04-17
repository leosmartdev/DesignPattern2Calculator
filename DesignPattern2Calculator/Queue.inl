////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Queue.inl
//  Date:           09/26/2017
//  Description:    Inline functions for Queue class.
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
// size
//
template <typename T>
inline
uInt Queue <T>::size (void) const {

    // The difference between the head and tail + 1
    //  will give the appropriate number of elements
    //  in the queue
    return this->tail_ - this->head_ + 1;
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const {

    // empty if head index has surpassed the tail
    return this->head_ > this->tail_;
}
