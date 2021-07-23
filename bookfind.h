#ifndef BOOKFIND_H
#define BOOKFIND_H
#include<string>
#include<vector>
#include<fstream>
using namespace std;
struct book4
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
vector<book4> books4;
int fb;
void abc4(string &str)
{
    for (unsigned int i{0};i<str.size();i++)
        if(str.at(i)=='\\')
            str.at(i)=' ';
}

void cba4(string &str)
{
    for (unsigned int i{0};i<str.size();i++)
        if(str.at(i)==' ')
            str.at(i)='\\';
}
void readfile4()
{
    books4.clear();
    fstream booklist("C:/Users/Yadollah/Documents/bookshop3/Book list.txt",ios::in);
    book4 b;
    if(booklist)
        while (booklist)
        {
            booklist>>b.Name;
            abc4(b.Name);
            booklist>>b.Author;
            abc4(b.Author);
            booklist>>b.Price;
            abc4(b.Price);
            booklist>>b.Language;
            abc4(b.Language);
            booklist>>b.Publisher;
            abc4(b.Publisher);
            booklist>>b.Publish_Date;
            abc4(b.Publish_Date);
            booklist>>b.Pages;
            abc4(b.Pages);
            booklist>>b.Dimensions;
            abc4(b.Dimensions);
            booklist>>b.Weight;
            abc4(b.Weight);
            if(b.Name!="")
                books4.push_back(b);
            b.Name="";
        }
    booklist.close();
}
int findbook(book4 b)
{
    int m=-1;
    for (unsigned int i{0};i<books4.size();i++)
    {
        if(b.Name==books4.at(i).Name && b.Author==books4.at(i).Author &&
                b.Language==books4.at(i).Language && b.Publisher==books4.at(i).Publisher)
        {
            m=i;
        }
    }
    return m;
}

#endif // BOOKFIND_H
