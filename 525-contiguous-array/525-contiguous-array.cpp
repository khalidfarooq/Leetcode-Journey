class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>m;
        int res=0, c=0;
        m.insert({0,-1});
        for(int i=0; i<nums.size(); i++){
            c = c + (nums[i] == 1 ? 1 : -1);
            if(m.find(c) != m.end()){
                res = max(res, i-m[c]);
            }else{
                m.insert({c,i});
            }
        }
        return res;
    }
};