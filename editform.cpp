#include "editform.h"
#include "ui_editform.h"
#include "bookfind.h"
#include <qmessagebox.h>
#include <fstream>
editform::editform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editform)
{
    ui->setupUi(this);
}

editform::~editform()
{
    delete ui;
}


void editform::on_findbut_clicked()
{
    QMessageBox m;
    book4 b;
    readfile4();
    b.Name=ui->name->text().toStdString();
    b.Author=ui->author->text().toStdString();
    b.Language=ui->language->text().toStdString();
    b.Publisher=ui->publisher->text().toStdString();
    if(b.Name.size()!=0 && b.Author.size()!=0 && b.Language.size()!=0 && b.Publisher.size()!=0)
    {
        fb=findbook(b);
        if(fb!=-1)
        {
            m.setText("Enter new information in changeable information group box.");
            m.setWindowTitle("Notice");
            m.exec();
            ui->price->setText(QString::fromStdString(books4.at(fb).Price));
            ui->dimen->setText(QString::fromStdString(books4.at(fb).Dimensions));
            ui->weight->setText(QString::fromStdString(books4.at(fb).Weight));
            ui->pages->setText(QString::fromStdString(books4.at(fb).Pages));
            ui->pub_date->setText(QString::fromStdString(books4.at(fb).Publish_Date));
            }
        else
        {
            m.setText("No book find");
            m.setWindowTitle("Error");
            m.exec();
        }
    }
    else
    {
        m.setText("Fill in the blanks");
        m.setWindowTitle("Error");
        m.exec();
    }
}

void editform::on_addbut_clicked()
{
    books4.clear();
    readfile4();
    QMessageBox m;

    if(ui->price->text().size()==0 || ui->pages->text().size()==0 || ui->pub_date->text().size()==0)
    {
        m.setText("Fill in the blanks");
        m.setWindowTitle("Error");
        m.exec();
    }
    else
    {
            books4.at(fb).Price=ui->price->text().toStdString();
            books4.at(fb).Publish_Date=ui->pub_date->text().toStdString();
        if(ui->weight->text().size()!=0)
            books4.at(fb).Weight=ui->weight->text().toStdString();
        else
            books4.at(fb).Weight=" ";
        if(ui->dimen->text().size()!=0)
            books4.at(fb).Dimensions=ui->dimen->text().toStdString();
        else
            books4.at(fb).Dimensions=" ";
            books4.at(fb).Pages=ui->pages->text().toStdString();
        fstream booklist("C:/Users/Yadollah/Documents/bookshop3/Book list.txt",ios::out);
        for (unsigned int i{0};i<books4.size();i++)
        {
            cba4(books4.at(i).Name);
            booklist<<books4.at(i).Name<<" ";
            cba4(books4.at(i).Author);
            booklist<<books4.at(i).Author<<" ";
            cba4(books4.at(i).Price);
            booklist<<books4.at(i).Price<<" ";
            cba4(books4.at(i).Language);
            booklist<<books4.at(i).Language<<" ";
            cba4(books4.at(i).Publisher);
            booklist<<books4.at(i).Publisher<<" ";
            cba4(books4.at(i).Publish_Date);
            booklist<<books4.at(i).Publish_Date<<" ";
            cba4(books4.at(i).Pages);
            booklist<<books4.at(i).Pages<<" ";
            cba4(books4.at(i).Dimensions);
            booklist<<books4.at(i).Dimensions<<" ";
            cba4(books4.at(i).Weight);
            booklist<<books4.at(i).Weight<<endl;
        }
        booklist.close();
        this->close();
    }
}
