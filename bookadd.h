#ifndef BOOKADD_H
#define BOOKADD_H
#include<string>
#include<vector>
#include<fstream>
using namespace std;
struct book2
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
vector<book2> books2;
void abc2(string &str)
{
    for (unsigned int i{0};i<str.size();i++)
        if(str.at(i)=='\\')
            str.at(i)=' ';
}
void readfile2()
{
    fstream booklist2("C:/Users/Yadollah/Documents/bookshop3/Book list.txt",ios::in);
    book2 b;
    if(booklist2)
        while (booklist2)
        {
            booklist2>>b.Name;
            abc2(b.Name);
            booklist2>>b.Author;
            abc2(b.Author);
            booklist2>>b.Price;
            abc2(b.Price);
            booklist2>>b.Language;
            abc2(b.Language);
            booklist2>>b.Publisher;
            abc2(b.Publisher);
            booklist2>>b.Publish_Date;
            abc2(b.Publish_Date);
            booklist2>>b.Pages;
            abc2(b.Pages);
            booklist2>>b.Dimensions;
            abc2(b.Dimensions);
            booklist2>>b.Weight;
            abc2(b.Weight);
            if(b.Name!="")
                books2.push_back(b);
            b.Name="";
        }
    booklist2.close();
}
bool exist(book2 b)
{
    for (unsigned int i{0};i<books2.size();i++)
        if(b.Name==books2.at(i).Name && b.Author==books2.at(i).Author && b.Pages==books2.at(i).Pages &&
                b.Publisher==books2.at(i).Publisher && b.Language==books2.at(i).Language &&
                b.Publish_Date==books2.at(i).Publish_Date && b.Dimensions==books2.at(i).Dimensions)
        {
            return true;
        }
    return false;
}
void cba(string &str)
{
    for (unsigned int i{0};i<str.size();i++)
        if(str.at(i)==' ')
            str.at(i)='\\';
}


#endif // BOOKADD_H
