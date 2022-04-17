////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Number_Node.cpp
//  Date:           11/20/2017
//  Description:    Main implementation for Number_Node class.
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

//
// (resources)
//
#include "Expression_Node_Visitor.h"
#include "Expression_Node.h"
#include "Number_Node.h"

//
//  default constructor
//
Number_Node::Number_Node() : number_(0) {

    //...
}

//
//  initialization constructor
//
Number_Node::Number_Node(int number) : number_(number) {

    //...
}

// Ryan: You need to use the abstract Visitor here.
// Fixed: Now using abstract visitor rather than the concrete visitor

//
//  accept
//
void Number_Node::accept(Expression_Node_Visitor & visitor) {

    // accept the visitor's visitaion to know
    // exactly what we are (a Number_Node)
    visitor.visit_number_node(this);
}

//
//  get_number
//
int Number_Node::get_number() {

    return this->number_;
}

//
//  set_number
//
void Number_Node::set_number(int number) {

    this->number_ = number;
}
