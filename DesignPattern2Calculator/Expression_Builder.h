////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Expression_Builder.h
//  Date:           11/18/2017
//  Description:    Abstract Expression_Builder class.
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

#ifndef _EXPRESSION_BUILDER_H_
#define _EXPRESSION_BUILDER_H_

#include <string>

#include "Queue.h"
#include "Expression_Node.h"

/**
*   @class Expression_Builder
*
*   An abstract Expression Builder for building
*   expressions
*/
class Expression_Builder {

    public:
        /// Default constructor
        Expression_Builder(void) {}

        /// Destructor (virtual)
        virtual ~Expression_Builder(void) {};

        /// Copy constructor (deleted)
        Expression_Builder(const Expression_Builder &) = delete;

        /// Equals operator (deleted)
        const Expression_Builder & operator = (const Expression_Builder &) = delete;

        /**
        *   Builds the expression tree
        *
        *   @param[in]          postfix queue           contains items in postfix order
        */
        virtual void build_expression(Queue<std::string> &) = 0;

        /**
        *   Returns the root node of expression tree
        *
        *   @return             root node               root node of expresion tree
        */
        virtual Expression_Node * get_expression(void) = 0;

        /**
        *   Builds a number node into the tree
        *
        *   @return             number                  a number from the postfix expression
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

#endif   // !defined _EXPRESSION_BUILDER_H_
