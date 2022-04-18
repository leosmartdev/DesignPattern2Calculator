#include "Expr_Node_Visitor.h"
#include "Binary_Op_Node.h"
#include "add_Node_P.h"

//  default constructor
add_Node_P::add_Node_P() : Binary_Op_Node() 
{
    //...
}

//  initialization constructor
add_Node_P::add_Node_P(Expr_Node * first, Expr_Node * second) : Binary_Op_Node(first, second) 
{
    //...
}

//  accept
void add_Node_P::accept(Expr_Node_Visitor & visitor) 
{
    visitor.visit_add_node(this);
}
