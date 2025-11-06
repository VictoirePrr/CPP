#include "RPN.hpp"

RPN::RPN() {

}

RPN::RPN(const RPN &other) {
    (void)other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
    {
        (void)other;
    }
    return *this;
}

RPN::~RPN() {
}

void RPN::parseExpr(std::string expr) {

    int countop = 0;
    int countnum = 0;
    if (expr.length() == 1 && isdigit(expr[0]))
        return;
    
    findOp(expr[expr.length() - 1]);
    if (_op.empty() && expr[expr.length() - 1] != ' ') {
        throw std::invalid_argument("Error");
                    return ;
    }

    for (size_t i = 0; i < expr.length(); i++) {
            if (expr[i] >= '0' && expr[i] <= '9') {
                countnum++;
                i++;
                if (expr[i] != ' ') {
                    throw std::invalid_argument("Error");
                    return ;
                }
            }

            if (expr[i] != ' ' && !isalpha(expr[i])) {
                findOp(expr[i]);
                if (_op.empty()) {
                    throw std::invalid_argument("Error");
                    return ;
                }
                countop++;
            }
    }

    if (countnum != countop + 1) {
        throw std::invalid_argument("Error");
                    return ;
    }
    
}

void RPN::polishOp(std::string expr) {

    _res = 0;

    for (size_t i = 0; i <= expr.length(); i++) {
        if(!isdigit(expr[i]) && expr[i] != ' ') {

            findOp(expr[i]);
            if (!_compute.empty()) {
                _res = _compute.top();
                _compute.pop();

                if (!_compute.empty()) {
                    doOp(_op[0], _compute.top());
                    _compute.pop();
                }
            }
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
            break;
        case '-' : _op = '-';
            break;
        case '/' : _op = '/';
            break;
        case '*' : _op = '*';
            break;
        default:
            break;
    }
}

void RPN::doOp(char op, int &top) {

     switch(op) {
        case '+' : _res = top + _res;
            break;
        case '-' : _res = top - _res;
            break;
        case '/' : _res /= top;
            break;
        case '*' : _res = top * _res;
            break;
        default: 
            break;
    }
}