////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Binary_Operator_Node.h
//  Date:           11/20/2017
//  Description:    Headers for Binary_Operator_Node class.
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

#ifndef _BINARY_OPERATOR_NODE_H_
#define _BINARY_OPERATOR_NODE_H_

#include <string>

#include "Queue.h"
#include "Expression_Node.h"

class Expression_Node_Visitor;

/**
*   @class Binary_Operator_Node
*
*   An expression node that specifically represents
*   binary operators
*/
class Binary_Operator_Node : public Expression_Node {

    public:
        /// Default constructor
        Binary_Operator_Node(void);

        /// Destructor
        virtual ~Binary_Operator_Node();

        /**
        *   Initializing constructor
        *
        *   @param[in]          left                operand-node left of operator
        *   @param[in]          right               operand-node right of operator
        */
        Binary_Operator_Node(Expression_Node *, Expression_Node *);

        // Ryan: You need to use the abstract Visitor here.
        // Fixed: Now using abstract visitor rather than the concrete visitor

        /**
        *   Accept a visitor and let it visit us
        *
        *   @param[in]          visitor             expression node visitor
        */
        virtual void accept(Expression_Node_Visitor &) = 0;

        /**
        *   Returns the precedence of the operator
        *
        *   @return             precedence          for implementating order-of-operations
        */
        int get_precedence(void);

        /**
        *   Returns the operand-node left of the operator
        *
        *   @return             left                operand-node left of operator
        */
        Expression_Node * get_left(void);

        /**
        *   Returns the operand-node left of operator
        *
        *   @return             right               operand-node right of operator
        */
        Expression_Node * get_right(void);

        /**
        *   Sets the precedence of the operator
        *
        *   @param[in]          precedence          for implementating order-of-operations
        */
        void set_precedence(int);

        /**
        *   Sets the operand-node left of the operator
        *
        *   @param[in]          left                operand-node left of operator
        */
        void set_left(Expression_Node *);

        /**
        *   Sets the operand-node left of operator
        *
        *   @param[in]          right               operand-node right of operator
        */
        void set_right(Expression_Node *);

    protected:
        /// precedence of the binary operator in a typical expression
        int precedence_;

        /// expression-node representing operand left of operator
        Expression_Node * left_;

        /// expression-node representing operand right of operator
        Expression_Node * right_;
};

#endif   // !defined _BINARY_OPERATOR_NODE_H_
