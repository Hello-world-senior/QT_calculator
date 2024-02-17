#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Percent_button,SIGNAL(clicked(bool)), this , SLOT(operations()));
    connect(ui->Negative_button,SIGNAL(clicked(bool)), this , SLOT(operations()));
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
    connect(ui->Plus_button,SIGNAL(clicked(bool)), this , SLOT(math_operations()));
    connect(ui->Division_button,SIGNAL(clicked(bool)), this , SLOT(math_operations()));
    connect(ui->Minus_button,SIGNAL(clicked(bool)), this , SLOT(math_operations()));
    connect(ui->Multip_button,SIGNAL(clicked(bool)), this , SLOT(math_operations()));

    ui->Multip_button->setCheckable(true);
    ui->Division_button->setCheckable(true);
    ui->Minus_button->setCheckable(true);
    ui->Plus_button->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){

    QPushButton * button = (QPushButton * )sender() ;

    double all_numbers ;
    QString new_label ;
    all_numbers = (ui->label->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers , 'g' , 15);

    ui -> label->setText(new_label);
}
void MainWindow::math_operations(){

    QPushButton * button = (QPushButton * )sender() ;
    num_first = ui->label->text().toDouble() ;
    ui->label->setText(" ");
    button->setCheckable(true);
}


void MainWindow::on_Dot_button_clicked()
{
    if(ui->label->text().contains('.') == false)
    ui -> label->setText(ui -> label->text() + '.');
}

void MainWindow::operations()
{
    QPushButton * button = (QPushButton * )sender() ;

    double all_numbers ;
    QString new_label ;
    if(button->text() == "+/-"){
    all_numbers = (ui->label->text()).toDouble();
        all_numbers *= -1 ;
    new_label = QString::number(all_numbers , 'g' , 15);

    ui -> label->setText(new_label);
    }   else if(button->text() == "%"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers *= 0.01 ;
        new_label = QString::number(all_numbers , 'g' , 15);

        ui -> label->setText(new_label);
    }
}




void MainWindow::on_Equal_button_clicked()
{
    double num_second , label_number ;
    QString new_label ;
    num_second = ui->label->text().toDouble() ;
    if(ui->Plus_button->isChecked()){
         label_number = num_first + num_second  ;
        new_label = QString::number(label_number , 'g' , 15);

        ui -> label->setText(new_label);
        ui->Plus_button->setChecked(false);
    }else     if(ui->Minus_button->isChecked()){
        label_number = num_first - num_second  ;
        new_label = QString::number(label_number , 'g' , 15);

        ui -> label->setText(new_label);
        ui->Minus_button->setChecked(false);

    }else     if(ui->Division_button->isChecked()){
        if(num_second == 0 || num_first == 0 ){
            ui -> label->setText("Не делится на ноль");
            ui->Division_button->setChecked(false);
        }else {
             label_number = num_first / num_second  ;
        new_label = QString::number(label_number , 'g' , 15);

        ui -> label->setText(new_label);
        ui->Division_button->setChecked(false);
        }

}   else     if(ui->Multip_button->isChecked()){
        label_number = num_first * num_second  ;
        new_label = QString::number(label_number , 'g' , 15);

        ui -> label->setText(new_label);
        ui->Multip_button->setChecked(false);

}

}

