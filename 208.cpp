#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    struct Node
    {
        Node* next[27];
        Node()
        {
            for(int i=0;i<27;i++)
            {
                next[i] = NULL;
            }
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++)
        {
            int ch = word[i]-'a';
            //cout << "ins:" << word << " " << ch << endl;
            if(node->next[ch]==NULL)
            {
                node->next[ch] = new Node();
            }
            node = node->next[ch];
        }
        node->next[26] = new Node;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++)
        {
            int ch = word[i]-'a';
            //cout << word << " " << ch << endl;
            if(node->next[ch]==NULL)
            {
                return false;
            }
            node = node->next[ch];
        }
        if(node->next[26]!=NULL)
        {
            return true;
        }
        return false;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0;i<prefix.length();i++)
        {
            int ch = prefix[i]-'a';
            if(node->next[ch]==NULL)
            {
                return false;
            }
            node = node->next[ch];
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main()
{
    return 0;
}
