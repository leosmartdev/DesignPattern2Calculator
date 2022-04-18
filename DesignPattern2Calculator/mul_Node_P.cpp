#include "Expr_Node_Visitor.h"
#include "Binary_Op_Node.h"
#include "mul_Node_P.h"

//  default constructor
mul_Node_P::mul_Node_P() : Binary_Op_Node() 
{
    //...
}

//  initialization constructor
mul_Node_P::mul_Node_P(Expr_Node * first, Expr_Node * second) : Binary_Op_Node(first, second) 
{
    //...
}

//  accept
void mul_Node_P::accept(Expr_Node_Visitor & visitor) 
{
    visitor.visit_multiply_node(this);
}
