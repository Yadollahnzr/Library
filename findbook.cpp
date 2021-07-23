#include "findbook.h"
#include "ui_findbook.h"
#include "bookfind.h"
#include <qmessagebox.h>
#include "editform.h"
#include "findbook.h"
Findbook::Findbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Findbook)
{
    ui->setupUi(this);
}

Findbook::~Findbook()
{
    delete ui;
}


void Findbook::on_findbut_clicked()
{
    QMessageBox m;
    book4 b;
    readfile4();
    b.Name=ui->name->text().toStdString();
    b.Author=ui->author->text().toStdString();
    b.Language=ui->language->text().toStdString();
    b.Publisher=ui->publisher->text().toStdString();
    fb=findbook(b);
    if(fb!=-1)
    {
        this->close();
        editform *edit=new editform();
        edit->show();
    }
    else
    {
        m.setText("No book find");
        m.setWindowTitle("Error");
        m.exec();
    }
}
