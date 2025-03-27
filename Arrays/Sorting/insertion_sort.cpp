/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

void insertion_sort ( int arr[] , int n){
    
    for(int i=0; i<=n ; i++){
        int j=i;
        while( j>0 && arr[j-1] > arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp ;
                j--;
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
   
   insertion_sort(arr,n);
   
   for(int i=0;i<n;i++){
       cout<<arr[i]<< " ";
   }
   
return 0;
}
   