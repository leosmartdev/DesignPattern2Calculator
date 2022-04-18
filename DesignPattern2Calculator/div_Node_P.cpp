#include "Expr_Node_Visitor.h"
#include "Binary_Op_Node.h"
#include "div_Node_P.h"

//  default constructor
div_Node_P::div_Node_P() : Binary_Op_Node() 
{
    //...
}

//  initialization constructor
div_Node_P::div_Node_P(Expr_Node * first, Expr_Node * second) : Binary_Op_Node(first, second)
{
    //...
}

//  accept
void div_Node_P::accept(Expr_Node_Visitor & visitor)
{
    visitor.visit_divide_node(this);
}
