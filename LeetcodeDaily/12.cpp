class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        string result ="";
        result.push_back(s[0]);
        int freq=1;

        for(int i=1;i<n;i++){
            if(s[i]==result.back()){
                freq++;
                if(freq<3){
                    result.push_back(s[i]);
                }
            }else{
                result.push_back(s[i]);
                freq=1;
            }
        }
        return result;
    }
};

// Another Method 

class Solution {
public:
    static string makeFancyString(string& s) {
        int n=s.size(), i=0;
        char prev='@';
        for(int len=0; char c: s){
            if (prev!=c) len=1;
            else len++;
            if (len<= 2) 
                s[i++]=c;
            prev=c;
            
        }
        s.resize(i);
        return s;
         
    }
};