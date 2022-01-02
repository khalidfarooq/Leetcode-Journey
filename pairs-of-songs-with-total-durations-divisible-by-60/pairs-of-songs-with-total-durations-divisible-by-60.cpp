class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int>rec(60);
        for(int i=0; i<n; i++){
            time[i] %= 60;
            rec[time[i]]++;
        }
        
        int ans = 0;
        for(int t:time){
           rec[t]--;
            int other = (60-t)%60;
            ans += max(rec[other], 0);
        }
        return ans;
    }
};