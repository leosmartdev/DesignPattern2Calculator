#ifndef _MULTIPLY_NODE_H_
#define _MULTIPLY_NODE_H_

#include "Binary_Op_Node.h"
#include "Expr_Node.h"

/**
*   @class mul_Node_P
*
*   An expression node that specifically represents operands
*/
class mul_Node_P : public Binary_Op_Node {

    public:

        mul_Node_P(void);

        /**
        *   Initializing constructor
        *
        *   @param: first                operand-node first of operator
        *   @param: second               operand-node second of operator
        */
        mul_Node_P(Expr_Node *, Expr_Node *);

        // Ryan: You need to use the abstract Visitor here.
        // Fixed: Now using abstract visitor rather than the concrete visitor

        /**
        *   Accept a visitor and let it visit us
        *
        *   @param: visitor             expression node visitor
        */
        void accept(Expr_Node_Visitor &);
};

#endif   // !defined _MULTIPLY_NODE_H_
