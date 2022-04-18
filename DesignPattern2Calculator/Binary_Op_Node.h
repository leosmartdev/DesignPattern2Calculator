#ifndef _BINARY_OPERATOR_NODE_H_
#define _BINARY_OPERATOR_NODE_H_

#include <string>

#include "Queue.h"
#include "Expr_Node.h"

class Expr_Node_Visitor;

/**
*   @class Binary_Op_Node
*
*   An expression node that specifically represents binary operators
*/
class Binary_Op_Node : public Expr_Node {

    public:

        Binary_Op_Node(void);

        virtual ~Binary_Op_Node();

        /**
        *   Initializing constructor
        */
        Binary_Op_Node(Expr_Node *, Expr_Node *);

        /**
        *   Accept a visitor and let it visit us
        */
        virtual void accept(Expr_Node_Visitor &) = 0;

        /**
        *   Returns the priority of the operator
        *
        *   @return: priority          for implementating order-of-operations
        */
        int get_priority(void);

        /**
        *   Returns the operand-node first of the operator
        *
        *   @return: first                operand-node first of operator
        */
        Expr_Node * get_first(void);

        /**
        *   Returns the operand-node first of operator
        *
        *   @return: second               operand-node second of operator
        */
        Expr_Node * get_second(void);

        /**
        *   Sets the priority of the operator
        *
        *   @param: priority          for implementating order-of-operations
        */
        void set_priority(int);

        /**
        *   Sets the operand-node first of the operator
        *
        *   @param: first                operand-node first of operator
        */
        void set_first(Expr_Node *);

        /**
        *   Sets the operand-node first of operator
        *
        *   @param: second               operand-node second of operator
        */
        void set_second(Expr_Node *);

    protected:
        // priority of the binary operator in a typical expression
        int _priority;

        // expression-node representing operand first of operator
        Expr_Node * _first;

        // expression-node representing operand second of operator
        Expr_Node * _second;
};

#endif   // !defined _BINARY_OPERATOR_NODE_H_
