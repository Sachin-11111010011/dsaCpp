#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    string words[] = {"pay", "attention", "practice", "attend","atlas"};
    string pref = "at";

    
    int size = sizeof(words) / sizeof(string);
    cout << "Size of array: " << size << endl;

    // Example loop to count words starting with 'pref'
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (words[i].rfind(pref, 0) == 0) { // Check if the word starts with 'pref'
            count++;
        }
    }

    cout << "Number of words starting with '" << pref << "': " << count << endl;

    return 0;
}

// Leetcode One -------------------------------------------------------------------

// By using Brute Force

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
       
        for(string &word : words){
            if(word.find(pref)==0){
                count++;
            }
        }
        return count;
    }
};

// By using Trie Data Structure

struct trieNode{
    trieNode* children[26];
    bool isEndOfWord;
    int count;      // count of prefix ending at this node                  
};

trieNode* getNode(){
    trieNode* newNode = new trieNode();
    newNode-> isEndOfWord =false;
    newNode-> count = 0 ;

    for( int i=0; i<26; i++){
        newNode->children[i] = NULL;
    }

    return newNode;
}

class Trie{
    public:
    trieNode* root;

    Trie(){
        root = getNode();
    }

    void insert(string &word){
        trieNode* pCrawl= root;
        for( char &ch : word){
            int idx = ch - 'a';
            if(pCrawl->children[idx] == NULL){
                pCrawl->children[idx] = getNode();
            }
            pCrawl = pCrawl -> children[idx];
            pCrawl -> count++; // Count increased for prefix ending at this character node 
        }
        pCrawl-> isEndOfWord = true;
    }

    int searchPrefixCount(string &pref){
        trieNode* pCrawl =  root;
        for(  char &ch : pref  ){
            int idx = ch - 'a';
            if( pCrawl -> children [idx] == NULL){
                return 0;
            }
            pCrawl = pCrawl -> children[idx];
        }
        return pCrawl-> count; // count of prefix ending at the last character of pref wala node
    }
};

class Solution {
public:

    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        for( string &word : words){
            trie.insert(word);
        }
        return trie.searchPrefixCount(pref);
    }
};