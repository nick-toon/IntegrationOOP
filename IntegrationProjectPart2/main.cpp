/** @file main.cpp
 *  @brief main file of notepadZ program
 *
 *  The main file of my Qt notepad program simply opens the
 *  mainwindow including the notepad application. It also sets the
 *  title of the window to 'NotePadZ' shown on line 19.
 *
 * LO4: Compare/Contrast of procededural/functional programing vs OOP
 * In procedural/functional programming, programs are divided
 * into functions while OOP is divided into objects.
 * Procedural/functional is top down and OOP is bottom up
 * OOP uses access specifiers like public, private, and protected.Procedural/functional does not.
 * OOP can use overloading, procedural/functional can not.
 *
 *  @author Nicholas Cotugno
 *  @bug No known bugs.
 */
 
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("NotepadZ"); //Sets window title to "NotepadZ"
    //w.setWindowIcon(QIcon('notepad.png')); Tried to set window icon, will figure out in next milestone
    w.show();

    return a.exec();
}
