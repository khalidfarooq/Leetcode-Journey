class FreqStack {
public:
    map<int,int>freq;
    map<int,stack<int>>s;
    int maxFreq = 0;
    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;
        if(freq[val] > maxFreq){
            maxFreq = freq[val];
        }
        s[freq[val]].push(val);
    }
    
    int pop() {
        int top = s[maxFreq].top();
        s[maxFreq].pop();
        
        --freq[top];
        
        if(s[maxFreq].size() == 0){
            --maxFreq;
        }
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */