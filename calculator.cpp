
#include "calculator.h"
#include "ExpressionInterpreter.h"
#include "ui_calculator.h"
#include <string>
#include<iostream>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    ui->radioButton_Rad->setChecked(true);
    connect(ui->pushButton_0, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_1, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_3, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_4, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_5, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_6, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_7, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_8, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_9, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_Point, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_Plus, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_Minus, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_Multiply, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_Divide, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_LeftBracket, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);
    connect(ui->pushButton_RightBracket, &QPushButton::clicked,this,&Calculator::onPushButtonOtherButtonClicked);

    connect(ui->pushButton_Sin, &QPushButton::clicked,this,&Calculator::onPushButtonSinClicked);
    connect(ui->pushButton_Cos, &QPushButton::clicked,this,&Calculator::onPushButtonCosClicked);
    connect(ui->pushButton_Tan, &QPushButton::clicked,this,&Calculator::onPushButtonTanClicked);
    connect(ui->pushButton_Pi, &QPushButton::clicked,this,&Calculator::onPushButtonPiClicked);

    connect(ui->pushButton_Delete, &QPushButton::clicked,this,&Calculator::onPushButtonDeleteClicked);
    connect(ui->pushButton_Clear, &QPushButton::clicked,this,&Calculator::onPushButtonClearClicked);
    connect(ui->pushButton_Equals, &QPushButton::clicked,this, &Calculator::onPushButtonEqualsClicked);
}
void Calculator::onPushButtonClearClicked(){
    ui->Result->setText("0");
    ui->Input->setText(" ");
}

void Calculator::onPushButtonOtherButtonClicked(){

    QPushButton* button = (QPushButton*)sender();
    ui->Input->setText(ui->Input->text()+ button->text());
}

void Calculator::onPushButtonPiClicked(){
    ui->Input->setText(ui->Input->text() + "p");
}

void Calculator::onPushButtonSinClicked(){
    ui->Input->setText(ui->Input->text() + "sin(");
}

void Calculator::onPushButtonCosClicked(){
    ui->Input->setText(ui->Input->text() + "cos(");
}

void Calculator::onPushButtonTanClicked(){
    ui->Input->setText(ui->Input->text() + "tan(");
}

void Calculator::onPushButtonDeleteClicked(){
    std::string currentInput = ui->Input->text().toStdString();
    if(currentInput.length()){
        currentInput = currentInput.substr(0,currentInput.length()-1);
    }
    ui->Input->setText(QString::fromStdString(currentInput));
}

void Calculator::onPushButtonEqualsClicked()
{
    if(ui->radioButton_Grad->isChecked()){
        CalculatorMode = 1;
    }
    else if(ui->radioButton_Gon->isChecked()){
        CalculatorMode = 2;
    }
    else{
        CalculatorMode = 3;
    }
    std::string terminator = "=";
    std::string S_expression = ui->Input->text().toStdString() + terminator;

    const char* expressionCArray = S_expression.c_str();

    ExpressionInterpreter expressionInterpreter;
    expressionInterpreter.setExpression(expressionCArray);
    expressionInterpreter.calculateAnswer(CalculatorMode);

    ui->Result->setText(QString::number(expressionInterpreter.getAnswer()));
}

Calculator::~Calculator()
{
    delete ui;
}

