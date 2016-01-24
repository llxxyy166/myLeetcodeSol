//
//  main.cpp
//  LeetCodeSol
//
//  Created by xinye lei on 16/1/9.
//  Copyright © 2016年 xinye lei. All rights reserved.
//

#include <iostream>
#include <string>
#include "Solution.hpp"
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

class TrieNode {
public:
    bool isWord;
    map<char, TrieNode *> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }
    void insert(string word) {
        TrieNode *temp = root;
        for (int i = 0; i < word.length(); i++) {
            if (!temp -> children.count(word[i])) {
                TrieNode *newNode = new TrieNode;
                newNode -> isWord = false;
                temp -> children[word[i]] = newNode;
            }
            temp = temp -> children[word[i]];
        }
        temp -> isWord = true;
    }
    bool search(string word) {
        TrieNode *temp = root;
        int i = 0;
        while (temp && i < word.length()) {
            if (!temp -> children.count(word[i])) {
                return false;
            }
            temp = temp -> children[word[i]];
            i++;
        }
        if (!temp -> isWord) {
            return false;
        }
        return true;
    }
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        int i = 0;
        while (temp && i < prefix.length()) {
            if (!temp -> children.count(prefix[i])) {
                return false;
            }
            temp = temp -> children[prefix[i]];
            i++;
        }
        return true;
    }
private:
    TrieNode *root;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution ans;
//    std::vector<int> nums;
//    for (int i =1; i <= 5; i++) {
//        nums.push_back(i);
//    }
//    std::vector<std::vector<int>> res = ans.permute46(nums);
//    for (int i = 0; i < res.size(); i++) {
//        std::vector<int> p = res[i];
//        for (int j = 0; j < p.size(); j++) {
//            std::cout << p[j];
//        }
//        std::cout << std::endl;
//    }
    Trie trie;
//    trie.insert("a");
//    trie.insert("to");
//    trie.insert("tea");
//    trie.insert("ted");
//    trie.insert("ten");
//    trie.insert("i");
//    trie.insert("in");
//    trie.insert("inn");
    trie.insert("abc");
    cout << trie.search("abc");
    cout << trie.search("ab");
    trie.insert("ab");
    cout << trie.search("ab");
    trie.insert("ab");
    cout << trie.search("ab");
    return 0;
}
