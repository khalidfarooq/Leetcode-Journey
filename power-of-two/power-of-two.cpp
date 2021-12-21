class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        int low = 0, high=31;
        while(low<high){
            int mid = low +(high-low)/2;
            int temp = pow(2,mid);
            if(n == temp) return true;
            else if(n > temp) low = mid+1;
            else high = mid;
        }
        return false;
    }
};
