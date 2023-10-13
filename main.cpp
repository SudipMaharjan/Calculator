
#include "calculator.h"
#include "test.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.show();

    Test test;
    QTest::qExec(&test);

    return a.exec();
}
