#ifndef _Expr_NODE_VISITOR_H_
#define _Expr_NODE_VISITOR_H_

class num_Node_P;
class add_Node_P;
class sub_Node_P;
class mul_Node_P;
class div_Node_P;
class mod_Node_P;

/**
*   @class Expression Node Visitor
*
*   An abstract visitor that specifically visits expression nodes
*/
class Expr_Node_Visitor {

    public:

        Expr_Node_Visitor(void) {}

        // Destructor (virtual)
        virtual ~Expr_Node_Visitor(void) {};

        // Copy constructor (deleted)
        Expr_Node_Visitor(const Expr_Node_Visitor &) = delete;

        // Equals operator (deleted)
        const Expr_Node_Visitor & operator = (const Expr_Node_Visitor &) = delete;

        /**
        *   Visit a number node
        *
        *   @param: number node             node representing an integer value
        */
        virtual void visit_number_node(num_Node_P *) = 0;

        /**
        *   Visit a add node
        *
        *   @param: add node                node representing the add operator
        */
        virtual void visit_add_node(add_Node_P *) = 0;

        /**
        *   Visit a subtract node
        *
        *   @param: subtract node           node representing the subtract operator
        */
        virtual void visit_subtract_node(sub_Node_P *) = 0;

        /**
        *   Visit a multiply node
        *
        *   @param: multiply node           node representing the multiply operator
        */
        virtual void visit_multiply_node(mul_Node_P *) = 0;

        /**
        *   Visit a divide node
        *
        *   @param: divide node             node representing the divide operator
        */
        virtual void visit_divide_node(div_Node_P *) = 0;

        /**
        *   Visit a modulo node
        *
        *   @param: modulo node             node representing the modulo operator
        */
        virtual void visit_modulo_node(mod_Node_P *) = 0;
};

#endif   // !defined _Expr_NODE_VISITOR_H_
