#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    vector<pair<int,string>> top5; // (frequency, word)

    TrieNode() {
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

class Autocomplete {
    TrieNode* root;

public:
    Autocomplete() {
        root = new TrieNode();
    }

    void insert(string word, int freq) {
        TrieNode* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!node->children[idx])
                node->children[idx] = new TrieNode();

            node = node->children[idx];

            node->top5.push_back({freq, word});
            sort(node->top5.begin(), node->top5.end(), greater<>());
            if(node->top5.size() > 5)
                node->top5.pop_back();
        }
    }

    vector<string> getTop5(string prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            int idx = c - 'a';
            if(!node->children[idx])
                return {};
            node = node->children[idx];
        }

        vector<string> result;
        for(auto &p : node->top5)
            result.push_back(p.second);

        return result;
    }
};