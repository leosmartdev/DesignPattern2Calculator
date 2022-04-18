#include "Expr_Node_Visitor.h"
#include "Binary_Op_Node.h"
#include "sub_Node_P.h"

//  default constructor
sub_Node_P::sub_Node_P() : Binary_Op_Node() 
{
    //...
}

//  initialization constructor
sub_Node_P::sub_Node_P(Expr_Node * first, Expr_Node * second) : Binary_Op_Node(first, second) 
{
    //...
}

//  accept
void sub_Node_P::accept(Expr_Node_Visitor & visitor) 
{
    visitor.visit_subtract_node(this);
}
