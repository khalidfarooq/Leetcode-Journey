class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        if(n==k) return points;
        vector<vector<int>>res;
        set<pair<double,int>>s;
        for(int i=0; i<n; i++){
            double curr_dist = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            s.insert(make_pair(curr_dist,i));
        }
        int count = 0;
        for(auto x : s){
            if(count >= k) break;
            res.push_back(points[x.second]);
            cout<<x.first<<" "<<x.second<<endl;
            count++;
        }
        return res;
    }
};