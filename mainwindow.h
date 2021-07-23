#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_searchbut_clicked();

    void on_mainmenubut_clicked();

    void on_addbut_clicked();

    void on_removebut_clicked();

    void on_editbut_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
