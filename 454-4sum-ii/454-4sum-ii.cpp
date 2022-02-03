class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int,int>m;
        
        for(int x : nums1){
            for(int y : nums2){
                m[x+y]++;
            }
        }
        
        for(int i : nums3){
            for(int j : nums4){
                if(m.count(0-i-j)) count+=m[0-i-j];
            }
        }
        return count;
    }
};