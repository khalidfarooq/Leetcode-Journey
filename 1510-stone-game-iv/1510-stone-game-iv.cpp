class Solution {
public:
//     bool dfs(unordered_map<int,bool>&m, int left){
//         if(m.find(left) != m.end()){
//             return m[left];
//         }
        
//         int sqt = (int)sqrt(left);
//         for(int i=1; i<=sqt; i++){
//             if(!dfs(m, left-i*i)){
//                 m[left] = true;
//                 return true;
//             }
//         }
//         m[left] = false;
//         return false;
//     }
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1);
        for(int i=0; i< n+1; i++){
            for(int k = 1; k*k<=i; k++){
                if(dp[i-k*k] == false){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
        // unordered_map<int,bool>m;
        // m[0] = false;
        // return dfs(m,n);
    }
};

//10 -> 1,4,9,