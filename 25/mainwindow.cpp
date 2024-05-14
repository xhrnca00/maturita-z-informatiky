#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMEssageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_calcB_clicked() {
    double A = ui->amtIn->value();
    double B = ui->percIn->value();
    double C = ui->massIn->value();
    double res = (A * B * 0.8) / (C * 0.68);
    double timeToSober = res / 0.15;
    QMessageBox::information(
        this,
        "Výsledek",
        "V krvi máte " + QString::number(res) + " promile alkoholu.\nVystřízlivíte za "
            + QString::number(timeToSober) + " hodin"
    );
}
