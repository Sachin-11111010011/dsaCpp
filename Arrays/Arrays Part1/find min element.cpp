#include <iostream>
#include <climits>
using namespace std;
int main()
{
   int size=5; 
   int nums[size];
   
   int minimum=INT_MAX;
   
   
   for(int i=0; i< size; i++){
       cin>>nums[i];
   }
   
   for( int i=0; i< size; i++){
       
       if(nums[i] < minimum){
           minimum = nums[i];
       }
   }
   cout<< minimum <<endl;
   
}