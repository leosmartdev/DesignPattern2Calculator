#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Expr_Node.h"

/**
*   @class num_Node_P
*
*   An expression node that specifically represents operands
*/
class num_Node_P : public Expr_Node {

    public:

        num_Node_P(void);

        /**
        *   Initializing constructor
        *
        *   @param: number              integer value of this node
        */
        num_Node_P(int);

        /**
        *   Accept a visitor and let it visit us
        *
        *   @param: visitor             expression node visitor
        */
        void accept(Expr_Node_Visitor &);

        /**
        *   Returns the priority of this binary operator
        *
        *   @return: number              integer value of this node
        */
        int get_number(void);

        /**
        *   Sets the priority of this binary operator
        *
        *   @param: number              integer value of this node
        */
        void set_number(int);

    protected:
        /// priority of the binary operator in a typical expression
        int _number;
};

#endif   // !defined _NUMBER_NODE_H_
