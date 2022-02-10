class Solution {
public:
    
    /*
              curr_sum
        ___________________
        -,-,-,-,-,-,-,-,-,cur_index
        _________ _________
       curr_sum-k    k
    */
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int curr_sum = 0, count = 0;
        for(int x : nums){
            curr_sum += x;
            if(curr_sum == k) count++;
            
            if(m.find(curr_sum - k) != m.end())
                count += m[curr_sum-k];
            
            if(m.find(curr_sum) != m.end()){
                m[curr_sum]++;
            }else{
                m[curr_sum] = 1;
            }
         
        }
        return count;
    }
};