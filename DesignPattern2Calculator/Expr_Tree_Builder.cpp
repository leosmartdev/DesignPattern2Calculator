#include <string>

#include "Stack.h"
#include "Queue.h"
#include "Expr_Node.h"
#include "Expr_Tree_Builder.h"
#include "num_Node_P.h"
#include "add_Node_P.h"
#include "sub_Node_P.h"
#include "mul_Node_P.h"
#include "div_Node_P.h"
#include "mod_Node_P.h"

using std::string;

//  default constructor
Expr_Tree_Builder::Expr_Tree_Builder() : _tree(NULL), _sub_tree_stack(Stack<Expr_Node*>()) 
{
    //...
}

//  build_expression
void Expr_Tree_Builder::build_expression(Queue<std::string> & postfix_queue) 
{
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

    this->_tree = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
}

//  get_expression
Expr_Node * Expr_Tree_Builder::get_expression() 
{
    // return root node of tree
    return this->_tree;
}

//  build_number_node
void Expr_Tree_Builder::build_number_node(int num) 
{
    Expr_Node * node = new num_Node_P(num);
    this->_sub_tree_stack.push(node);
}

//  build_add_node
void Expr_Tree_Builder::build_add_node() 
{
    Expr_Node * second = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
    Expr_Node * first = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
    Expr_Node * parent = new add_Node_P(first, second);
    this->_sub_tree_stack.push(parent);
}

//  build_subtract_node
void Expr_Tree_Builder::build_subtract_node() 
{
    Expr_Node * second = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
    Expr_Node * first = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
    Expr_Node * parent = new sub_Node_P(first, second);
    this->_sub_tree_stack.push(parent);
}

//  build_multiply_node
void Expr_Tree_Builder::build_multiply_node() 
{
    Expr_Node * second = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
    Expr_Node * first = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
    Expr_Node * parent = new mul_Node_P(first, second);
    this->_sub_tree_stack.push(parent);
}

//  build_divide_node
void Expr_Tree_Builder::build_divide_node() 
{
    Expr_Node * second = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
    Expr_Node * first = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
    Expr_Node * parent = new div_Node_P(first, second);
    this->_sub_tree_stack.push(parent);
}

//  build_modulo_node
void Expr_Tree_Builder::build_modulo_node() 
{
    Expr_Node * second = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
    Expr_Node * first = this->_sub_tree_stack.top();
    this->_sub_tree_stack.pop();
    Expr_Node * parent = new mod_Node_P(first, second);
    this->_sub_tree_stack.push(parent);
}
