class Solution {
public:

    int minJumps(vector<int>& arr) {
        multimap<int,int>mm;
        int n = arr.size();
        
        for(int i=0; i<n; ++i){
            mm.insert({arr[i],i});
        }
        
        vector<bool>vis(n,false);
        vector<int>steps(n,0);
        queue<int>q;
        int end = arr.size()-1;
        
        vis[0] = true;
        steps[0] = 0;
        q.push(0);
        
        while(!q.empty()){
            int i = q.front();
            q.pop();
            
            if(i == end) return steps[i];
            
            
            if(i+1<arr.size() && !vis[i+1]){
                vis[i+1] = true;
                q.push(i+1);
                steps[i+1] = steps[i]+1;
            }
            if(i-1>=0 && !vis[i-1]){
                vis[i-1] = true;
                q.push(i-1);
                steps[i-1] = steps[i]+1;
            }
            if(mm.find(arr[i]) != mm.end()){
                auto p = mm.equal_range(arr[i]);
                for(auto it = p.first; it!=p.second; ++it){
                    int j = it->second;
                    if(i!=j && vis[j] == false){
                        vis[j] = true;
                        steps[j] = steps[i]+1;
                        q.push(j);
                    }
                }
                mm.erase(arr[i]);
            }
        }
        return 0;
    }
};