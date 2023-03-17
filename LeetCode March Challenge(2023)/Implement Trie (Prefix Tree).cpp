class TrieNode {
  public:
    vector<TrieNode*> dict;
    bool isEnd;
    TrieNode() {
        isEnd = false;
        dict.resize(26, nullptr);
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++) {
            if(node->dict[s[i]-'a']==nullptr) {
                node->dict[s[i]-'a'] = new TrieNode();
            }
            node = node->dict[s[i]-'a'];
        }
        node->isEnd = true;
    }
    bool search(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++) {
            if(node->dict[s[i]-'a']==nullptr)
                return false;
            node = node->dict[s[i]-'a'];
        }
        return node->isEnd;
    }
    bool startsWith(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++) {
            if(node->dict[s[i]-'a']==nullptr)
                return false;
            node = node->dict[s[i]-'a'];
        }
        return true;
    }
};