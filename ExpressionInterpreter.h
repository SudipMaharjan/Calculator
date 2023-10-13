
#ifndef EXPRESSIONINTERPRETER_H
#define EXPRESSIONINTERPRETER_H
#include <iostream>
using namespace std;
#include <cmath>



class ExpressionInterpreter
{
private:
    const char* C_expression;
    double answer;
    int mode;

public:
    ExpressionInterpreter();
    ~ExpressionInterpreter();
    void setMode(int m);
    void setExpression(const char *);
    char getPointedCharacter();
    void pointToNextCharacter();
    double getAnswer();
    void calculateAnswer(int m);
    double expression();
    double number();
    double term();
    double factor();
    double WinkelFunction();
    double WinkelFunctionSin();
    double WinkelFunctionCos();
    double WinkelFunctionTan();
};
double GradToRad(double);
double GonToRad(double);


#endif // EXPRESSIONINTERPRETER_H
