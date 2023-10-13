
#ifndef TEST_H
#define TEST_H


#include <QObject>
#include <QtTest/QTest>


class Test :public QObject
{
    Q_OBJECT
private slots:
    void testDecimalCalculation();
    void testComplexCalculation();
    void testBracketCalculation();
    void testSimpleSinCalculation();
    void testComplexSinCalculation();
};

#endif // TEST_H
