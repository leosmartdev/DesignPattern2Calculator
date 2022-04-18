#include "Expr_Tree_Evaluator.h"
#include "Expr_Node.h"
#include "num_Node_P.h"
#include "add_Node_P.h"
#include "sub_Node_P.h"
#include "mul_Node_P.h"
#include "div_Node_P.h"
#include "mod_Node_P.h"
#include "Stack.h"

//  default constructor
Expr_Tree_Evaluator::Expr_Tree_Evaluator() : _result(0), _stack(Stack<int>()) 
{
    //...
}

//  evaluate
int Expr_Tree_Evaluator::evaluate(Expr_Node * root) 
{
    root->accept(*this);
    this->_result = this->_stack.top();
    this->_stack.pop();
    return this->_result;
}

//  visit_number_node
void Expr_Tree_Evaluator::visit_number_node(num_Node_P * node) 
{
    this->_stack.push(node->get_number());
}

//  visit_add_node
void Expr_Tree_Evaluator::visit_add_node(add_Node_P * node) 
{
    node->get_first()->accept(*this);
    node->get_second()->accept(*this);
    int second = this->_stack.top();
    this->_stack.pop();
    int first = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(first + second);
}

//  visit_subtract_node
void Expr_Tree_Evaluator::visit_subtract_node(sub_Node_P * node) 
{
    node->get_first()->accept(*this);
    node->get_second()->accept(*this);
    int second = this->_stack.top();
    this->_stack.pop();
    int first = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(first - second);
}

//  visit_multiply_node
void Expr_Tree_Evaluator::visit_multiply_node(mul_Node_P * node) 
{
    node->get_first()->accept(*this);
    node->get_second()->accept(*this);
    int second = this->_stack.top();
    this->_stack.pop();
    int first = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(first * second);
}

//  visit_divide_node
void Expr_Tree_Evaluator::visit_divide_node(div_Node_P * node) 
{
    node->get_first()->accept(*this);
    node->get_second()->accept(*this);
    int second = this->_stack.top();
    this->_stack.pop();
    int first = this->_stack.top();
    this->_stack.pop();
    if (!second) throw Expr_Tree_Evaluator::divide_by_zero_exception(first);
    this->_stack.push(first / second);
}

//  visit_modulo_node
void Expr_Tree_Evaluator::visit_modulo_node(mod_Node_P * node) 
{
    node->get_first()->accept(*this);
    node->get_second()->accept(*this);
    int second = this->_stack.top();
    this->_stack.pop();
    int first = this->_stack.top();
    this->_stack.pop();
    if (!second) throw Expr_Tree_Evaluator::modulo_by_zero_exception(first);
    this->_stack.push(first % second);
}
