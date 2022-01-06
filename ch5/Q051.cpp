#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
    enum {CLERK, SENIOR, ASSIST, MANAGER};

    void ShowPosition(int pos) {
        case CLERK :
            cout<<"CLERK"<<endl;
            break;
        .
        .
        .
        
    }
}

class NameCard {

private :
    char *Name;
    char *ComName;
    char PhoneNum[15];
    int rank;

public :
    NameCard(char *myName, char *company, char *phone, int position) : rank(position) {
        Name = new char[strlen(myName) + 1];
        ComName = new char[strlen(company) + 1];

        strcpy(Name, myName);
        strcpy(ComName, company);
        strcpy(PhoneNum, phone);
    }

    NameCard(const NameCard& myCard) : rank(myCard.rank) {
        Name = new char[strlen(myCard.Name) + 1];
        ComName = new char[strlen(myCard.ComName) + 1];

        strcpy(Name, myCard.Name);
        strcpy(ComName, myCard.ComName);
        strcpy(PhoneNum,myCard.PhoneNum);
    }

    void ShowNameCardInfo() {
        cout<<"Name : "<<Name<<endl;
        cout<<"Company : "<<ComName<<endl;
        cout<<"Phone number : "<<PhoneNum<<endl;
        cout<<"Position : "<<COMP_POS::ShowPosition(rank)<<endl;
        cout<<"\n";
    }

    ~NameCard() {
        delete []Name;
        delete []ComName;
    }
};

int main(void) {
    NameCard manClerk("LEE", "ABCEng", "010-2313-2324", COMP_POS::CLERK);
    NameCard manSENIOR("KIM", "OrangeENg", "010-3333-4444", COMP_POS::SENIOR);

    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();

    return 0;
}