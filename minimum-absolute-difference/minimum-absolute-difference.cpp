class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>>res;
        int curr_diff = 0;
        int min_diff = INT_MAX;
        for(int i=1; i<arr.size(); ++i){
            curr_diff = abs(arr[i-1] - arr[i]);
            min_diff = min(min_diff, curr_diff);
        }
        
        for(int i=1; i<arr.size(); ++i){
            if(abs(arr[i-1] - arr[i]) == min_diff){
                res.push_back({arr[i-1],arr[i]});
            }   
        }
        return res;
    }
};