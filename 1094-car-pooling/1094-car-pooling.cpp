class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            v.push_back({trips[i][1], trips[i][0]});
            v.push_back({trips[i][2], -trips[i][0]});
        }
        sort(v.begin(), v.end());
        
        int currCap = 0;
        
        for(auto x : v){
            currCap += x.second;
            if(currCap > capacity) return false;
        }
        return true;
    }
};