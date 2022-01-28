class WordDictionary {
    unordered_map<int, vector<string>>m;
    bool isEqual(string s1 , string s2){
        for(int i=0; i<s1.length(); i++){
            if(s2[i] == '.') continue;
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        m[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto &&s : m[word.size()]){
            if(isEqual(s,word)) 
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */