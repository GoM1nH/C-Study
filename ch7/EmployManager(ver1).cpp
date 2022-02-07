#include <iostream>
#include <cstring>
using namespace std;

class PermanentWorker { // 데이터적 성격을 지닌 class

private :
    char name[100];
    int salary;

public :
    PermanentWorker(char* name, int money) : salary(monry) {
        strcpy(this->name, name);
    }

    int GetPay() const {
        return salary;
    }

    void ShowSalaryInfo() const {
        cout<<"name : "<<name<<endl;
        cout<<"salary : "<<GetPay()<<endl<<endl;
    }
};

class EmployeeHandler { // 기능적 성격을 지닌 class. "Control Class"나 "Handler Class"라고 부른다.
private :
    PermanentWorker* empList[50]; // 데이터적 성격을 지닌 PermanentWorker로 객체 포인터 배열 형성
    int empNum;
public :
    EmployeeHandler() : empNum(0) {}
    
    void AddEmployee(PermanentWorker* emp) { // 기능 1. 직원 추가
        empList[empNum++] = emp;
    }

    void ShowAllSalryInfo() const { // 기능 2. 모든 직원들의 급여 출력
        for (int i=0; i<empNum ; i++) {
            empList[i]->ShowSalaryInfo();
        }
    }

    void ShowTotalSalary() const { // 모든 직원들 급여의 총액 출력
        int sum = 0;
        for (int i=0; i<empNum ; i++) {
            sum += empList[i]->GetPay();
        }
        cout<<"Salary sum : "<<sum<<endl;
    }

    ~EmployeeHandler() {
        for (int i=0 ; i<empNum ; i++) {
            delete empList[i];
        }
    }
};

int main() {
    EmployeeHandler handler;
    handler.AddEmployee(new PermanentWorker("Go", 372));
    handler.AddEmployee(new PermanentWorker("Bae", 365));
    handler.AddEmployee(new PermanentWorker("Park", 256));

    handler.ShowAllSalryInfo();
    handler.ShowTotalSalary();

    return 0;
}