#ifndef _Expr_NODE_H_
#define _Expr_NODE_H_

class Expr_Node_Visitor;

/**
*   @class Expression Node
*
*   An abstract binary tree node, specifically meant for holding an expression item and accepting a visitation
*   from an expression node visitor.
*/
class Expr_Node {

    public:

        Expr_Node(void) {}

        virtual ~Expr_Node(void) {};

        // Copy constructor (deleted)
        Expr_Node(const Expr_Node &) = delete;

        // Equals operator (deleted)
        const Expr_Node & operator = (const Expr_Node &) = delete;

        /**
        *   Accept a visitor and let it visit us
        *
        *   @param: visitor             expression node visitor
        */
        virtual void accept(Expr_Node_Visitor &) = 0;
};

#endif   // !defined _Expr_NODE_H_
