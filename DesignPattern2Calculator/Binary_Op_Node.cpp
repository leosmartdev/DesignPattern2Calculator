#include "Expr_Node.h"
#include "Binary_Op_Node.h"

//  default constructor
Binary_Op_Node::Binary_Op_Node() : _priority(0), _first(NULL), _second(NULL)
{
    //...
}

//  destructor
Binary_Op_Node::~Binary_Op_Node() 
{
    delete this->_first;
    delete this->_second;
}

//  initialization constructor
Binary_Op_Node::Binary_Op_Node(Expr_Node * first, Expr_Node * second) : _priority(0), _first(first), _second(second) 
{
    //...
}

//  get_priority
int Binary_Op_Node::get_priority() 
{
    return this->_priority;
}

//  get_first
Expr_Node * Binary_Op_Node::get_first() 
{
    return this->_first;
}

//  get_second
Expr_Node * Binary_Op_Node::get_second() 
{
    return this->_second;
}

//  set_priority
void Binary_Op_Node::set_priority(int priority) 
{
    this->_priority = priority;
}

//  set_first
void Binary_Op_Node::set_first(Expr_Node * first) {

    this->_first = first;
}

//  set_second
void Binary_Op_Node::set_second(Expr_Node * second) {

    this->_second = second;
}
