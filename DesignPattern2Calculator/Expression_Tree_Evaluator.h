////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Expression_Tree_Evaluator.h
//  Date:           11/18/2017
//  Description:    Headers for Expression_Tree_Evaluator class.
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

#ifndef _EXPRESSION_TREE_EVALUATOR_H_
#define _EXPRESSION_TREE_EVALUATOR_H_

#include <exception>
#include <sstream>
#include <string>

#include "Expression_Node_Visitor.h"
#include "Expression_Node.h"
#include "Number_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulo_Node.h"
#include "Stack.h"

/**
*   @class Expression Tree Evaluator
*
*   Evaluates an expression tree using the visitor pattern
*   and a variable to gather node information
*/
class Expression_Tree_Evaluator : public Expression_Node_Visitor {

    /**
     *  @class divide_by_zero_exception
     *
     *  Exception thrown to indicate a division
     *  by zero was attempted
     */
    class divide_by_zero_exception : public std::exception {
    public:
        /// Initialization constructor.
        divide_by_zero_exception(int left) : std::exception(), left_(left) {}

        /// message of exception
        const char* what() const noexcept {
            std::stringstream ss;
            ss << "Division by zero: " << this->left_ << " / 0 is not allowed.";
            std::string tmpstr = ss.str();
            return tmpstr.c_str();
        }
    private:
        /// number trying to divide by zero by
        int left_;
    };

    /**
     *  @class modulo_by_zero_exception
     *
     *  Exception thrown to indicate a modulo
     *  by zero was attempted
     */
    class modulo_by_zero_exception : public std::exception {
    public:
        /// Initialization constructor.
        modulo_by_zero_exception(int left) : std::exception(), left_(left) {}

        /// message of exception
        const char* what() const noexcept {
            std::stringstream ss;
            ss << "Modulus by zero: " << this->left_ << " % 0 is not allowed.";
            std::string tmpstr = ss.str();
            return tmpstr.c_str();
        }
    private:
        /// number trying to divide by zero by
        int left_;
    };

    public:
        /// Default constructor
        Expression_Tree_Evaluator(void);

        /**
        *   Evaluates an expression tree/sub-tree starting at the root node
        *
        *   @param[in]          root node               node representing some binary operator
        *   @return             result                  result integer value of evaluated expression
        */
        int evaluate(Expression_Node *);

        /**
        *   Visit a number node and incorporate it into the evaluation stack
        *
        *   @param[in]          number node             node representing an integer value
        */
        void visit_number_node(Number_Node *);

        /**
        *   Visit a add node and incorporate it into the evaluation stack
        *
        *   @param[in]          add node                node representing the add operator
        */
        void visit_add_node(Add_Node *);

        /**
        *   Visit a subtract node and incorporate it into the evaluation stack
        *
        *   @param[in]          subtract node           node representing the subtract operator
        */
        void visit_subtract_node(Subtract_Node *);

        /**
        *   Visit a multiply node and incorporate it into the evaluation stack
        *
        *   @param[in]          multiply node           node representing the multiply operator
        */
        void visit_multiply_node(Multiply_Node *);

        /**
        *   Visit a divide node and incorporate it into the evaluation stack
        *
        *   @param[in]          divide node             node representing the divide operator
        */
        void visit_divide_node(Divide_Node *);

        /**
        *   Visit a modulo node and incorporate it into the evaluation stack
        *
        *   @param[in]          modulo node             node representing the modulo operator
        */
        void visit_modulo_node(Modulo_Node *);

    private:
        /// integer stack; used for storing operands in order
        Stack<int> stack_;

        /// integer result; used for evaluating a postfix tree
        int result_;
};

#endif   // !defined _EXPRESSION_TREE_H_
