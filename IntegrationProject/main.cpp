/* Nicholas Cotugno
 * LO1: Compare/Contrast of procededural/functional programing vs OOP
 * In procedural/functional programming, programs are divided
 * into functions while OOP is divided into objects.
 * Procedural/functional is top down and OOP is bottom up
 * OOP uses access specifiers like public, private, and protected.Procedural/functional does not.
 * OOP can use overloading, procedural/functional can not.
*/

#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Integration Project");
    w.show();
    return a.exec();
}
