class Solution {
public:

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
  
        
        unordered_map<int,int>m;
        int n = tops.size();
        for(int i=0; i<n; i++){
            m[tops[i]]++;
            m[bottoms[i]]++;
        }
        int max_ele = 0 , max_freq = -1;
        for(auto x : m){
            if(max_freq < x.second){
                max_freq = x.second;
                max_ele = x.first;
            }
        }
        int ctr_common = 0, ctr_top = 0, ctr_bottom = 0; // for max_ele
        for(int i=0; i<n; i++){
            if(tops[i] == max_ele && bottoms[i] == max_ele) ctr_common++;
            if(tops[i] == max_ele) ctr_top++;
            if(bottoms[i] == max_ele) ctr_bottom++;
        }
        cout<<ctr_common<<" "<<ctr_top<<" "<<ctr_bottom<<endl;
        if(ctr_top+ctr_bottom-ctr_common != n) return -1;
        return min(ctr_top, ctr_bottom) - ctr_common;
    }
};

