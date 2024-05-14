#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    double A, B, C;
    double promile, cas;
    A = ui->doubleSpinBox->value();
    B = ui->doubleSpinBox_2->value();
    C = ui->doubleSpinBox_3->value();

    promile = (A * B * 0.8) / (C * 0.68);
    cas = promile / 0.15;

    QMessageBox::information(
        this,
        "Jak moc seš vožralej",
        "Máš " + QString::number(promile) + " promile a budeš střízlivět "
            + QString::number(cas) + " hodin"
    );
}
