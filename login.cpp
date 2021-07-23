#include "login.h"
#include "ui_login.h"
#include <qmessagebox.h>
#include "loginfunctions.h"
#include <fstream>
#include <mainwindow.h>
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginbut_clicked()
{
    QMessageBox m;
    QString username=ui->username->text();
    QString password=ui->password->text();
    int lenu=username.size();
    int lenp=password.length();
    if(lenu==0 || lenp==0)
    {
        m.setText("Enter username and password then click .");
        m.setWindowTitle("Error");
        m.exec();
    }
    else
    {
        if(exist(username.toStdString(),password.toStdString()))
        {
            this->close();
            MainWindow *bookform=new MainWindow();
            bookform->show();
        }
        else
        {
            m.setText("username or password is not exist.");
            m.setWindowTitle("Login feult");
            m.exec();
        }

    }
}

void Login::on_registerbut_clicked()
{
    QMessageBox m;
    QString username=ui->username->text();
    QString password=ui->password->text();
    int lenu=username.size();
    int lenp=password.length();
    if(lenu==0 || lenp==0)
    {
        m.setText("Enter username and password then click .");
        m.setWindowTitle("Error");
        m.exec();
    }
    else
    {
        if(exist(username.toStdString()))
        {
            m.setText("Username is exist.");
            m.setWindowTitle("Register feult");
            m.exec();
        }
        else
        {
            fstream users("C:/Users/Yadollah/Documents/BookShop/users.txt",ios::app);
            if(findspace(username.toStdString()) && findspace(password.toStdString()))
            {
                m.setText("Enter username and password whithout space.");
                m.setWindowTitle("Register feult");
                m.exec();
            }
            else
            {
                users<<endl<<username.toStdString()<<" "<<password.toStdString();
                m.setText("Clicked login to enter the main menu.");
                m.setWindowTitle("Register Successfull");
                m.exec();
            }
            users.close();
        }

    }
}
