#include<iostream>
#include<climits>
using namespace std;
int main(){

int arr[]={90,91,92,93,94,95,89};

int size = sizeof(arr)/ sizeof(int);


int small = INT_MAX;

int index=0;

for(int i=0; i < size ; i++){
    min(arr[i],small);
    small=arr[i];
    index=i;

}
  
 cout<< small<<"Index is "<<index;
 return 0;
}