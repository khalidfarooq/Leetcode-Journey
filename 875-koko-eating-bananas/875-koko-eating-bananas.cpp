class Solution {
public:
    int isPossible(vector<int>&piles, int h, int curr_k){
        int reqHours = 0;
        for(int p : piles){
            reqHours += ceil((double)p/(double)curr_k);
        }
        return reqHours<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = pow(10,9);
        int res = 0;
        while(low < high){
            int mid = low + (high-low)/2;
            
            if(isPossible(piles,h,mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};