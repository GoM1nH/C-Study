#include <iostream>
#include <cstring>
using namespace std;

class Computer { // 기초클래스
private :
    char owner[50];
public :
    Computer(char * name) {
        strcpy(owner, name);
    }
    void Calculator() {
        cout<<"Calculate ON"<<endl;
    }
};

class NotebookComp : public Computer { // Computer을 기초 클래스로 두는 유도클래스
// Notebook은 일종의 Computer이기에, IS-A 관계가 성립한다. (Notebook is a Computer.)
private :
    int Battery;
public :
    NotebookComp(char *name, int initChag) : Computer(name), Battery(initChag) {}

    void Charging() { Batterry += 5; }
    void Usingg() { Battery -= 1; }
    void MovingCal() {
        if(GetBatteryInfo() < 1) {
            cout<<"Notebook needs charging"<<endl;
            return;
        }
        cout<<"When Moving : ";
        Calcultor(); // Computer에서 선언한 함수 Calculator 사용 가능!
        Usingg();
    }

    int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp {// NotebookComp을 기초 클래스로 두는 유도클래스
// TabletNotebook은 일종의 Notebook이기에, IS-A 관계가 성립한다. (Notebook is a Computer.)
private :
    char regstPenModel[50];
public :
    TabletNotebook(char *name, int initChag, char *pen) : NotebookComp(name, initChag) {
        strcpy(regstPenModel, pen);
    }

    void Write(char *penInfo) {
        if (GetBatteryInfo() < 1) { // NotebookComp에서 선언한 함수 GetBatteryInfo 사용 가능!
            cout<<"Pen needs charging."<<endl;
            return;
        }

        if (strcmp(regstPenModel, penInfo) != 0) {
            cout<<"Not This Pen";
            return;
        }
        cout<<"Write Complete"<<endl;
        Usingg(); // NotebookComp에서 선언한 함수 Usingg 사용 가능!
    }
};

int main() {
    NotebookComp nc("하영환", 4);
    TabletNotebook tn("박운종", 6, "ISE-241-243");
    nc.MovingCal();
    tn.Write("ISE-241-243");

    return 0;
}