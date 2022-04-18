#include "Expr_Node_Visitor.h"
#include "Expr_Node.h"
#include "num_Node_P.h"

//  default constructor
num_Node_P::num_Node_P() : _number(0) 
{
    //...
}

//  initialization constructor
num_Node_P::num_Node_P(int number) : _number(number) 
{
    //...
}

//  accept
void num_Node_P::accept(Expr_Node_Visitor & visitor) 
{
    visitor.visit_number_node(this);
}

//  get_number
int num_Node_P::get_number() 
{
    return this->_number;
}

//  set_number
void num_Node_P::set_number(int number) 
{
    this->_number = number;
}
