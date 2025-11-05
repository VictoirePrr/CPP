#include "RPN.hpp"

RPN::RPN() {

}

// RPN::RPN(const RPN& other) {

//     *this = other;
// }

// RPN& RPN::operator=(const RPN& other) {

//     if (this != &other) {
//         // copy attributes here
//     }
//     return *this;
// }

RPN::~RPN() {
}

void RPN::parseExpr(char c) {

    if (c == ' ')
        return ;
    if (c >= '0' && c <= '9')
        return ;
    findOp(c);
    if (_op.empty())
        throw std::invalid_argument("ERROR");
    return ;
}

void RPN::polishOp(std::string expr) {

    _res = 0;

    for (size_t i = 0; i < expr.length(); i++) {
        if(!isdigit(expr[i]) && expr[i] != ' ') {
            findOp(expr[i]);
            std::cout << _op << std::endl;
            while (!_compute.empty()) {
                _res = _compute.top();
                _compute.pop();
                //add an if statement for seg fault
                doOp(_op[0], _compute.top());

            }
            _compute.pop();
            std::cout << "res in polishOp : " << _res << std::endl;
            _compute.push(_res);

        }
        else if (expr[i] == ' ')
            continue;
        else {
            _num = expr[i] - '0';
            _compute.push(_num);
        }
    }

    std::cout << _res << std::endl;
}

void RPN::findOp(char c) {
    switch(c) {
        case '+' : _op = '+';
        case '-' : _op = '-';
        case '/' : _op = '/';
        case '*' : _op = '*';
        default:
            break;
    }
}

void RPN::doOp(char op, int &top) {
    std::cout << "res in doOp : " << _res << std::endl;

     switch(op) {
        case '+' : _res += top;
        case '-' : _res -= top;
        case '/' : _res /= top;
        case '*' : _res *= top;
        default:
            break;
    }
}