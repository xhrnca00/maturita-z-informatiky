#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->btn0, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->btn2, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->btn3, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->btn4, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->btn5, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->btn6, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->btn7, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->btn8, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->btn9, SIGNAL(clicked()), this, SLOT(numberClicked()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_nulSum_clicked() {
    ui->sumF->setText("0");
}

void MainWindow::on_nulMem_clicked() {
    ui->memF->setText("0");
}

void MainWindow::on_btnPlus_clicked() {
    auto res = QString::number(ui->sumF->text().toInt() + ui->memF->text().toInt());
    ui->sumF->setText(res);
    ui->memF->setText("0");
}

void MainWindow::on_btnMinus_clicked() {
    auto res = QString::number(ui->sumF->text().toInt() - ui->memF->text().toInt());
    ui->sumF->setText(res);
    ui->memF->setText("0");
}

void MainWindow::numberClicked() {
    QString num = ((QPushButton *)sender())->text();
    QString curr = ui->memF->text();
    if (curr == "0")
        curr = num;
    else
        curr += num;
    ui->memF->setText(curr);
}
