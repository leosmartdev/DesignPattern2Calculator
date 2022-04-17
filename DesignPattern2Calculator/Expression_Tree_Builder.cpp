////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Expression_Tree_Builder.h
//  Date:           11/18/2017
//  Description:    Main implementation for Expression_Tree_Builder class.
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
#include <string>

#include "Stack.h"
#include "Queue.h"
#include "Expression_Node.h"
#include "Expression_Tree_Builder.h"
#include "Number_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulo_Node.h"

using std::string;

//
//  default constructor
//
Expression_Tree_Builder::Expression_Tree_Builder() : tree_(NULL),
        sub_tree_stack_(Stack<Expression_Node*>()) {

    //...
}

//
//  build_expression
//
void Expression_Tree_Builder::build_expression(Queue<std::string> & postfix_queue) {

    // ===-- Algorithm --================================== //
    // ---------------------------------------------------- //
    // For each string in the queue, create the             //
    // cooresponding node and, if it is an operand-node,    //
    // then push it into the sub-tree-stack; and if it is   //
    // an operator, then pop the top 2 sub-trees and make   //
    // them the children of the operator-node, where the    //
    // 1st item popped is the right child and the 2nd is    //
    // the left, and then push this newly-created sub-tree  //
    // onto the stack. It is expected that the root node of //
    // the tree will be the last item on the stack, so we   //
    // then record a reference of that root and clear the   //
    // sub-tree-stack.                                      //
    // ---------------------------------------------------- //
    while (!postfix_queue.is_empty()) {

        string item = postfix_queue.dequeue();
        if (item == "+") {
            this->build_add_node();
        } else if (item == "-") {
            this->build_subtract_node();
        } else if (item == "*") {
            this->build_multiply_node();
        } else if (item == "/") {
            this->build_divide_node();
        } else if (item == "%") {
            this->build_modulo_node();
        } else {
            this->build_number_node(std::stoi(item));
        }
    }

    this->tree_ = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
}

//
//  get_expression
//
Expression_Node * Expression_Tree_Builder::get_expression() {

    // return root node of tree
    return this->tree_;
}

//
//  build_number_node
//
void Expression_Tree_Builder::build_number_node(int num) {

    Expression_Node * node = new Number_Node(num);
    this->sub_tree_stack_.push(node);
}

//
//  build_add_node
//
void Expression_Tree_Builder::build_add_node() {

    Expression_Node * right = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
    Expression_Node * left = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
    Expression_Node * parent = new Add_Node(left, right);
    this->sub_tree_stack_.push(parent);
}

//
//  build_subtract_node
//
void Expression_Tree_Builder::build_subtract_node() {

    Expression_Node * right = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
    Expression_Node * left = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
    Expression_Node * parent = new Subtract_Node(left, right);
    this->sub_tree_stack_.push(parent);
}

//
//  build_multiply_node
//
void Expression_Tree_Builder::build_multiply_node() {

    Expression_Node * right = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
    Expression_Node * left = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
    Expression_Node * parent = new Multiply_Node(left, right);
    this->sub_tree_stack_.push(parent);
}

//
//  build_divide_node
//
void Expression_Tree_Builder::build_divide_node() {

    Expression_Node * right = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
    Expression_Node * left = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
    Expression_Node * parent = new Divide_Node(left, right);
    this->sub_tree_stack_.push(parent);
}

//
//  build_modulo_node
//
void Expression_Tree_Builder::build_modulo_node() {

    Expression_Node * right = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
    Expression_Node * left = this->sub_tree_stack_.top();
    this->sub_tree_stack_.pop();
    Expression_Node * parent = new Modulo_Node(left, right);
    this->sub_tree_stack_.push(parent);
}
