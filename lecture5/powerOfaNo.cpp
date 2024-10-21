
#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,i,pow,num;
   cout<<"enter the number";
   cin>>n;
   cout<<"enter the power";
   cin>>pow;
   num=n;
   for( i=1;i<pow;i++)
   {
     num=num*n;
   }
   cout<<num;
}