#ifndef _DIVIDE_NODE_H_
#define _DIVIDE_NODE_H_

#include "Binary_Op_Node.h"
#include "Expr_Node.h"

/**
*   @class div_Node_P
*
*   An expression node that specifically represents
*   operands
*/
class div_Node_P : public Binary_Op_Node {

    public:
        /// Default constructor
        div_Node_P(void);

        /**
        *   Initializing constructor
        *
        *   @param[in]          first                operand-node first of operator
        *   @param[in]          second               operand-node second of operator
        */
        div_Node_P(Expr_Node *, Expr_Node *);

        // Ryan: You need to use the abstract Visitor here.
        // Fixed: Now using abstract visitor rather than the concrete visitor

        /**
        *   Accept a visitor and let it visit us
        *
        *   @param[in]          visitor             expression node visitor
        */
        void accept(Expr_Node_Visitor &);
};

#endif   // !defined _DIVIDE_NODE_H_
