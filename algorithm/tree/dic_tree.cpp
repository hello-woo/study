class Trie {
private:
    bool isEnd;
    Trie *next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd=false;
        memset(next,0,sizeof(next));
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            if(next[i]) delete next[i];
        }
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node=this;//cur初始化为根节点指针；
        for(char c:word){
            if(node->next[c-'a']==nullptr){
                node->next[c-'a']=new Trie();
            }
            node=node->next[c-'a'];
        }
        node->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node=this;
        for(char c:word){
            node=node->next[c-'a'];
            if(node==nullptr){
                return false;
            }
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node=this;
        for(char c:prefix){
            node=node->next[c-'a'];
            if(node==nullptr){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */