class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s,i);
    }
    string helper(string s, int &i){
        string ans = "";
        while(i<s.size() && s[i] != ']'){
            if(isalpha(s[i])){
                ans += s[i++];
            }else{
                int d = 0;
                while(isdigit(s[i])) d= (d*10) + (s[i++]-'0');
                i++;
                string temp = helper(s,i);
                i++;
                while(d--) ans += temp;
            }
        }
        return ans ;
    }
};