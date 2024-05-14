#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionOpen_triggered() {
    QString s = QFileDialog::getOpenFileName(this, "Otevřít");
    QMessageBox::information(this, "Value", s);
}

void MainWindow::on_actionSave_triggered() {
    QString s = QFileDialog::getSaveFileName(this, "Uložit");
    QMessageBox::information(this, "Value", s);
}

void MainWindow::on_actionCritical_triggered() {
    QMessageBox::critical(this, "Critical", "Velmi kritické");
}

void MainWindow::on_actionInformation_triggered() {
    QMessageBox::information(this, "Information", "Důležitá informace");
}

void MainWindow::on_actionQuestion_triggered() {
    auto res = QMessageBox::question(this, "Question", "OMG QUESTION???");
    QMessageBox::information(
        this,
        "Value",
        res == QMessageBox::StandardButton::Yes ? "Yes" : "No"
    );
}

void MainWindow::on_actionWarning_triggered() {
    QMessageBox::warning(this, "Warning", "Pozor varování!");
}

void MainWindow::on_actiongetDouble_triggered() {
    auto res = QInputDialog::getDouble(this, "getDouble", "Wat dubl?");
    QMessageBox::information(this, "Value", QString::number(res));
}

void MainWindow::on_actiongetInt_triggered() {
    auto res = QInputDialog::getInt(this, "getInt", "Wat intik?");
    QMessageBox::information(this, "Value", QString::number(res));
}

void MainWindow::on_actiongetText_triggered() {
    auto res = QInputDialog::getText(this, "getText", "Wat txt?");
    QMessageBox::information(this, "Value", res);
}
