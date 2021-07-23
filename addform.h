#ifndef ADDFORM_H
#define ADDFORM_H
#include <QDialog>
namespace Ui {
class addform;
}

class addform : public QDialog
{
    Q_OBJECT

public:
    explicit addform(QWidget *parent = nullptr);
    ~addform();

private slots:
    void on_addbut_clicked();

private:
    Ui::addform *ui;
};

#endif // ADDFORM_H
