#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionVyjmout_triggered();

    void on_actionKop_rovat_triggered();

    void on_actionVlo_it_triggered();

    void on_actionKonec_triggered();

    void on_actionO_programu_triggered();

    void on_actionNov_triggered();

    void on_actionOtev_t_triggered();

    void on_textEdit_textChanged();

    void on_actionUlo_it_triggered();

    void on_actionUlo_it_jako_triggered();

private:
    Ui::MainWindow *ui;

protected:
    QString filename = "";
    bool modified = false;

    bool ensureSaved();
    void save();
    void closeEvent(QCloseEvent *) override;
};
#endif // MAINWINDOW_H
