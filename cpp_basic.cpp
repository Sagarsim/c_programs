#include <iostream>
#include <string>

using namespace std;

class Details{
    protected:
        int age;
        string name;
    public:
        Details();
        void getAge(int);
        void getName(string);
        ~Details();
};

Details :: Details(){
    cout << "Parent constructor called"<< endl;
    Details::age = 0;
    Details::name = "noname";
}

Details :: ~Details(){
    cout << "Parent destructor called"<< endl;
}

void Details :: getAge(int iage){
    Details :: age = iage;
}

void Details :: getName(string iname){
    Details :: name = iname;
}

class Student : public Details{
        int id;
        string branch;
    public:
        static int count;
        Student();
        void getId(int);
        void getBranch(string);
        friend void showDetails(Student);
        ~Student();
};

int Student :: count = 0;

Student :: Student(){
    cout << "Child constructor called "<< endl;
    Student :: count++;
    Student :: id = 0;
    Student :: branch = "NA";
    
}

Student :: ~Student(){
    cout << "Child destructor called "<< endl;
}

void Student :: getId(int iid){
    Student :: id = iid;
}

void Student :: getBranch(string ibranch){
    Student :: branch = ibranch;
}

void showDetails(Student newStu){
    cout <<endl<< "Student name is "<< newStu.Details :: name<<endl;
    cout << "Student age is "<< newStu.Details :: age<<endl;
    cout << "Student id is "<< newStu.id<<endl;
    cout << "Student branch is "<< newStu.branch<<endl;
    cout << "Total Students: " << Student :: count << endl<<endl;
}



int main(){
    Student *sagar = new Student();
    sagar->Details:: getName("Sagar Gujarati");
    sagar->Details:: getAge(21);
    sagar->getId(21);
    sagar->getBranch("CSE");
    showDetails(*sagar);
    Student *yogesh = new Student();
    showDetails(*yogesh);
    Student *mihir = new Student();
    showDetails(*mihir);
    delete sagar;
    delete yogesh;
    delete mihir;
    return 0;
}