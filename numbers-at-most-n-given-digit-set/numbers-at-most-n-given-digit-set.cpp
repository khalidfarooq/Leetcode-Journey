class Solution {
    unordered_map<int, int> convertStringToInt(vector<string> &digits){
        unordered_map<int,int> dig;
        for(auto &x:digits){
            dig[stoi(x)]=1;
        }
        return dig;
    }
    
    vector<int> numberToVector(int n){
        vector<int> nums;
        while(n){
            nums.push_back(n%10);
            n/=10;
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
    
    int rec(int pos, unordered_map<int, int> &dig, vector<int> &nums, int strict, int sum, vector<vector<vector<int>>> &dp){
        if(pos==nums.size()){
            if(sum) return 1;
            return 0;
        }
        
        if(dp[pos][strict][sum]!=-1) return dp[pos][strict][sum];
        
        int cur = 0;
        if(strict){
            for(int i=0;i<=nums[pos];i++){
                if(i==0 && sum==0) cur += rec(pos+1, dig, nums, false, sum, dp);
                else if(i==nums[pos] && dig[i]==1) cur += rec(pos+1, dig, nums, true, sum + i, dp);
                else if(dig[i]==1) cur += rec(pos+1, dig, nums, false, sum + i, dp);
            }
        }else{
            for(int i=0;i<=9;i++){
                if(i==0 && sum==0) cur += rec(pos+1, dig, nums, false, sum, dp);
                else if(dig[i]==1) cur += rec(pos+1, dig, nums, false, sum + i, dp);
            }
        }
        return dp[pos][strict][sum]=cur;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> nums = numberToVector(n);
        unordered_map<int, int> dig = convertStringToInt(digits);
        vector<vector<vector<int>>> dp(10, vector<vector<int>> (2, vector<int>(82,-1)));
        return rec(0, dig, nums, true, 0, dp);
    }
};