
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,num,pow;
    cout<<"enter the n";
    cin>>n;
    cout<<"enter the power";
    cin>>pow;
    num=n;
    for(int i=1;i<pow;i++)
    {
        num=num*n;
    }
    cout<<num;
}