// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//    int n;
//    cout<<"enter the n";
//    cin>>n;
//     for(int i=1;i<=10;i++)
//     {
//     cout<<n*i<<endl;
//     }
// }

// Another method

#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cout<<"enter the n";
   cin>>n;
    for(int i=n;i<=n*10;i=i+n)
    {
    cout<<i<<endl;
    }
}