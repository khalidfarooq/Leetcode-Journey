class Solution {
public:
    int maxPower(string s) {
        if(s.length() == 1) return 1;
        int max_count = INT_MIN;
        int curr_count = 1;
        for(int i=1; i<s.length(); i++){
            if(s[i-1] == s[i]){
                curr_count+=1;
            }
            else{
                max_count = max(max_count, curr_count);
                curr_count = 1;
            }
        }
        return max(max_count, curr_count);
        
    }
};