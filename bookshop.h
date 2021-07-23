#ifndef BOOKSHOP_H
#define BOOKSHOP_H
#include <QMainWindow>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
struct book
{
    string Name;
    string Author;
    string Price;
    string Language;
    string Publisher;
    string Publish_Date;
    string Pages;
    string Dimensions;
    string Weight;
};
vector<book> books;
vector<book> searchbook;

void abc(string &str)
{
    for (unsigned int i{0};i<str.size();i++)
        if(str.at(i)=='\\')
            str.at(i)=' ';
}
void readfile()
{
    books.clear();
    fstream booklist("C:/Users/Yadollah/Documents/bookshop3/Book list.txt",ios::in);
    book b;
    if(booklist)
        while (booklist)
        {
            booklist>>b.Name;
            abc(b.Name);
            booklist>>b.Author;
            abc(b.Author);
            booklist>>b.Price;
            abc(b.Price);
            booklist>>b.Language;
            abc(b.Language);
            booklist>>b.Publisher;
            abc(b.Publisher);
            booklist>>b.Publish_Date;
            abc(b.Publish_Date);
            booklist>>b.Pages;
            abc(b.Pages);
            booklist>>b.Dimensions;
            abc(b.Dimensions);
            booklist>>b.Weight;
            abc(b.Weight);
            if(b.Name!="")
                books.push_back(b);
            b.Name="";
        }
    booklist.close();
}
bool Showsearch(string name)
{
    searchbook.clear();
    for (unsigned int i{0};i<books.size();i++)
    {
        if(name==books[i].Name)
            searchbook.push_back(books.at(i));
    }
    return false;
}
#endif // BOOKSHOP_H
