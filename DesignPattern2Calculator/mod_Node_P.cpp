#include "Expr_Node_Visitor.h"
#include "Binary_Op_Node.h"
#include "mod_Node_P.h"

//  default constructor
mod_Node_P::mod_Node_P() : Binary_Op_Node() 
{
    //...
}

//  initialization constructor
mod_Node_P::mod_Node_P(Expr_Node * first, Expr_Node * second) : Binary_Op_Node(first, second) 
{
    //...
}

//  accept
void mod_Node_P::accept(Expr_Node_Visitor & visitor) 
{
    visitor.visit_modulo_node(this);
}
