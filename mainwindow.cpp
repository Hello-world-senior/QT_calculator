#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Zero_button,SIGNAL(clicked(bool)), this , SLOT(digits_numbers()));
    connect(ui->One_button,SIGNAL(clicked(bool)), this , SLOT(digits_numbers()));
    connect(ui->Two_button,SIGNAL(clicked(bool)), this , SLOT(digits_numbers()));
    connect(ui->three_button,SIGNAL(clicked(bool)), this , SLOT(digits_numbers()));
    connect(ui->Four_button,SIGNAL(clicked(bool)), this , SLOT(digits_numbers()));
    connect(ui->Five_button,SIGNAL(clicked(bool)), this , SLOT(digits_numbers()));
    connect(ui->Six_button,SIGNAL(clicked(bool)), this , SLOT(digits_numbers()));
    connect(ui->Seven_button,SIGNAL(clicked(bool)), this , SLOT(digits_numbers()));
    connect(ui->Eight_button,SIGNAL(clicked(bool)), this , SLOT(digits_numbers()));
    connect(ui->Nine_button,SIGNAL(clicked(bool)), this , SLOT(digits_numbers()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){

    QPushButton *button = (QPushButton * )sender() ;

    double all_numbers ;
    QString new_label ;
    all_numbers = (ui->label->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers , 'g' , 15);

    ui -> label->setText(new_label);
}

