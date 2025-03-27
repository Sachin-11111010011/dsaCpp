/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

void buble_sort ( int arr[] , int n){
    
    for(int i=n-1; i>=1 ; i--){
        for(int j=0; j<= i-1 ;j++){
            if(arr[j] > arr[j+1]){
                
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp ;
        }
            }
        }
}




int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
       cin>>arr[i]; 
   }
   
   buble_sort(arr,n);
   
   for(int i=0;i<n;i++){
       cout<<arr[i]<< " ";
   }
   
return 0;
}
   