#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <exception>
#include "Array.h"

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue {

public:

    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the queue is empty.
     */
    class empty_exception : public std::exception {
    public:
        /// Default constructor.
        empty_exception (void) : std::exception () {}
    };

    /// Default constructor.
    Queue (void);

    /// Copy constructor.
    Queue (const Queue & s);

    /// Destructor.
    ~Queue (void);

    /**
     * Assignment operator
     *
     * @param: rhs           second-hand side of operator
     * @return: Reference to self
     */
    const Queue & operator = (const Queue & rhs);

    /**
     * Enqueues an element into the end of the queue.
     *
     * @param: element         element to add to the list
     */
     void enqueue(T);

     /**
      * Dequeues an element from the beginning of the queue.
      *
      * @exception: empty_exception    The queue is empty
      * @return: element        element from the start of the list
      */
     T dequeue(void);

     /**
      * Test if the queue is empty.
      *
      * @retval: true          The queue is empty
      * @retval: false         The queue is not empty
      */
     bool is_empty (void) const;

     /**
      * Number of element in the queue.
      *
      * @return         Size of the queue.
      */
     uInt size (void) const;

     // Remove all elements from the queue.
     void clear (void);

private:
    // add member variable(s) here

    ///Pointer to queue data stored in an Array
    Array <T> * _data;

    // Head index of current queue
    int _head;

    // Tail index of current queue
    int _tail;
};

// include the source file since template class
#include "Queue.cpp"

#endif   // !defined _QUEUE_H_
