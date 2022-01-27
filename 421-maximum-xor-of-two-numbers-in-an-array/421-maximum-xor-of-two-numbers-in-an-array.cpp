class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0, mask = 0;
        for(int i=31; i>=0; i--){
            mask = mask | (1<<i);
            set<int>s;
            for(int x : nums)
                s.insert(x & mask);
            
            int temp = ans | (1<<i);
            for(int z : s){
                if(s.find(temp^z) != s.end()){
                    ans = temp;
                    break;
                }
            }
        }
        return ans;
    }
};