
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow

{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
    double solve(std::string);
    std::string getMode();

private slots:
    void onPushButtonClearClicked();
    void onPushButtonOtherButtonClicked();
    void onPushButtonEqualsClicked();
    void onPushButtonDeleteClicked();
    void onPushButtonPiClicked();
    void onPushButtonSinClicked();
    void onPushButtonCosClicked();
    void onPushButtonTanClicked();

private:
    Ui::Calculator *ui;

};
static int CalculatorMode{};

#endif // CALCULATOR_H
