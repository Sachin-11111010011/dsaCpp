#include <iostream>
#include <climits>
using namespace std;
int main()
{
   int size=5; 
   int nums[size];
   
   int largest=INT_MIN;
   int index=-1;
   
   for(int i=0; i< size; i++){
       cin>>nums[i];
   }
   
   for( int i=0; i< size; i++){
       
       if(nums[i] > largest){
           largest = nums[i];
           index=i;
       }
   }
   cout<< "Index of the largest element "<< index <<endl;
   
}