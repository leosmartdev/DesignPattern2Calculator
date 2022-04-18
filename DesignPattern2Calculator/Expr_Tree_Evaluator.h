#ifndef _Expr_TREE_EVALUATOR_H_
#define _Expr_TREE_EVALUATOR_H_

#include <exception>
#include <sstream>
#include <string>

#include "Expr_Node_Visitor.h"
#include "Expr_Node.h"
#include "num_Node_P.h"
#include "add_Node_P.h"
#include "sub_Node_P.h"
#include "mul_Node_P.h"
#include "div_Node_P.h"
#include "mod_Node_P.h"
#include "Stack.h"

/**
*   @class Expression Tree Evaluator
*
*   Evaluates an expression tree using the visitor pattern and a variable to gather node information
*/
class Expr_Tree_Evaluator : public Expr_Node_Visitor {

    /**
     *  @class divide_by_zero_exception
     *
     *  Exception thrown to indicate a division by zero was attempted
     */
    class divide_by_zero_exception : public std::exception {
    public:
        // Initialization constructor.
        divide_by_zero_exception(int first) : std::exception(), _first(first) {}

        // message of exception
        const char* what() const noexcept {
            std::stringstream ss;
            ss << "Division by zero: " << this->_first << " / 0 is not allowed.";
            std::string tmpstr = ss.str();
            return tmpstr.c_str();
        }
    private:
        // number trying to divide by zero by
        int _first;
    };

    /**
     *  @class modulo_by_zero_exception
     *
     *  Exception thrown to indicate a modulo by zero was attempted
     */
    class modulo_by_zero_exception : public std::exception {
    public:
        // Initialization constructor.
        modulo_by_zero_exception(int first) : std::exception(), _first(first) {}

        // message of exception
        const char* what() const noexcept {
            std::stringstream ss;
            ss << "Modulus by zero: " << this->_first << " % 0 is not allowed.";
            std::string tmpstr = ss.str();
            return tmpstr.c_str();
        }
    private:
        // number trying to divide by zero by
        int _first;
    };

    public:
        // Default constructor
        Expr_Tree_Evaluator(void);

        /**
        *   Evaluates an expression tree/sub-tree starting at the root node
        *
        *   @param: root node               node representing some binary operator
        *   @return: result                  result integer value of evaluated expression
        */
        int evaluate(Expr_Node *);

        /**
        *   Visit a number node and incorporate it into the evaluation stack
        *
        *   @param: number node             node representing an integer value
        */
        void visit_number_node(num_Node_P *);

        /**
        *   Visit a add node and incorporate it into the evaluation stack
        *
        *   @param: add node                node representing the add operator
        */
        void visit_add_node(add_Node_P *);

        /**
        *   Visit a subtract node and incorporate it into the evaluation stack
        *
        *   @param: subtract node           node representing the subtract operator
        */
        void visit_subtract_node(sub_Node_P *);

        /**
        *   Visit a multiply node and incorporate it into the evaluation stack
        *
        *   @param: multiply node           node representing the multiply operator
        */
        void visit_multiply_node(mul_Node_P *);

        /**
        *   Visit a divide node and incorporate it into the evaluation stack
        *
        *   @param: divide node             node representing the divide operator
        */
        void visit_divide_node(div_Node_P *);

        /**
        *   Visit a modulo node and incorporate it into the evaluation stack
        *
        *   @param: modulo node             node representing the modulo operator
        */
        void visit_modulo_node(mod_Node_P *);

    private:
        // integer stack; used for storing operands in order
        Stack<int> _stack;

        // integer result; used for evaluating a postfix tree
        int _result;
};

#endif   // !defined _Expr_TREE_H_
