
#include "ExpressionInterpreter.h"

ExpressionInterpreter::ExpressionInterpreter()
{}

ExpressionInterpreter::~ExpressionInterpreter(){

}

void ExpressionInterpreter::setExpression(const char *expression){
    this->C_expression = expression;
}

void ExpressionInterpreter::setMode(int m){
    this->mode = m;
}

char ExpressionInterpreter::getPointedCharacter()
{
    return *C_expression;
}

void ExpressionInterpreter::pointToNextCharacter()
{
    C_expression++;
}

double ExpressionInterpreter::getAnswer(){
    return answer;
}

void ExpressionInterpreter::calculateAnswer(int m){
    setMode(m);
    do{
        pointToNextCharacter();
        if(getPointedCharacter() != '='){
            this->answer = expression();
        }
    }while(getPointedCharacter() != '=');
}

double ExpressionInterpreter::number()
{
    double result = 0.0;
    while (isdigit(getPointedCharacter()))
    {
        result = 10*result + long(getPointedCharacter() - '0');
        pointToNextCharacter();
    }
    if(getPointedCharacter() == '.'){
        pointToNextCharacter();
        double nachkommastelle = 1.0;
        while(isdigit(getPointedCharacter())){
        nachkommastelle *=10.0;
        result = result +double(getPointedCharacter() - '0') / nachkommastelle;
        pointToNextCharacter();
        }
    }
    else if (getPointedCharacter() == 'p'){
        result = M_PI;
        pointToNextCharacter();
    }
    else if(getPointedCharacter() =='s'){
        result = WinkelFunctionSin();
    }
    else if(getPointedCharacter() =='c'){
        result = WinkelFunctionCos();
    }
    else if(getPointedCharacter() =='t'){
        result = WinkelFunctionTan();
    }
    return result;
}

double ExpressionInterpreter::factor()
{

    double result;
    if (getPointedCharacter() == '(')
    {
        pointToNextCharacter(); // '('
        result = expression();
        pointToNextCharacter(); // ')'
    }
    else
    {
        result = number();
    }
    return result;
}

double ExpressionInterpreter::term()
{
    double tmp;
    double result = factor();
    while (getPointedCharacter() == '*' || getPointedCharacter() == '/'){
        if (getPointedCharacter() == '*'){
        pointToNextCharacter();
            result *= factor();
        }
        else{
            pointToNextCharacter();
            tmp = factor();
            if(tmp!=0)
            result /= tmp;
        }
    }
    return result;
}

double ExpressionInterpreter::expression()
{
    double result;
    if(getPointedCharacter() == '-'){
        pointToNextCharacter();
        result = -term();
    }
    else{
        if(getPointedCharacter()== '+'){
            pointToNextCharacter();
        }
        result = term();
    }
    while(getPointedCharacter()=='+' || getPointedCharacter() == '-'){
        if(getPointedCharacter()=='+'){
            pointToNextCharacter();
            result += term();
        }
        else{
            pointToNextCharacter();
            result -= term();
        }
    }
    return result;
}

double ExpressionInterpreter::WinkelFunction(){

    pointToNextCharacter();
    pointToNextCharacter();
    pointToNextCharacter();

    double argument = 0.0;
    if(mode == 1){
        argument = GradToRad(expression());
    }
    else if(mode == 2){
        argument = GonToRad(expression());
    }
    else{
        argument = expression();
    }
    return argument;
}

double ExpressionInterpreter::WinkelFunctionSin(){
    double result;
    double temp = WinkelFunction();
    result = std::sin(temp);

    return result;
}

double ExpressionInterpreter::WinkelFunctionCos(){
    double result;
    double temp = WinkelFunction();
    result = std::cos(temp);

    return result;
}

double ExpressionInterpreter::WinkelFunctionTan(){
   double result1,result2, result{};
    result1 = std::sin(WinkelFunction());
    result2 = std::cos(WinkelFunction());
    if(result2 != 0){
        result = result1/result2;
    }
    return result;
}

double GradToRad(double Grad){
    return Grad * M_PI / 180.0;
}
double Pi(){
    return M_PI;
}

double GonToRad(double Gon){
    return Gon * M_PI / 200.0;
}
