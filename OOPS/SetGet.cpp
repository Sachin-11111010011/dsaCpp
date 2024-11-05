#include<bits/stdc++.h>
using namespace std;


class student
{
    string grade;
    int age,roll_number;
    string name;
    public:
    void setname(string n)
    {
        name=n;
    }
    void setage(int a)
    {
        age=a;
    }
    void setroll_number(int r)
    {
        roll_number=r;
    }
    void setgrade(string g)
    {
        grade=g;
    }
    
    void getname()
    {
        cout<<name<<endl;
    }
    void getage()
    {
        cout<<age<<endl;
    }
};


int main()
{
    student s1;
    s1.setname("Sachin");
    s1.setgrade("A+");
    s1.setroll_number(22);
    s1.setage(21);
    s1.getname();
    s1.getage();
    
}