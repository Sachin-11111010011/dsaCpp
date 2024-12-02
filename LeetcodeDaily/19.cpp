class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string check;
        int count=0;
        int n= searchWord.size();
        for(char c:sentence){
            if(c==' '){
                if(check.size()>=n && check.substr(0,n)==searchWord)
                return count+1;
            else{
                count++;
                check="";
                }
            }
          else{
            check+=c;
          } 
        }
        if(check.size()>=n && check.substr(0,n)==searchWord)
        return count+1;
        else return -1;
    }
};