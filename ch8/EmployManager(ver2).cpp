#include <iostream>
#include <cstring>
using namespace std;

class Employee { // 가장 기본 형태인 "피고용인"
private : // 모든 고용인의 공통적인 멤버는 "이름" 밖에 없다.
    char name[100];
public :
    Employee(char *empname) {
        strcpy(name, empname);
    }
    void ShowYourName() const {
        cout<<"Name : "<<name<<endl;
    }
};

/* 고용 형태 */

class PermanentWorker : public Employee { // Employee의 고용 형태중 하나인 "정규직"

private :
    int salary;

public :
    PermanentWorker(char* name, int money) : Employee(name), salary(money) {    }

    int GetPay() const {
        return salary;
    }

    void ShowSalaryInfo() const {
        ShowYourName();
        cout<<"salary : "<<GetPay()<<endl<<endl;
    }
};

class SalesWorker : public PermanentWorker { // Employee 중 PermantWokrer의 고용 형태 중 하나인 "영업직"
private :
    int salesResult;
    double bonusRatio;
public :
    SalesWorker(char *name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {    }
    
    void AddSalesResult(int value) {
        salesResult += value;
    }

    int GetPay() const { // 이의 경우, PermanentWorker 클래스와 같은 이름의 함수를 가지게 되는데, 이를 "함수 오버라이딩"이라고 한다.
        return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
    } // PermanentWorker::GetPay()는 오버라이딩 된 기초 클래스의 GetPay 함수를 호출하는 것.
    // 만약 매개변수의 자료형 / 개수가 다르다면 함수 오버라이딩이 아닌 함수 오버로딩이 된다.

    void ShowSalaryInfo() const {
        ShowYourName();
        cout<<"Salary : "<<GetPay()<<endl<<endl;
    } 
    // PermanentWorker에 저장된 ShowSalaryInfo와 100% 똑같으나 오버라이딩 진행.
    // because, 각 클래스에 있는 서로 이름만 같은 GetPay()함수 때문에.
};

class TemporaryWorker : public Employee { // Employee의 고용 형태 중 하나인 "임시직"
private :
    int workTime; // 근무시간
    int payPerHour; // 시급
public :
    TemporaryWorker(char *empname, int pay) : Employee(empname), workTime(0), payPerHour(pay) { }
    
    void AddWorkTime(int time) {
        workTime += time;
    }

    int GetPay() const {
        return workTime * payPerHour;
    }

    void ShowSalaryInfo() const {
        ShowYourName();
        cout<<"Salary : "<<GetPay()<<endl<<endl;
    }
};

 /* Control class */

class EmployeeHandler { // Control Class
private :
    Employee* empList[50];
    int empNum;
public :
    EmployeeHandler() : empNum(0) {}
    
    void AddEmployee(Employee* emp) { // 기능 1. 직원 추가
        empList[empNum++] = emp;
    }

    void ShowAllSalryInfo() const { // 기능 2. 모든 직원들의 급여 출력
        // 대기!
    }

    void ShowTotalSalary() const { // 모든 직원들 급여의 총액 출력
        int sum = 0;
        // 대기!
        cout<<"Salary sum : "<<sum<<endl;
    }

    ~EmployeeHandler() {
        for (int i=0 ; i<empNum ; i++) {
            delete empList[i];
        }
    }
};

/* 메인함수 */

int main() {
    EmployeeHandler handler;

    // 정규직
    handler.AddEmployee(new PermanentWorker("Go", 372)); // handler가 여전히 PermanentWorker 객체를 저장하고 관리한다!
    handler.AddEmployee(new PermanentWorker("Bae", 365));

    // 임시직 (객체 포인터 사용)
    TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(6);
    handler.AddEmployee(alba);

    // 영업직 (객체 포인터 사용)
    SalesWorker *seller = new SalesWorker("Hong", 980, 0.15);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    handler.ShowAllSalryInfo();

    handler.ShowTotalSalary();

    return 0;
}