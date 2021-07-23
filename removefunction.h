#ifndef REMOVEFUNCTION_H
#define REMOVEFUNCTION_H
#include<string>
#include<vector>
#include<fstream>
using namespace std;
struct book3
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
vector<book3> books3;

void abc3(string &str)
{
    for (unsigned int i{0};i<str.size();i++)
        if(str.at(i)=='\\')
            str.at(i)=' ';
}
void readfile3()
{
    fstream booklist("C:/Users/Yadollah/Documents/bookshop3/Book list.txt",ios::in);
    book3 b;
    if(booklist)
        while (booklist)
        {
            booklist>>b.Name;
            abc3(b.Name);
            booklist>>b.Author;
            abc3(b.Author);
            booklist>>b.Price;
            abc3(b.Price);
            booklist>>b.Language;
            abc3(b.Language);
            booklist>>b.Publisher;
            abc3(b.Publisher);
            booklist>>b.Publish_Date;
            abc3(b.Publish_Date);
            booklist>>b.Pages;
            abc3(b.Pages);
            booklist>>b.Dimensions;
            abc3(b.Dimensions);
            booklist>>b.Weight;
            abc3(b.Weight);
            if(b.Name!="")
                books3.push_back(b);
            b.Name="";
        }
    booklist.close();
}
bool remove(book3 b)
{
    bool flag=false;

    if (b.Name!="")
    {
        if(b.Author!="")
        {
            if(b.Language!="")
            {
                if(b.Publisher!="")
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Name==books3.at(i).Name && b.Author==books3.at(i).Author &&
                                b.Publisher==books3.at(i).Publisher && b.Language==books3.at(i).Language)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
                else
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Name==books3.at(i).Name && b.Author==books3.at(i).Author &&
                                b.Language==books3.at(i).Language)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
            }
            else
            {
                if(b.Publisher!="")
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Name==books3.at(i).Name && b.Author==books3.at(i).Author &&
                                b.Publisher==books3.at(i).Publisher)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
                else
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Name==books3.at(i).Name && b.Author==books3.at(i).Author)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
            }

        }
        else
        {
            if(b.Language!="")
            {
                if(b.Publisher!="")
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Name==books3.at(i).Name && b.Publisher==books3.at(i).Publisher && b.Language==books3.at(i).Language)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
                else
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Name==books3.at(i).Name && b.Language==books3.at(i).Language)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
            }
            else
            {
                if(b.Publisher!="")
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Name==books3.at(i).Name && b.Publisher==books3.at(i).Publisher)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
                else
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Name==books3.at(i).Name)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
            }

        }
    }
    else
    {
        if(b.Author!="")
        {
            if(b.Language!="")
            {
                if(b.Publisher!="")
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Author==books3.at(i).Author && b.Publisher==books3.at(i).Publisher && b.Language==books3.at(i).Language)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
                else
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Author==books3.at(i).Author && b.Language==books3.at(i).Language)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
            }
            else
            {
                if(b.Publisher!="")
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Author==books3.at(i).Author && b.Publisher==books3.at(i).Publisher)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
                else
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Author==books3.at(i).Author)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
            }

        }
        else
        {
            if(b.Language!="")
            {
                if(b.Publisher!="")
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Publisher==books3.at(i).Publisher && b.Language==books3.at(i).Language)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
                else
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Language==books3.at(i).Language)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
            }
            else
            {
                if(b.Publisher!="")
                {
                    for (unsigned int i{0};i<books3.size();i++)
                        if(b.Publisher==books3.at(i).Publisher)
                        {
                            books3.erase(books3.begin()+i);
                            flag=true;
                        }
                }
            }
        }
    }

    return flag;
}
void cba2(string &str)
{
    for (unsigned int i{0};i<str.size();i++)
        if(str.at(i)==' ')
            str.at(i)='\\';
}

#endif // REMOVEFUNCTION_H
