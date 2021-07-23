#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bookshop.h"
#include <qmessagebox.h>
#include "addform.h"
#include "removeform.h"
#include "editform.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readfile();
    int rowcount=books.size();
    ui->booktable->setRowCount(rowcount);
    ui->booktable->setColumnCount(9);
    QStringList clumns={"Name","Author","Price","Language","Publisher",
                        "Publish_Date","Pages","Dimensions","Weight"};
    ui->booktable->setHorizontalHeaderLabels(clumns);
    for (unsigned int i{0};i<books.size();i++)
    {
        ui->booktable->setItem(i,0,new QTableWidgetItem((QString::fromStdString(books.at(i).Name))));
        ui->booktable->setItem(i,1,new QTableWidgetItem((QString::fromStdString(books.at(i).Author))));
        ui->booktable->setItem(i,2,new QTableWidgetItem((QString::fromStdString(books.at(i).Price))));
        ui->booktable->setItem(i,3,new QTableWidgetItem((QString::fromStdString(books.at(i).Language))));
        ui->booktable->setItem(i,4,new QTableWidgetItem((QString::fromStdString(books.at(i).Publisher))));
        ui->booktable->setItem(i,5,new QTableWidgetItem((QString::fromStdString(books.at(i).Publish_Date))));
        ui->booktable->setItem(i,6,new QTableWidgetItem((QString::fromStdString(books.at(i).Pages))));
        ui->booktable->setItem(i,7,new QTableWidgetItem((QString::fromStdString(books.at(i).Dimensions))));
        ui->booktable->setItem(i,8,new QTableWidgetItem((QString::fromStdString(books.at(i).Weight))));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_searchbut_clicked()
{
//    QMessageBox m;
    QString search=ui->Searchtext->text();
    int length=search.length();
//    if(length==0)
//    {
//        m.setText("Enter book's name");
//        m.setWindowTitle("Error");
//        m.exec();
//    }
    if(length!=0)
    {
        Showsearch(search.toStdString());
        ui->booktable->clear();
        int rowcount=searchbook.size();
        ui->booktable->setRowCount(rowcount);
        ui->booktable->setColumnCount(9);
        QStringList clumns={"Name","Author","Price","Language","Publisher",
                            "Publish_Date","Pages","Dimensions","Weight"};
        ui->booktable->setHorizontalHeaderLabels(clumns);
        for (unsigned int i{0};i<searchbook.size();i++)
        {
            QString::fromStdString(searchbook[i].Name);
            QString::fromStdString(searchbook[i].Author);
            QString::fromStdString(searchbook[i].Price);
            QString::fromStdString(searchbook[i].Language);
            QString::fromStdString(searchbook[i].Publisher);
            QString::fromStdString(searchbook[i].Publish_Date);
            QString::fromStdString(searchbook[i].Pages);
            QString::fromStdString(searchbook[i].Dimensions);
            QString::fromStdString(searchbook[i].Weight);
            ui->booktable->setItem(i,0,new QTableWidgetItem((QString::fromStdString(searchbook.at(i).Name))));
            ui->booktable->setItem(i,1,new QTableWidgetItem((QString::fromStdString(searchbook.at(i).Author))));
            ui->booktable->setItem(i,2,new QTableWidgetItem((QString::fromStdString(searchbook.at(i).Price))));
            ui->booktable->setItem(i,3,new QTableWidgetItem((QString::fromStdString(searchbook.at(i).Language))));
            ui->booktable->setItem(i,4,new QTableWidgetItem((QString::fromStdString(searchbook.at(i).Publisher))));
            ui->booktable->setItem(i,5,new QTableWidgetItem((QString::fromStdString(searchbook.at(i).Publish_Date))));
            ui->booktable->setItem(i,6,new QTableWidgetItem((QString::fromStdString(searchbook.at(i).Pages))));
            ui->booktable->setItem(i,7,new QTableWidgetItem((QString::fromStdString(searchbook.at(i).Dimensions))));
            ui->booktable->setItem(i,8,new QTableWidgetItem((QString::fromStdString(searchbook.at(i).Weight))));
        }
    }
}

void MainWindow::on_mainmenubut_clicked()
{
    ui->Searchtext->clear();
    readfile();
    int rowcount=books.size();
    ui->booktable->setRowCount(rowcount);
    ui->booktable->setColumnCount(9);
    QStringList clumns={"Name","Author","Price","Language","Publisher",
                        "Publish_Date","Pages","Dimensions","Weight"};
    ui->booktable->setHorizontalHeaderLabels(clumns);
    for (unsigned int i{0};i<books.size();i++)
    {
        QString::fromStdString(books[i].Name);
        QString::fromStdString(books[i].Author);
        QString::fromStdString(books[i].Price);
        QString::fromStdString(books[i].Language);
        QString::fromStdString(books[i].Publisher);
        QString::fromStdString(books[i].Publish_Date);
        QString::fromStdString(books[i].Pages);
        QString::fromStdString(books[i].Dimensions);
        QString::fromStdString(books[i].Weight);
        ui->booktable->setItem(i,0,new QTableWidgetItem((QString::fromStdString(books.at(i).Name))));
        ui->booktable->setItem(i,1,new QTableWidgetItem((QString::fromStdString(books.at(i).Author))));
        ui->booktable->setItem(i,2,new QTableWidgetItem((QString::fromStdString(books.at(i).Price))));
        ui->booktable->setItem(i,3,new QTableWidgetItem((QString::fromStdString(books.at(i).Language))));
        ui->booktable->setItem(i,4,new QTableWidgetItem((QString::fromStdString(books.at(i).Publisher))));
        ui->booktable->setItem(i,5,new QTableWidgetItem((QString::fromStdString(books.at(i).Publish_Date))));
        ui->booktable->setItem(i,6,new QTableWidgetItem((QString::fromStdString(books.at(i).Pages))));
        ui->booktable->setItem(i,7,new QTableWidgetItem((QString::fromStdString(books.at(i).Dimensions))));
        ui->booktable->setItem(i,8,new QTableWidgetItem((QString::fromStdString(books.at(i).Weight))));
    }
}

void MainWindow::on_addbut_clicked()
{
    books.clear();
    addform *add=new addform();
    add->show();
}

void MainWindow::on_removebut_clicked()
{
    books.clear();
    removeform *remove=new removeform();
    remove->show();
}



void MainWindow::on_editbut_clicked()
{
   editform *edit=new editform();
   edit->show();
}
