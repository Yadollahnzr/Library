#ifndef FINDBOOK_H
#define FINDBOOK_H

#include <QDialog>
#include "editform.h"
int fb;
namespace Ui {
class Findbook;
}
class Findbook : public QDialog
{
    Q_OBJECT

public:
    explicit Findbook(QWidget *parent = nullptr);
    ~Findbook();

private slots:
    void on_findbut_clicked();

private:
    Ui::Findbook *ui;
};

#endif // FINDBOOK_H
