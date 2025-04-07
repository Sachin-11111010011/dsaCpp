#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
   sort(arr.begin() , arr.end());   // Largest

   int largest =arr[n-1];

   // Find second largest element

   int Slargest=-1;

   for(int i=n-2 ; i>=0 ; i--){
       if(arr[i]!= largest ){
           Slargest= arr[i];
           break;
       }
      
   }

   return Slargest;


}