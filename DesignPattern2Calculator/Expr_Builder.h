#ifndef _Expr_BUILDER_H_
#define _Expr_BUILDER_H_

#include <string>

#include "Queue.h"
#include "Expr_Node.h"

/**
*   @class Expr_Builder
*
*   An abstract Expression Builder for building expressions
*/
class Expr_Builder {

    public:

        Expr_Builder(void) {}

        virtual ~Expr_Builder(void) {};

        // Copy constructor (deleted)
        Expr_Builder(const Expr_Builder &) = delete;

        // Equals operator (deleted)
        const Expr_Builder & operator = (const Expr_Builder &) = delete;

        /**
        *   Builds the expression tree
        *
        *   @param: postfix queue           contains items in postfix order
        */
        virtual void build_expression(Queue<std::string> &) = 0;

        /**
        *   Returns the root node of expression tree
        *
        *   @return: root node               root node of expresion tree
        */
        virtual Expr_Node * get_expression(void) = 0;

        /**
        *   Builds a number node into the tree
        *
        *   @return: number                  a number from the postfix expression
        */
        virtual void build_number_node(int) = 0;

        /**
        *   Builds an add node into the tree
        */
        virtual void build_add_node(void) = 0;

        /**
        *   Builds a subtract node into the tree
        */
        virtual void build_subtract_node(void) = 0;

        /**
        *   Builds a multiply node into the tree
        */
        virtual void build_multiply_node(void) = 0;

        /**
        *   Builds a divide node into the tree
        */
        virtual void build_divide_node(void) = 0;

        /**
        *   Builds a modulo node into the tree
        */
        virtual void build_modulo_node(void) = 0;
};

#endif   // !defined _Expr_BUILDER_H_
