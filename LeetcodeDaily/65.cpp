// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int main() {
    
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout<<"The size of the vector is "<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    cout<<"capacity of vector is "<<vec.capacity()<<endl;
    
   
   
    return 0;
}