////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Subtract_Node.h
//  Date:           11/20/2017
//  Description:    Headers for Subtract_Node class.
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

#include "Expression_Node_Visitor.h"
#include "Binary_Operator_Node.h"
#include "Subtract_Node.h"

//
//  default constructor
//
Subtract_Node::Subtract_Node() : Binary_Operator_Node() {

    //...
}

//
//  initialization constructor
//
Subtract_Node::Subtract_Node(Expression_Node * left, Expression_Node * right) :
        Binary_Operator_Node(left, right) {

    //...
}

// Ryan: You need to use the abstract Visitor here.
// Fixed: Now using abstract visitor rather than the concrete visitor

//
//  accept
//
void Subtract_Node::accept(Expression_Node_Visitor & visitor) {

    // accept the visitor's visitaion to know
    // exactly what we are (a Subtract_Node)
    visitor.visit_subtract_node(this);
}
