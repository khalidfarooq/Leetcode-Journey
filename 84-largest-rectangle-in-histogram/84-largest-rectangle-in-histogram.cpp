class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);
        stack<int>s;
        
        /*finding left limit index from i such that height[i] >= left most limit */
        s.push(0);
        for(int i=1; i<n; i++){
            if(heights[s.top()] < heights[i]) left[i] = i;
            else if(heights[s.top()]>=heights[i]){
                while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
                (s.empty()) ? left[i] = 0 : left[i] = s.top()+1;
            }
            s.push(i);
        }
        
        
        /*finding right limit index from i such that height[i] >= right most limit */
        s = stack<int>();
        s.push(n-1);
        right[n-1] = n-1;
        
        for(int i=n-2; i>=0; i--){
            if(heights[s.top()] < heights[i]) right[i] = i;
            else if(heights[s.top()]>=heights[i]){
                while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
                (s.empty()) ? right[i] = n-1 : right[i] = s.top()-1;
            }
            s.push(i);
        }
        
        int max_area=0;
        for(int i=0; i<n; i++){
            max_area = max(heights[i] * (right[i]-left[i]+1),max_area);
        }
        
        return max_area;
        
    }
};