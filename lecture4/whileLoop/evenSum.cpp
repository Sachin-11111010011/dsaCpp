
#include <iostream>
using namespace std;
int main()
{
    int evenSum=0;
    int n;
    cout<<"Enter the n";
    cin>>n;
    int i=1;
    
    while( i<=n){
        if(i%2==0){
           evenSum+=i;
            
        }
        i++;
    }
    cout<<evenSum;
    return 0;
}