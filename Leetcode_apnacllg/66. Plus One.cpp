class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // step-1 => traverse on the given array
       for( int i=digits.size() -1; i>=0; i--){
          // step 2=> check if current element is 9 or not 
          if(digits[i]==9){
            digits[i]=0;
          }
          else{
            digits[i] =digits[i] + 1;
            return digits;
          }
       }
      // step 3 => push 0 at the back of the array
       digits.push_back(0);
       digits[0]=1;
      // step-4 => return the array
       return digits; 
    }
};