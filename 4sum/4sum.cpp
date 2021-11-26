class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n==0) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int target_2 = target - (nums[i] + nums[j]);
                int front = j+1, back = n-1;
                while(front<back){
                    int two_sum = nums[front]+nums[back];
                    if(two_sum < target_2) front++;
                    else if(two_sum > target_2) back--;
                    else{
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[front]); //2
                        temp.push_back(nums[back]);  //3
                        res.push_back(temp);
                        
                        while(front<back && nums[front] == temp.at(2)) ++front;
                        while(front<back && nums[back] == temp.at(3)) --back;                        
                    }
                }
                while(j+1<n && nums[j+1] == nums[j]) j++;
            }
            while(i+1<n && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};
/*
 7 2 1 0 2 8, t = 4
 
 
 -1 1 2 2 7 8 => [[-1,1,2,2], [2,2]]
      i j
 

*/