/** @file mainwindow.cpp
 *  @brief The mainwindow file for my NotepadZ app
 *
 *  This file contains all of the functions for the notepad
 *  application. It includes many trigger functions from
 *  the mainwindow.ui in Qt. The trigger function ties the
 *  buttons in the ui to a function. These functions have all
 *  specific uses. For example, New File or Save.
 *
 *  @author Nicholas Cotugno
 *  @bug No known bugs.
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit); //Gets rid of white space on both sides of textboxt
}

MainWindow::~MainWindow()
{
    delete ui;
}

/** @brief Assigning action button to new file
 *
 *  When someone clicks "New" file path reset.
 *  When someone clicks "New" text box clears
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionNew_triggered(){
    file_path_ = "";
    ui->textEdit->setText("");
}

/** @brief Assigning action button to open file
 *
 * This function opens the explorer, checks if the file
 * is open and if not gives an error message
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionOpen_file_triggered(){
    QString file_name = QFileDialog::getOpenFileName(this, "Open the file"); //Opens explorer
    QFile file(file_name); //Gets name from explorer
    file_path_ = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){ //checks if file is open
        QMessageBox::warning(this,"..","file not open"); //error message
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll(); //passes stream to string
    ui->textEdit->setText(text); //passes text to edit text
    file.close(); //closes file
}

/** @brief Assigning action button to save file
 *
 * This function is built to save the content
 * in the notepad. It will check if it saved,
 * if not it will display an error
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionSave_triggered(){
    QFile file(file_path_);
    if(!file.open(QFile::WriteOnly | QFile::Text)){ //checks if file is saved
        QMessageBox::warning(this,"..","file not saved"); // error message
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text; //gives stream to string
    file.flush(); //clears the internal buffer of the file
    file.close(); //closes file
}

/** @brief Assigning action button to save as
 *
 * This function is built for the save as function,
 * when saving a new document. It opens the explorer
 * and allows the user to enter a doc name.
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionSave_as_triggered(){
    QString file_name = QFileDialog::getSaveFileName(this, "Save the file as"); //Opens explorer to save file
    QFile file(file_name);
    file_path_ = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not saved"); //error message
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text; //gives stream to text
    file.flush(); //clears the internal buffer of the file
    file.close(); //closes file
}

/** @brief Assigning action button to cut
 *
 * Basic cut function. This function is already
 * built into the program. Simply calling it
 * makes it work as intented.
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionCut_triggered(){
    ui->textEdit->cut();
}
/** @brief Assigning action button to copy
 *
 * Basic copy function. This function is already
 * built into the program. Simply calling it
 * makes it work as intented.
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionCopy_triggered(){
    ui->textEdit->copy();
}
/** @brief Assigning action button to paste
 *
 * Basic paste function. This function is already
 * built into the program. Simply calling it
 * makes it work as intented.
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionPaste_triggered(){
    ui->textEdit->paste();
}

/** @brief Assigning action button to redo
 *
 * Basic redo function. This function is already
 * built into the program. Simply calling it
 * makes it work as intented.
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionRedo_triggered(){
    ui->textEdit->redo();
}
/** @brief Assigning action button to undo
 *
 * Basic undo function. This function is already
 * built into the program. Simply calling it
 * makes it work as intented.
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionUndo_triggered(){
    ui->textEdit->undo();
}
/** @brief Assigning action button to about section
 *
 * This function displays text, showing the user
 * what the program is 'about' and information.
 * Uses Qmessaagebox library.
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionAbout_NotepadZ_triggered(){
    QString about_text; //creates string
    about_text =  "Author : Nichoals Cotugno\n";
    about_text += "Date   : 11/24/2021\n";
    about_text += "Icons  : https://www.flaticon.com/\n";
    about_text += "(C) NotepadZ (R)\n";
    QMessageBox::about(this,"About NotepadZ",about_text); //uses the "about" subclass from QmessageBox
}

/** @brief Assigning action button to font
 *
 * This function allows the user to change the font
 * of the text in the notepad app. By opening the
 * QFontDialog it allows the user to change the text
 * in a numerous amount of ways
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionFont_triggered(){
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok){ //checks if font is selected or not
        ui->textEdit->setFont(font);
    }else return;
}

/** @brief Assigning action button to color
 *
 * This function allows the user to change the color
 * of the text in the notepad app. By opening the
 * QColorDialog it allows the user to change the color
 * of the text in a numerous amount of ways
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionColor_triggered(){
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid()){
        ui->textEdit->setTextColor(color);
    }else return;
}
/** @brief Assigning action button to highlight text
 *
 * This function allows the user highlight their text
 * in the notepad app. By opening the QColorDialog it allows
 * the user to change the highlight color of the text
 * in a numerous amount of ways by calling the setTextBackgroundColor function
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionBackground_Color_triggered(){
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid()){
        ui->textEdit->setTextBackgroundColor(color);
    }else return;
}

/** @brief Assigning action button to change background color
 *
 * This function allows the user to change the color of the bg
 * in the notepad app. By opening the QColorDialog it allows
 * the user to change the background color of the app
 * in a numerous amount of ways by calling the setPalette function
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionBackgroundColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid()){
        ui->textEdit->setPalette(QPalette(color));
    }else return;
}

/** @brief Assigning action button to print
 *
 * This function allows the user to print their
 * doc from the notepad app. By creating a printer object
 * and then using QPrintDialog to open the printer menu.
 *
 *  @param none
 *  @return nothing
 */
void MainWindow::on_actionPrint_triggered(){
    QPrinter printer; //declaring object printer
    printer.setPrinterName("Printer name");
    QPrintDialog dialog(&printer,this); //shows options
    if(dialog.exec() == QDialog::Rejected) return; //checks chosen printer
    ui->textEdit->print(&printer);
}

