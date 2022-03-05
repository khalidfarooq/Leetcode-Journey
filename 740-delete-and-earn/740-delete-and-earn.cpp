class Solution {
public:
    int findMax(vector<int>&freq, int i, vector<int>&memo){  
        if(i>=10001) return 0;
        if(memo[i] != -1) return memo[i];   
        return memo[i] = max((i*freq[i])+
                   findMax(freq, i+2,memo), 
                   findMax(freq, i+1,memo));
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>freq(10001);
        vector<int>memo(10001,-1);
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        return findMax(freq, 0,memo);
    }
};


