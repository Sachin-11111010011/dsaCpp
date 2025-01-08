

#include <iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int arr[5]={91,92,93,94,5};
    
    int size = 5;
    int target = 5;
    bool find = false;
    
    for(int i=0; i<size;i++){
        if(arr[i] ==  target){
            cout<<"The element is present at Index "<<i;
            find=true;
            break;
        }
    }
    if(!find){
        cout<<"-1";
    }
    return 0;
}