class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = INT_MIN;
        for(int i=0; i<accounts.size(); ++i){
            int curr_sum =0;
            for(int j=0; j<accounts[0].size(); ++j){
                curr_sum += accounts[i][j];
            }
            mx = max(mx,curr_sum);
        }
        return mx;
    }
};