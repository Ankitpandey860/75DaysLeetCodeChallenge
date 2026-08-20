class TrieNode{
    public:
    bool is=false;
    TrieNode* children[26];
    bool isterminal;
    void add(string &s,int i){
        int idx=s[i]-'a';
        if(children[idx]==NULL){
            children[idx]=new TrieNode();
        }
        if(i==s.length()-1){
            children[idx]->isterminal=true;
            children[idx]->is=true;
            return ;
        }
        
        
        if(i<s.length()-1){
            children[idx]->add(s,i+1);
        }
        children[idx]->is=true;
    }
    bool search(string& s,int i){
        int idx=s[i]-'a';
        if(i==s.length()-1){
            if(idx==-51){
                bool ans=false;
                for(auto &it:children){
                    if(it!=NULL&&it->isterminal){
                        return true;
                    }
                }
                return ans;
            }
            return children[idx]==NULL?false:children[idx]->isterminal;;
        } 
        if(idx==-51){
            bool ans=false;
            for(auto &it:children){
                if(it!=NULL&&it->is){
                    ans|=it->search(s,i+1);
                }
            }
            return ans;
        }
        else if(children[idx]==NULL){
            return false;
        }
        else if(children[idx]->is){
            return children[idx]->search(s,i+1);
        }
        return false;
    }

};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        root->add(word,0);
    }
    
    bool search(string word) {
        return root->search(word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */