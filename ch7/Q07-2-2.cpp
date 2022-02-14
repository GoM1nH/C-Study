#include <iostream>
#include <cstring>
using namespace std;

class Book {
private :
    char *title;
    char *isbn;
    int price;
public :
    Book(char *bookt, char *isbNumber, int much) : price(much) {
        title = new char[strlen(bookt) + 1];
        strcpy(title, bookt);
        isbn = new char[strlen(isbNumber) + 1];
        strcpy(isbn, isbNumber);
    }

    void ShowBookInfo() {
        cout<<"TITLE : "<<title<<endl;
        cout<<"ISBN : "<<isbn<<endl;
        cout<<"PRICE : "<<price<<endl;
    }

    ~Book() {
        delete []title;
        delete []isbn;
    }

};

class Ebook : public Book {
private :
    char *DRMKey;
public :
    Ebook(char *bookt, char *isbNumber, int much, char *drmk) : Book(bookt, isbNumber, much) {
        DRMKey = new char[strlen(drmk) + 1];
        strcpy(DRMKey, drmk);
    }

    void ShowEBookInfo() {
        ShowBookInfo();
        cout<<"DRM Key : "<<DRMKey<<endl;
    }

    ~Ebook() {
        delete []DRMKey;
    }
}

int main() {
    Book book("AWESOME C++", "555-12345-890-1", 20000);
    book.ShowBookInfo();
    cout<<endl;
    EBook ebook("AWESOME C++ Ver.E-Book", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    cout<<endl;

    return 0;
}