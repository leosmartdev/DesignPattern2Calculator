////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Expression_Tree_Builder.h
//  Date:           11/18/2017
//  Description:    Headers for Expression_Tree_Builder class.
//
////////////////////////////////////////////////////////////////////////////////
//
//  Honor Pledge:
//
//  I pledge that I have neither given nor received any help on this assignment.
//
//  ibsardar
//
////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2017 Copyright Holder All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _EXPRESSION_TREE_BUILDER_H_
#define _EXPRESSION_TREE_BUILDER_H_

#include <string>

#include "Queue.h"
#include "Stack.h"
#include "Expression_Builder.h"
#include "Expression_Node.h"

/**
*   @class Expression Tree Builder
*
*   Builds and stores an expression tree's root
*   node from a postfix queue
*/
class Expression_Tree_Builder : public Expression_Builder {

    public:
        /// Default constructor
        Expression_Tree_Builder(void);

        /**
        *   Builds the expression tree via stack manipulation; then store the root
        *
        *   @param[in]          postfix queue           contains items in postfix order
        */
        void build_expression(Queue<std::string> &);

        /**
        *   Returns the root node of expression tree
        *
        *   @return             root node               root node of expresion tree
        */
        Expression_Node * get_expression(void);

        // Ryan: Why not let them be public?
        // Fixed: I have left the following functions public instead of private
        // which is what I was thinking doing before (since they are never used
        // publicly in this program).

        /**
        *   Builds a number node into the tree via stack manipulation
        *
        *   @return             number                  a number from the postfix expression
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
        /// last built expression tree's root-node from this Builder
        Expression_Node * tree_;

        /// stack that holds expression nodes
        Stack <Expression_Node*> sub_tree_stack_;
};

#endif   // !defined _EXPRESSION_TREE_BUILDER_H_
