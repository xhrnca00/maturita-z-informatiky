#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString jmeno=QFileDialog::getOpenFileName();
    QMessageBox::information(this,"Co sis vybral",jmeno);
}


void MainWindow::on_actionSave_triggered()
{
    QString jmeno=QFileDialog::getSaveFileName();
    QMessageBox::information(this,"Co sis vybral",jmeno);
}


void MainWindow::on_actiongetDouble_triggered()
{
    double cislo=QInputDialog::getDouble(this,"Vstup",
                  "Zadej desetinné číslo");
    QMessageBox::information(this,"Co jsi zadal",
                   "Bylo zadáno "+QString::number(cislo));
}

