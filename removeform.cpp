#include "removeform.h"
#include "ui_removeform.h"
#include "removefunction.h"
#include <qmessagebox.h>
removeform::removeform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeform)
{
    ui->setupUi(this);
}

removeform::~removeform()
{
    delete ui;
}

void removeform::on_pushButton_clicked()
{
    book3 b;
    QMessageBox m;
    QString qstr;
    qstr=ui->name->text();
    b.Name=qstr.toStdString();
    qstr=ui->author->text();
    b.Author=qstr.toStdString();
    qstr=ui->publisher->text();
    b.Publisher=qstr.toStdString();
    qstr=ui->language->text();
    b.Language=qstr.toStdString();
    if(b.Name.size()!=0 || b.Author.size()!=0 || b.Publisher.size()!=0 || b.Language.size()!=0)
    {
        readfile3();
        bool flag=remove(b);
        fstream booklist3("C:/Users/Yadollah/Documents/bookshop3/Book list.txt",ios::out);
        if(flag)
        {
            for (unsigned int i{0};i<books3.size();i++)
            {
                cba2(books3.at(i).Name);
                booklist3<<books3.at(i).Name<<" ";
                cba2(books3.at(i).Author);
                booklist3<<books3.at(i).Author<<" ";
                cba2(books3.at(i).Price);
                booklist3<<books3.at(i).Price<<" ";
                cba2(books3.at(i).Language);
                booklist3<<books3.at(i).Language<<" ";
                cba2(books3.at(i).Publisher);
                booklist3<<books3.at(i).Publisher<<" ";
                cba2(books3.at(i).Publish_Date);
                booklist3<<books3.at(i).Publish_Date<<" ";
                cba2(books3.at(i).Pages);
                booklist3<<books3.at(i).Pages<<" ";
                cba2(books3.at(i).Dimensions);
                booklist3<<books3.at(i).Dimensions<<" ";
                cba2(books3.at(i).Weight);
                booklist3<<books3.at(i).Weight<<endl;
            }
        }
        else
        {
            m.setText("No book exist");
            m.setWindowTitle("Error");
            m.exec();
        }
        this->close();
        booklist3.close();
    }
    else
    {
        m.setText("Fill in the blanks");
        m.setWindowTitle("Error");
        m.exec();
    }
    books3.clear();
}
