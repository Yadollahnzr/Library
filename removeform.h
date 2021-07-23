#ifndef REMOVEFORM_H
#define REMOVEFORM_H

#include <QDialog>

namespace Ui {
class removeform;
}

class removeform : public QDialog
{
    Q_OBJECT

public:
    explicit removeform(QWidget *parent = nullptr);
    ~removeform();

private slots:
    void on_pushButton_clicked();

private:
    Ui::removeform *ui;
};

#endif // REMOVEFORM_H
