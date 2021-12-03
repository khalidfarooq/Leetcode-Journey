class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p1 = 1, p2 = 1, n=nums.size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            p1 = p1 * nums[i];
            p2 = p2 * nums[n-i-1];
            
            ans = max(ans, max(p1,p2));
            cout<<ans<<" ";
            
            if(p1 == 0) p1 = 1;
            if(p2 == 0) p2 = 1;
        }
        return ans;
    }
};