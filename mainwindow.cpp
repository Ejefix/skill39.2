#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegularExpression>
#include <QLineEdit>

const QRegularExpression MainWindow::line_telefon("^\\+[0-9]{9}$"); // или так ("^\\+\\d{9}$")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textChanged,this,&MainWindow::control);
    control();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::control()
{
    QString digit = ui->lineEdit->text();
    if (line_telefon.match( digit ) .hasMatch())
    {
        ui->label->setText("Telefon: true");
        ui->label->setStyleSheet("color: green;");
    }
    else {
        ui->label->setText("Telefon: false");
        ui->label->setStyleSheet("color: red;");
    }
}

