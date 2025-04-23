#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    int sumOfEven=0;
    int SumOfOdd=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
             sumOfEven = sumOfEven + arr[i];
        }
        
        else{
            SumOfOdd=SumOfOdd+arr[i];
        }
    }
    
    if(SumOfOdd > sumOfEven){
        cout<<"SumOfOdd " <<SumOfOdd;
    }
    else{
        cout<< " sumOfEven"<<sumOfEven;
    }
    

    return 0;
}
