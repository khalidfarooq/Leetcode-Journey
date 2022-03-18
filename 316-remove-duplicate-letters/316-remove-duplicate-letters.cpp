class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,bool>visited;
        unordered_map<char,int>freq;
        string res ="";
        int n = s.length();

        for(int i=0; i<n; i++){ 
            freq[s[i]]++;
            visited[s[i]] = false;
        }
        stack<char>st;
        st.push(s[0]);
        visited[s[0]] = true;
        for(int i=1; i<n; i++){
           if(s[i] <= st.top()){
               if(!visited[s[i]]){
                   while(!st.empty() && s[i] < st.top() && freq[st.top()] > 1){
                       freq[st.top()]--;
                       visited[st.top()] = false;
                       st.pop();
                   }
                   st.push(s[i]);
                   visited[s[i]] = true;
               }else{
                   freq[s[i]]--;
               }
           }else{
               if(!visited[s[i]]){
                   st.push(s[i]);
                   visited[s[i]] = true;
               }
           }
        }
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};