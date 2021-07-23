#ifndef EDITFORM_H
#define EDITFORM_H
#include <QDialog>
namespace Ui {
class editform;
}

class editform : public QDialog
{
    Q_OBJECT

public:
    explicit editform(QWidget *parent = nullptr);
    ~editform();

private slots:
    void on_findbut_clicked();

    void on_addbut_clicked();

private:
    Ui::editform *ui;
};

#endif // EDITFORM_H
