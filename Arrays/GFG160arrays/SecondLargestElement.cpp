class Solution {
    public:
   
    int getSecondLargest(vector<int> &arr) {
          int n = arr.size();
          int i;
          int largest=arr[i];
          int Slargest=-1;
          
          for(int i=0;i<n;i++){
              if(arr[i]>largest){
                  Slargest=largest;
                  largest=arr[i];
                  
              }
              else if(largest>arr[i] && Slargest<arr[i]){
                  Slargest=arr[i];
              }
          }
          return Slargest;
          
      }
  };