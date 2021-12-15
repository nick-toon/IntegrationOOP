#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form; // LO1: Design and implement a class
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();


private:
    Ui::Form *ui;
};

#endif // FORM_H
