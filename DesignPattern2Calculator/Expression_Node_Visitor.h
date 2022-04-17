////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Expression_Node_Visitor.h
//  Date:           11/19/2017
//  Description:    Headers for Expression_Node_Visitor class.
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

#ifndef _EXPRESSION_NODE_VISITOR_H_
#define _EXPRESSION_NODE_VISITOR_H_

// Ryan: You need to use forward declaration here.
// Fixed: Now using forward declaration rather than includes

class Number_Node;
class Add_Node;
class Subtract_Node;
class Multiply_Node;
class Divide_Node;
class Modulo_Node;

/**
*   @class Expression Node Visitor
*
*   An abstract visitor that specifically visits
*   expression nodes
*/
class Expression_Node_Visitor {

    public:
        /// Default constructor
        Expression_Node_Visitor(void) {}

        /// Destructor (virtual)
        virtual ~Expression_Node_Visitor(void) {};

        /// Copy constructor (deleted)
        Expression_Node_Visitor(const Expression_Node_Visitor &) = delete;

        /// Equals operator (deleted)
        const Expression_Node_Visitor & operator = (const Expression_Node_Visitor &) = delete;

        /**
        *   Visit a number node
        *
        *   @param[in]          number node             node representing an integer value
        */
        virtual void visit_number_node(Number_Node *) = 0;

        /**
        *   Visit a add node
        *
        *   @param[in]          add node                node representing the add operator
        */
        virtual void visit_add_node(Add_Node *) = 0;

        /**
        *   Visit a subtract node
        *
        *   @param[in]          subtract node           node representing the subtract operator
        */
        virtual void visit_subtract_node(Subtract_Node *) = 0;

        /**
        *   Visit a multiply node
        *
        *   @param[in]          multiply node           node representing the multiply operator
        */
        virtual void visit_multiply_node(Multiply_Node *) = 0;

        /**
        *   Visit a divide node
        *
        *   @param[in]          divide node             node representing the divide operator
        */
        virtual void visit_divide_node(Divide_Node *) = 0;

        /**
        *   Visit a modulo node
        *
        *   @param[in]          modulo node             node representing the modulo operator
        */
        virtual void visit_modulo_node(Modulo_Node *) = 0;
};

#endif   // !defined _EXPRESSION_NODE_VISITOR_H_
