////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Number_Node.h
//  Date:           11/20/2017
//  Description:    Headers for Number_Node class.
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

#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Expression_Node.h"

/**
*   @class Number_Node
*
*   An expression node that specifically represents
*   operands
*/
class Number_Node : public Expression_Node {

    public:
        /// Default constructor
        Number_Node(void);

        /**
        *   Initializing constructor
        *
        *   @param[in]          number              integer value of this node
        */
        Number_Node(int);

        // Ryan: You need to use the abstract Visitor here.
        // Fixed: Now using abstract visitor rather than the concrete visitor

        /**
        *   Accept a visitor and let it visit us
        *
        *   @param[in]          visitor             expression node visitor
        */
        void accept(Expression_Node_Visitor &);

        /**
        *   Returns the precedence of this binary operator
        *
        *   @return             number              integer value of this node
        */
        int get_number(void);

        /**
        *   Sets the precedence of this binary operator
        *
        *   @param[in]          number              integer value of this node
        */
        void set_number(int);

    protected:
        /// precedence of the binary operator in a typical expression
        int number_;
};

#endif   // !defined _NUMBER_NODE_H_
