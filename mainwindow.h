#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots :
        void digits_numbers();
        void math_operations();
        void on_Dot_button_clicked();
        void operations();
        void on_Equal_button_clicked();
        void on_Ac_button_clicked();
};
#endif // MAINWINDOW_H
