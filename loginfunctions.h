#ifndef LOGINFUNCTIONS_H
#define LOGINFUNCTIONS_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
bool exist(string user,string pass)
{
    bool e=false;
    fstream users("C:/Users/Yadollah/Documents/bookshop3/users.txt",ios::in);
    while(users)
    {
        string username;
        string password;
        users>>username;
        users>>password;
        if(user==username && pass==password)
            e=true;
    }
    users.close();
    return e;
}
bool exist(string user)
{
    bool e=false;
    fstream users("C:/Users/Yadollah/Documents/bookshop3/users.txt",ios::in);
    while(users)
    {
        string username;
        string password;
        users>>username;
        users>>password;
        if(user==username)
            e=true;
    }
    users.close();
    return e;
}

bool findspace(string str)
{
    for (unsigned int i{0};i<str.size();i++)
        if(str.at(i)==' ')
            return true;
    return false;
}

#endif // LOGINFUNCTIONS_H
