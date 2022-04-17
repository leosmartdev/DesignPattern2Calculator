////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Expression_Node.h
//  Date:           11/20/2017
//  Description:    Headers for Expression_Node class.
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

#ifndef _EXPRESSION_NODE_H_
#define _EXPRESSION_NODE_H_

// Ryan: You need to use forward declaration here.
// Fixed: Now using forward declaration rather than includes

class Expression_Node_Visitor;

/**
*   @class Expression Node
*
*   An abstract binary tree node, specifically meant for
*   holding an expression item and accepting a visitation
*   from an expression node visitor.
*/
class Expression_Node {

    public:
        /// Default constructor
        Expression_Node(void) {}

        /// Destructor (virtual)
        virtual ~Expression_Node(void) {};

        /// Copy constructor (deleted)
        Expression_Node(const Expression_Node &) = delete;

        /// Equals operator (deleted)
        const Expression_Node & operator = (const Expression_Node &) = delete;

        // Ryan: You need to use the abstract Visitor here.
        // Fixed: Now using abstract visitor rather than the concrete visitor

        /**
        *   Accept a visitor and let it visit us
        *
        *   @param[in]          visitor             expression node visitor
        */
        virtual void accept(Expression_Node_Visitor &) = 0;
};

#endif   // !defined _EXPRESSION_NODE_H_
