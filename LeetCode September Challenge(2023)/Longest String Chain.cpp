class Solution {
private:
    unordered_map<string, int> chain_lengths;
    unordered_map<string, bool> word_set;
    int calculateChainLength(const string &word) {
        if (word_set.find(word) == word_set.end())
            return 0;
        if (chain_lengths.find(word) != chain_lengths.end())
            return chain_lengths[word];
        int chain_length = 1;
        for (int i = 0; i < word.size(); i++) {
            string new_word = word.substr(0, i) + word.substr(i + 1);
            chain_length = max(chain_length, 1 + calculateChainLength(new_word));
        }
        chain_lengths[word] = chain_length;
        return chain_length;
    }
public:
    int longestStrChain(vector<string> &words) {
        for (const auto &word : words) {
            word_set[word] = true;
        }
        int max_chain_length = -1;
        for (const auto &word : words) {
            max_chain_length = max(max_chain_length, calculateChainLength(word));
        }
        return max_chain_length;
    }
};