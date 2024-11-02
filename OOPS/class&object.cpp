
#include <bits/stdc++.h>
using namespace std;
class Student
    {
        public:
        string name;
        int age,roll_number;
        string grade;
    };
    
int main()
{
    Student S1;
    S1.name="Sachin";
    S1.age=21;
    S1.roll_number=22;
    S1.grade="A+";
    cout<<S1.name<<endl;
    
    Student S2;
    S2.name="Sheetal";
    S2.age=21;
    S2.roll_number=22;
    S2.grade="A+";
    cout<<S2.age;
}