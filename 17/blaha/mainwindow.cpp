#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn0,SIGNAL(clicked()),
           this,SLOT(stiskCiselnehoTlacitka()));
    connect(ui->btn1,SIGNAL(clicked()),
           this,SLOT(stiskCiselnehoTlacitka()));
    connect(ui->btn2,SIGNAL(clicked()),
           this,SLOT(stiskCiselnehoTlacitka()));
    connect(ui->btn3,SIGNAL(clicked()),
           this,SLOT(stiskCiselnehoTlacitka()));
    connect(ui->btn4,SIGNAL(clicked()),
           this,SLOT(stiskCiselnehoTlacitka()));
    connect(ui->btn5,SIGNAL(clicked()),
           this,SLOT(stiskCiselnehoTlacitka()));
    connect(ui->btn6,SIGNAL(clicked()),
           this,SLOT(stiskCiselnehoTlacitka()));
    connect(ui->btn7,SIGNAL(clicked()),
           this,SLOT(stiskCiselnehoTlacitka()));
    connect(ui->btn8,SIGNAL(clicked()),
           this,SLOT(stiskCiselnehoTlacitka()));
    connect(ui->btn9,SIGNAL(clicked()),
           this,SLOT(stiskCiselnehoTlacitka()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText("0");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_2->setText("0");
}

void MainWindow::stiskCiselnehoTlacitka()
{
    if(ui->lineEdit_2->text()=="0")
        ui->lineEdit_2->setText(
               ((QPushButton *)sender())->text()
        );
        else
        ui->lineEdit_2->setText(
            ui->lineEdit_2->text()
            +(
                ((QPushButton *)sender())->text()
              )
        );
}

void MainWindow::on_bntPlus_clicked()
{
    // this does not work, IDK why
    ui->lineEdit->setText(
        QString::number(ui->lineEdit->text().toInt() + ui->lineEdit_2->text().toInt())
    );
}


void MainWindow::on_btnMinus_clicked()
{
    ui->lineEdit->setText(
      QString::number(
         ui->lineEdit->text().toInt()
         -
         ui->lineEdit_2->text().toInt()
      )
    );
}

