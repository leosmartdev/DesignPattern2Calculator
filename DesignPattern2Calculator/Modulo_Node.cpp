////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Modulo_Node.h
//  Date:           11/20/2017
//  Description:    Headers for Modulo_Node class.
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
#include "Modulo_Node.h"

//
//  default constructor
//
Modulo_Node::Modulo_Node() : Binary_Operator_Node() {

    //...
}

//
//  initialization constructor
//
Modulo_Node::Modulo_Node(Expression_Node * left, Expression_Node * right) :
        Binary_Operator_Node(left, right) {

    //...
}

// Ryan: You need to use the abstract Visitor here.
// Fixed: Now using abstract visitor rather than the concrete visitor

//
//  accept
//
void Modulo_Node::accept(Expression_Node_Visitor & visitor) {

    // accept the visitor's visitaion to know
    // exactly what we are (a Modulo_Node)
    visitor.visit_modulo_node(this);
}
