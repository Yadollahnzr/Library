#include "addform.h"
#include "ui_addform.h"
#include "bookadd.h"
#include <qmessagebox.h>
#include <fstream>
#include <mainwindow.h>
addform::addform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addform)
{
    ui->setupUi(this);
}

addform::~addform()
{
    delete ui;
}

void addform::on_addbut_clicked()
{
    readfile2();
    book2 b;
    QString qstr=ui->name->text();
    qstr=ui->name->text();
    b.Name=qstr.toStdString();
    qstr=ui->author->text();
    b.Author=qstr.toStdString();
    qstr=ui->price->text();
    b.Price=qstr.toStdString();
    qstr=ui->lan->text();
    b.Language=qstr.toStdString();
    qstr=ui->publisher->text();
    b.Publisher=qstr.toStdString();
    qstr=ui->pub_date->text();
    b.Publish_Date=qstr.toStdString();
    qstr=ui->pages->text();
    b.Pages=qstr.toStdString();
    qstr=ui->dimen->text();
    b.Dimensions=qstr.toStdString();
    qstr=ui->weight->text();
    b.Weight=qstr.toStdString();
    if(b.Name.length()!=0 && b.Author.length()!=0 && b.Price.length()!=0 && b.Language.length()!=0 &&
            b.Publisher.length()!=0 && b.Publish_Date.length()!=0 && b.Pages.length()!=0)
    {
        if(b.Dimensions.length()==0)
            b.Dimensions="\\";
       if(b.Weight.length()==0)
           b.Weight="\\";
        books2.push_back(b);
        fstream booklist("C:/Users/Yadollah/Documents/bookshop3/Book list.txt",ios::out);
        for (unsigned int i{0};i<books2.size();i++)
        {
            cba(books2.at(i).Name);
            booklist<<books2.at(i).Name<<" ";
            cba(books2.at(i).Author);
            booklist<<books2.at(i).Author<<" ";
            cba(books2.at(i).Price);
            booklist<<books2.at(i).Price<<" ";
            cba(books2.at(i).Language);
            booklist<<books2.at(i).Language<<" ";
            cba(books2.at(i).Publisher);
            booklist<<books2.at(i).Publisher<<" ";
            cba(books2.at(i).Publish_Date);
            booklist<<books2.at(i).Publish_Date<<" ";
            cba(books2.at(i).Pages);
            booklist<<books2.at(i).Pages<<" ";
            cba(books2.at(i).Dimensions);
            booklist<<books2.at(i).Dimensions<<" ";
            cba(books2.at(i).Weight);
            booklist<<books2.at(i).Weight<<endl;
        }
        booklist.close();
        this->close();
    }
    else
    {
        QMessageBox m;
        m.setText("Fill in the blanks");
        m.setWindowTitle("Error");
        m.exec();

    }
    books2.clear();
}
