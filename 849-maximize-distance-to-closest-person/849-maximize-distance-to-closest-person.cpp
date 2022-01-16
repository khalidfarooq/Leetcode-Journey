class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int>left(n);
        vector<int>right(n);
        
        left[0] = n;
        right[n-1] = n;
        for(int i=0; i<n; ++i){
            if(seats[i] == 1) left[i] = 0;
            else if(i>0) left[i] = left[i-1] + 1;
        }
        
        for(int i=n-1; i>=0; --i){
            if(seats[i] == 1) right[i] = 0;
            else if(i<n-1) right[i] = right[i+1] + 1;
        }
        for(int x : left) cout<<x<<" ";
        cout<<endl;
        
        for(int x : right) cout<<x<<" ";
        cout<<endl;
        int res = 0;
        for(int i=0; i<n; i++){
            if(seats[i] == 0){
                res = max(res,min(left[i],right[i]));
            }
        }
        return res;
    }
};