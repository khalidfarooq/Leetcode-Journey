class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>m;
        char res;
        for(char x: s) m[x]++;
        
        
        for(int i=0; i<t.length(); i++){
            if(m[t[i]] >= 1) m[t[i]]--;
            else if(m[t[i]] <=0){
                res = t[i];
                break;
            }
        
        }
        return res;
    }
}; 