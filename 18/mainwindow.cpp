#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionVyjmout_triggered() {
    ui->textEdit->cut();
}

void MainWindow::on_actionKop_rovat_triggered() {
    ui->textEdit->copy();
}

void MainWindow::on_actionVlo_it_triggered() {
    ui->textEdit->paste();
}

void MainWindow::closeEvent(QCloseEvent *evt) {
    if (ensureSaved()) {
        evt->accept();
        return;
    }
    evt->ignore();
}

bool MainWindow::ensureSaved() {
    if (!modified)
        return true;
    int ans = QMessageBox::warning(
        this,
        "Warning",
        "Máte neukončenou práci! Chcete ji uložit?",
        QMessageBox::StandardButton::Save | QMessageBox::StandardButton::Cancel
            | QMessageBox::StandardButton::Ignore
    );
    if (ans == QMessageBox::StandardButton::Save)
        save();
    if (ans == QMessageBox::StandardButton::Cancel)
        return false;
    return true;
}

void MainWindow::save() {
    if (filename == "") {
        filename = QFileDialog::getSaveFileName(this, "Vyberte kam uložit soubor");
        if (filename == "") {
            modified = false;
            return;
        }
    }
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    modified = false;
    file.close();
}

void MainWindow::on_actionKonec_triggered() {
    close();
}

void MainWindow::on_actionO_programu_triggered() {
    QMessageBox::information(this, "O programu", "Notepad 3.14\n(c) Adam Hrncarek");
}

void MainWindow::on_actionNov_triggered() {
    if (!ensureSaved())
        return;
    ui->textEdit->clear();
    modified = false;
    filename = "";
}

void MainWindow::on_actionOtev_t_triggered() {
    if (!ensureSaved())
        return;
    QString nfname = QFileDialog::getOpenFileName(this, "Vyberte soubor k otevření");
    if (nfname == "")
        return;
    filename = nfname;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    ui->textEdit->setPlainText(in.readAll());
    modified = false;
    file.close();
}

void MainWindow::on_textEdit_textChanged() {
    modified = true;
}

void MainWindow::on_actionUlo_it_triggered() {
    save();
}

void MainWindow::on_actionUlo_it_jako_triggered() {
    QString old = filename;
    filename = "";
    save();
    if (filename == "")
        filename = old;
}
