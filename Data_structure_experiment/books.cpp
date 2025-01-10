#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include<iomanip>
using namespace std;



struct Book {
    string title;
    string author;
    string publish;
    string date;
    Book(string s1,string s2,string s3,string s4)
    {
        title = s1;
        author = s2;
        publish = s3;
        date = s4;
    }
};

vector<Book> books;

bool compareBooks(const Book& book1, const Book& book2) 
{
    return book1.title < book2.title;
}

void save() 
{
    ofstream out("ordered.txt");
//    freopen("ordered.txt","w",stdout);
    for (auto& book : books) 
    {
        out<<left<<setw(50)<<book.title<<setw(20)<<book.author<<setw(30)<<book.publish<<setw(10)<<book.date<<endl;

        //out<<left<<setw(50)<<book.title<<" "<<setw(20)<<book.author<<" "<<setw(30)<<book.publish<<" "<<setw(10)<<book.date<<endl;
        //printf("%-50s %-20s %-30s %-10s",book.title,book.author,book.publish,book.date);
        //puts("");
    }
    out.close();
}

void insert(Book& newBook) 
{
    books.push_back(newBook);
    sort(books.begin(), books.end(), compareBooks);
}

void search(string keyword) 
{
    for (auto& book:books) 
    {
        if (book.title.find(keyword) != string::npos) 
        {
            cout<<left<<setw(50)<<book.title<<setw(20)<<book.author<<setw(30)<<book.publish<<setw(10)<<book.date<<endl;
            //cout<<left<<book.title<<" "<<book.author<<" "<<book.publish<<" "<<book.date<<endl;

            // printf("%-50s %-20s %-30s %-10s",book.title,book.author,book.publish,book.date);
            // puts("");
        }
    }
}

void my_delete(string& keyword)
{
    for (auto it = books.begin(); it != books.end(); it++) 
    {
        if (it->title.find(keyword) != string::npos) {
            it = books.erase(it);
            it--;
        }
    }
}

int main() 
{

    ifstream in_data("books.txt");
//    freopen("in.txt","r",stdin);
    string title, author, publish, date;
    while (in_data>>title>>author>>publish>> date) 
    {
        Book temp(title, author, publish, date);
        books.push_back(temp);
    }
//    fclose(stdin);
    in_data.close();

    int choice;

    do 
    {
        cin >> choice;
        switch (choice) 
        {
            case 1: 
            {
                cin >> title >> author >> publish >> date;
                Book temp(title, author, publish, date);
                insert(temp);
                break;
            }

            case 2: 
            {
                string keyword;
                cin >> keyword;
                search(keyword);
                break;
            }

            case 3: 
            {
                string keyword;
                cin >> keyword;
                my_delete(keyword);
                break;
            }

            case 0: 
            {
                save();
                break;
            }

        }
    } while (choice != 0);

    return 0;
}

