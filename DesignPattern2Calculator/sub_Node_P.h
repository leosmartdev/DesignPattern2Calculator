#ifndef _SUBTRACT_NODE_H_
#define _SUBTRACT_NODE_H_

#include "Binary_Op_Node.h"
#include "Expr_Node.h"

/**
*   @class sub_Node_P
*
*   An expression node that specifically represents operands
*/
class sub_Node_P : public Binary_Op_Node {

    public:

        sub_Node_P(void);

        /**
        *   Initializing constructor
        *
        *   @param: first                operand-node first of operator
        *   @param: second               operand-node second of operator
        */
        sub_Node_P(Expr_Node *, Expr_Node *);

        /**
        *   Accept a visitor and let it visit us
        *
        *   @param:  visitor             expression node visitor
        */
        void accept(Expr_Node_Visitor &);
};

#endif   // !defined _SUBTRACT_NODE_H_
