#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    int id;
    string name;
    void paydues()
    {
        cout << "Student has paid his Dues" << endl;
    }
    Student(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    ~Student()
    {
        cout << "it is Destroyed";
    }
};
void changeStudent(int *a)
{
    *a = 32;
}
int main()
{
    int a = 1000;
    changeStudent(&a);
    cout << a << endl;
    Student *s1 = new Student(100, "Sadik");

    cout << s1->id << endl;
    cout << s1->name << endl;
    s1->paydues();
    delete s1;
}
