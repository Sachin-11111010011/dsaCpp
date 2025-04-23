class Solution {
    public:
      void pushZerosToEnd(vector<int>& arr) {
          int j=-1;
          int n=arr.size();
          for(int i=0;i<n;i++)
          {
              if(arr[i] == 0){
                  j=i;
                  break;
              }
          }
         if(j==-1) return;   // IF no zero is found , no need to proceed   
          for(int i=j+1;i<n;i++){
              if(arr[i]!=0){
                  swap(arr[i],arr[j]);
                  j++;
              }
          }
      
      }
  };
  