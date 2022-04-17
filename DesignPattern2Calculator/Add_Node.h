////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Add_Node.h
//  Date:           11/20/2017
//  Description:    Headers for Add_Node class.
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

#ifndef _ADD_NODE_H_
#define _ADD_NODE_H_

#include "Binary_Operator_Node.h"
#include "Expression_Node.h"

/**
*   @class Add_Node
*
*   An expression node that specifically represents
*   operands
*/
class Add_Node : public Binary_Operator_Node {

    public:
        /// Default constructor
        Add_Node(void);

        /**
        *   Initializing constructor
        *
        *   @param[in]          left                operand-node left of operator
        *   @param[in]          right               operand-node right of operator
        */
        Add_Node(Expression_Node *, Expression_Node *);

        // Ryan: You need to use the abstract Visitor here.
        // Fixed: Now using abstract visitor rather than the concrete visitor

        /**
        *   Accept a visitor and let it visit us
        *
        *   @param[in]          visitor             expression node visitor
        */
        void accept(Expression_Node_Visitor &);
};

#endif   // !defined _ADD_NODE_H_
