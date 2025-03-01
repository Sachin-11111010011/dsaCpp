#include <iostream>
#include <climits>
using namespace std;

void changeArray(int arr[] ,  int size){
    cout<<"in function"<<endl;
    for(int i=0;i<size;i++){
        arr[i] = 2 * arr[i]; 
    }
}



int main()
{
  int arr[]={1,2,3,4};
  changeArray(arr,3);
  cout<<"main function"<<endl;
  for(int i =0; i<4; i++){
      cout<<arr[i]<<endl;
  }
  return 0;
}