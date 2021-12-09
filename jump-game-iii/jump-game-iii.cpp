class Solution {
public:
    bool dfs(vector<int>&arr, int curr_pos, vector<bool>&visited){
        if(curr_pos >= arr.size() || curr_pos < 0 || visited[curr_pos]) 
            return false;
        if(arr[curr_pos] == 0)
            return true;
        
        visited[curr_pos] = true;
        return dfs(arr, curr_pos+arr[curr_pos],visited)||
            dfs(arr, curr_pos-arr[curr_pos],visited);
        
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>visited(arr.size(),false);
        return dfs(arr,start,visited);
    }
};