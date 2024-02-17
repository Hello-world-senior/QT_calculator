A simple example of a calculator in QT.

So you can download Qt on the official site https://www.qt.io 

I made a calculator on mingw 6.4

This calculator has such functions of addition, subtraction, multiplication, division. Looking at the example of the mathematical function and the on_Equal_button_clicked function(In the file mainwindow.cpp ) you can easily add a couple more things to this calculator. But I'm too lazy .(Root , Degrees , Percentage of the number)

All the main functions are declared in the mainwindow.h file. 

In the file mainwindow.cpp All function bodies and the main program. 

In the file main.cpp I did not change anything (The standard code, as when creating an application on qt) 
int main(int argc, char *argv[])
{
QApplication a(argc, argv);
 MainWindow w;
 w.show();
 return a.exec();
}

In the mainwindow.ui file, the program interface
