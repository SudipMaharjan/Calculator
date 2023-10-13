
#include "test.h"
#include "ExpressionInterpreter.h"
#include "QtTest/qtestcase.h"

void Test::testDecimalCalculation()
{
    ExpressionInterpreter expressionenInterpreter;
    expressionenInterpreter.setExpression(" 3*5+2.5=");
    expressionenInterpreter.calculateAnswer(1);
    QCOMPARE(expressionenInterpreter.getAnswer(),17.5);
}
void Test::testSimpleSinCalculation(){
    ExpressionInterpreter expressionenInterpreter;
    expressionenInterpreter.setExpression(" sin(30)=");
    expressionenInterpreter.calculateAnswer(1);
    QCOMPARE(expressionenInterpreter.getAnswer(),0.5);
}
void Test::testBracketCalculation(){
    ExpressionInterpreter expressionenInterpreter;
    expressionenInterpreter.setExpression(" (2+2)*3=");
    expressionenInterpreter.calculateAnswer(1);
    QCOMPARE(expressionenInterpreter.getAnswer(),12);
}

void Test::testComplexCalculation(){
    ExpressionInterpreter expressionenInterpreter;
    expressionenInterpreter.setExpression(" (2+2)*3=");
    expressionenInterpreter.calculateAnswer(1);
    QCOMPARE(expressionenInterpreter.getAnswer(),12);
}
void Test::testComplexSinCalculation(){
    ExpressionInterpreter expressionenInterpreter;
    expressionenInterpreter.setExpression(" sin(30+60)=");
    expressionenInterpreter.calculateAnswer(1);
    QCOMPARE(expressionenInterpreter.getAnswer(),1);
}

