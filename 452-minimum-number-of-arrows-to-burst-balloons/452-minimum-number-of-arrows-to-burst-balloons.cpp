class Solution {
public:
    
int findMinArrowShots(vector<vector<int>>& points) {
        int cnt = 1;
        sort(points.begin(),points.end());
        int curr_min = points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0] > curr_min)
            {
                cnt++;
                curr_min = points[i][1];
            }
            curr_min = min(curr_min,points[i][1]);
        }
        
        return cnt;
    }
};