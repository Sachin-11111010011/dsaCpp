#include <iostream>
#include <climits>
using namespace std;
int main()
{
   int size=5; 
   int nums[size];
   
   int largest = INT_MIN;
   
   
   for(int i=0; i< size; i++){
       cin>>nums[i];
   }
   
   for( int i=0; i< size; i++){
       
       if(nums[i] > largest){
           largest = nums[i];
       }
   }
   cout<< largest <<endl;
   
}