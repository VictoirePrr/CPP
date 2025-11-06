#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <stack>
#include <sstream>


class RPN {

    private:

        int _num;
        int _res;
        std::string _op;
        std::stack<int> _compute;

    public:

        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void parseExpr(std::string expr);
        void polishOp(std::string expr);
        void findOp(char c);
        void doOp(char op, int &top);

};

#endif
