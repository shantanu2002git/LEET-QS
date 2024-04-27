#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    Trie* children[26]; 
    bool isEndOfWord = false;

public:
   
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new Trie(); // Create a new node if not exists
            }
            node = node->children[c - 'a'];
        }
        node->isEndOfWord = true; 
    }

    // Method to search for a word in the Trie
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                return false; // Word not found
            }
            node = node->children[c - 'a'];
        }
        return node != nullptr && node->isEndOfWord; // Return true if the end of the word is reached
    }

  
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (node->children[c - 'a'] == nullptr) {
                return false; 
            }
            node = node->children[c - 'a'];
        }
        return node != nullptr; 
    }
};


