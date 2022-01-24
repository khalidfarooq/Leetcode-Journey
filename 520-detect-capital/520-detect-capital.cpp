class Solution {
public:
    bool isCapital(char c){
        return (c>='A' && c<='Z') ? true : false; 
    }
    bool detectCapitalUse(string word) {
        int n = word.length();
        int cnt = 0;
        
        for(int i=0; i<n; ++i){
            if(isCapital(word[i])) ++cnt;
        }
        cout<<cnt;
        if(cnt == n) return true;
        else if(cnt == 0) return true;
        else if(isCapital(word[0]) && cnt == 1) return true;
        
        return false;
    }
};