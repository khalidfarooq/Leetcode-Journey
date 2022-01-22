class Solution {
public:
    bool dfs(unordered_map<int,bool>&m, int left){
        if(m.find(left) != m.end()){
            return m[left];
        }
        
        int sqt = (int)sqrt(left);
        for(int i=1; i<=sqt; i++){
            if(!dfs(m, left-i*i)){
                m[left] = true;
                return true;
            }
        }
        m[left] = false;
        return false;
    }
    bool winnerSquareGame(int n) {
        unordered_map<int,bool>m;
        m[0] = false;
        return dfs(m,n);
    }
};

//10 -> 1,4,9,