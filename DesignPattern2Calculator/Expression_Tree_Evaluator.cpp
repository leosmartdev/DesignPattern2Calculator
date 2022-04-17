////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Expression_Tree_Evaluator.cpp
//  Date:           11/18/2017
//  Description:    Main implementation for Expression_Tree_Evaluator class.
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

#include "Expression_Tree_Evaluator.h"
#include "Expression_Node.h"
#include "Number_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulo_Node.h"
#include "Stack.h"

//
//  default constructor
//
Expression_Tree_Evaluator::Expression_Tree_Evaluator() : result_(0),
        stack_(Stack<int>()) {

    //...
}

//
//  evaluate
//
int Expression_Tree_Evaluator::evaluate(Expression_Node * root) {

    // ===-- Algorithm --================================== //
    // ---------------------------------------------------- //
    // Root node is expected to be an operator. We only     //
    // have to visit the root node to trigger a recursive   //
    // evaluation/visitation: if it is an operand-node,     //
    // then push its int value into the stack; and if it is //
    // an operator, then pop the top 2 ints and apply the   //
    // operator on them, where the 1st item popped is the   //
    // right child and the 2nd is the left, and then push   //
    // their result onto the stack. It is expected that the //
    // result of the expression tree will be the last item  //
    // on the stack, so we then record the the result and   //
    // clear the stack.                                     //
    // ---------------------------------------------------- //
    root->accept(*this);
    this->result_ = this->stack_.top();
    this->stack_.pop();
    return this->result_;
}

//
//  visit_number_node
//
void Expression_Tree_Evaluator::visit_number_node(Number_Node * node) {

    this->stack_.push(node->get_number());
}

//
//  visit_add_node
//
void Expression_Tree_Evaluator::visit_add_node(Add_Node * node) {

    node->get_left()->accept(*this);
    node->get_right()->accept(*this);
    int right = this->stack_.top();
    this->stack_.pop();
    int left = this->stack_.top();
    this->stack_.pop();
    this->stack_.push(left + right);
}

//
//  visit_subtract_node
//
void Expression_Tree_Evaluator::visit_subtract_node(Subtract_Node * node) {

    node->get_left()->accept(*this);
    node->get_right()->accept(*this);
    int right = this->stack_.top();
    this->stack_.pop();
    int left = this->stack_.top();
    this->stack_.pop();
    this->stack_.push(left - right);
}

//
//  visit_multiply_node
//
void Expression_Tree_Evaluator::visit_multiply_node(Multiply_Node * node) {

    node->get_left()->accept(*this);
    node->get_right()->accept(*this);
    int right = this->stack_.top();
    this->stack_.pop();
    int left = this->stack_.top();
    this->stack_.pop();
    this->stack_.push(left * right);
}

//
//  visit_divide_node
//
void Expression_Tree_Evaluator::visit_divide_node(Divide_Node * node) {

    node->get_left()->accept(*this);
    node->get_right()->accept(*this);
    int right = this->stack_.top();
    this->stack_.pop();
    int left = this->stack_.top();
    this->stack_.pop();
    if (!right) throw Expression_Tree_Evaluator::divide_by_zero_exception(left);
    this->stack_.push(left / right);
}

//
//  visit_modulo_node
//
void Expression_Tree_Evaluator::visit_modulo_node(Modulo_Node * node) {

    node->get_left()->accept(*this);
    node->get_right()->accept(*this);
    int right = this->stack_.top();
    this->stack_.pop();
    int left = this->stack_.top();
    this->stack_.pop();
    if (!right) throw Expression_Tree_Evaluator::modulo_by_zero_exception(left);
    this->stack_.push(left % right);
}
