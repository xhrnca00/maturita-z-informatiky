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


void MainWindow::on_actionVyjmout_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionKop_rovat_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionVlo_it_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionUkon_it_triggered()
{
    this->close();
}


void MainWindow::on_actionO_programu_triggered()
{
    QMessageBox::about(this,"O programu",
         "SuperNotepad v.3.14\n2024 (c) Hugo Kokoška");
}


void MainWindow::on_actionOtev_t_triggered()
{
    QString jmenoSouboru;
    jmenoSouboru=QFileDialog::getOpenFileName();

    if(jmenoSouboru!=""){
        QFile file(jmenoSouboru);
        if (!file.open (QIODevice::ReadOnly | QIODevice::Text)) return;
        QTextStream in(&file);
        QString textik = in.readAll();
        ui->textEdit->setText(textik);
        file.close();
    }
}


void MainWindow::on_actionUlo_it_jako_triggered()
{
    QString jmenoSouboru;
    jmenoSouboru=QFileDialog::getSaveFileName();

    if(jmenoSouboru!=""){
        QFile file(jmenoSouboru);
        if (!file.open (QIODevice::WriteOnly | QIODevice::Text)) return;
        QTextStream out(&file);
        QString textik = ui->textEdit->toPlainText();
        out<<textik;
        file.close();
    }
}


void MainWindow::on_actionNov_triggered()
{
    ui->textEdit->clear();
}

