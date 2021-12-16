/** @file main.cpp
 *  @brief main file of notepadZ program
 *
 *  The main file of my Qt notepad program simply opens the
 *  mainwindow including the notepad application. It also sets the
 *  title of the window to 'NotePadZ' shown on line 19.
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
