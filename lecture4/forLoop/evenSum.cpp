
#include <iostream>
using namespace std;
int main()
{
    int evenSum=0;
    int n;
    cout<<"Enter the n";
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            evenSum+=i;
        }
    }
    cout<<evenSum;

    return 0;
}