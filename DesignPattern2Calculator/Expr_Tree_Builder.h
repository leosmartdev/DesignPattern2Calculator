#ifndef _Expr_TREE_BUILDER_H_
#define _Expr_TREE_BUILDER_H_

#include <string>

#include "Queue.h"
#include "Stack.h"
#include "Expr_Builder.h"
#include "Expr_Node.h"

/**
*   @class Expression Tree Builder
*
*   Builds and stores an expression tree's root node from a postfix queue
*/
class Expr_Tree_Builder : public Expr_Builder {

    public:

        Expr_Tree_Builder(void);

        /**
        *   Builds the expression tree via stack manipulation; then store the root
        *
        *   @param: postfix queue           contains items in postfix order
        */
        void build_expression(Queue<std::string> &);

        /**
        *   Returns the root node of expression tree
        *
        *   @return: root node               root node of expresion tree
        */
        Expr_Node * get_expression(void);

        /**
        *   Builds a number node into the tree via stack manipulation
        *
        *   @return: number                  a number from the postfix expression
        */
        void build_number_node(int);

        /**
        *   Builds an add node into the tree via stack manipulation
        */
        void build_add_node(void);

        /**
        *   Builds a subtract node into the tree via stack manipulation
        */
        void build_subtract_node(void);

        /**
        *   Builds a multiply node into the tree via stack manipulation
        */
        void build_multiply_node(void);

        /**
        *   Builds a divide node into the tree via stack manipulation
        */
        void build_divide_node(void);

        /**
        *   Builds a modulo node into the tree via stack manipulation
        */
        void build_modulo_node(void);

    private:

        Expr_Node * _tree;

        Stack <Expr_Node*> _sub_tree_stack;
};

#endif   // !defined _Expr_TREE_BUILDER_H_
