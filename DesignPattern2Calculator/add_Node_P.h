#ifndef _ADD_NODE_H_
#define _ADD_NODE_H_

#include "Binary_Op_Node.h"
#include "Expr_Node.h"

/**
*   @class add_Node_P
*
*   An expression node that specifically represents operands
*/
class add_Node_P : public Binary_Op_Node {

    public:
    
        add_Node_P(void);

        /**
        *   Initializing constructor
        */
        add_Node_P(Expr_Node *, Expr_Node *);

        /**
        *   Accept a visitor and let it visit us
        */
        void accept(Expr_Node_Visitor &);
};

#endif   // !defined _ADD_NODE_H_
