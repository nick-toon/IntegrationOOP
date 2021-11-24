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
