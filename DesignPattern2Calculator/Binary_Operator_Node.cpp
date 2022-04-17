////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Binary_Operator_Node.cpp
//  Date:           11/20/2017
//  Description:    Main implementation for Binary_Operator_Node class.
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
#include "Expression_Node.h"
#include "Binary_Operator_Node.h"

//
//  default constructor
//
Binary_Operator_Node::Binary_Operator_Node() : precedence_(0), left_(NULL),
        right_(NULL) {

    //...
}

//
//  destructor
//
Binary_Operator_Node::~Binary_Operator_Node() {

    delete this->left_;
    delete this->right_;
}

//
//  initialization constructor
//
Binary_Operator_Node::Binary_Operator_Node(Expression_Node * left,
        Expression_Node * right) : precedence_(0), left_(left), right_(right) {

    //...
}

//
//  get_precedence
//
int Binary_Operator_Node::get_precedence() {

    return this->precedence_;
}

//
//  get_left
//
Expression_Node * Binary_Operator_Node::get_left() {

    return this->left_;
}

//
//  get_right
//
Expression_Node * Binary_Operator_Node::get_right() {

    return this->right_;
}

//
//  set_precedence
//
void Binary_Operator_Node::set_precedence(int precedence) {

    this->precedence_ = precedence;
}

//
//  set_left
//
void Binary_Operator_Node::set_left(Expression_Node * left) {

    this->left_ = left;
}

//
//  set_right
//
void Binary_Operator_Node::set_right(Expression_Node * right) {

    this->right_ = right;
}
