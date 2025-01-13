// class Solution {
// public:
//     int minimumLength(string s) {
//         int n=s.length();
//         vector<int> freq(26,0);
//         int  deleted=0;

//         for(int i=0;i<n;i++){
//             freq[s[i]-'a'] +=1;

//             if(freq[s[i] - 'a'] == 3){
//                 freq[s[i] - 'a'] -=2;  // We delete 2 characters
//                 deleted +=2;   // We have deleted 2 characters here
//             }
//         }
//         return n - deleted;
//     }
// };

//Another logic

class Solution {
public:
    int minimumLength(string s) {
      vector<int> freq(26,0);
      for(char& ch:s){
        freq[ch-'a']++;
      }
      int result=0;
      for(int i=0;i<26;i++){
        if(freq[i] == 0){
            continue;
        }
        else if( freq[i] % 2==0){
            result +=2;
        }
        else{
            result += 1;
        }
      }
      return result;

    }
};