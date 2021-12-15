#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

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

// Assigning action buttons triggers
void MainWindow::on_actionNew_triggered(){
    file_path_ = ""; // When someone clicks "New" file path reset
    ui->textEdit->setText(""); // When someone clicks "New" text box clears
}

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

// Cut, Copy, Paste, Redo, & Undo are simply built into the textEdit Feature

void MainWindow::on_actionCut_triggered(){
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered(){
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered(){
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered(){
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered(){
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_NotepadZ_triggered(){
    QString about_text; //creates string
    about_text =  "Author : Nichoals Cotugno\n";
    about_text += "Date   : 11/24/2021\n";
    about_text += "Icons  : https://www.flaticon.com/\n";
    about_text += "(C) NotepadZ (R)\n";
    QMessageBox::about(this,"About NotepadZ",about_text); //LO2. Uses the "about" subclass from QmessageBox
}

