class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int>s;
        int j = 0;
        for(int x : pushed){
            s.push(x);
            while(!s.empty() && j<n && s.top() == popped[j]){
                s.pop();
                j++;
            }
        }
        return j==n;
    }
};

