class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.length();
        int sign = 1; //assuming it to be postive
        int res = 0;
        int i=0;
        
        while(i<n && s[i]==' ') ++i; //ignore white spaces
        
        if(i<n && s[i] == '-'){
            sign = -1;
            ++i;
        } // if negative
        else if(i<n && s[i] == '+'){
            sign = 1;
            ++i;
        } //if positive
        
        
        while(i<n && isdigit(s[i])){
            int dig = s[i] - '0';
            
            if((res > INT_MAX/10) || (res == INT_MAX/10 && dig > INT_MAX%10 )){
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            res = 10*res + dig;
            ++i;
        }
        return sign * res;
    }
};