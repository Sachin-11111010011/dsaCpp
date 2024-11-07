#include<bits/stdc++.h>
using namespace std;

class student
{
    public:
    string name;
    int age,roll_number;
    string grade;
};

int main()
{
    student *S =new student;
    (*S).name="Sachin";
    (*S).age=20;
    (*S).roll_number=22;
    (*S).grade="A+";

    cout<<S->name<<endl;

}