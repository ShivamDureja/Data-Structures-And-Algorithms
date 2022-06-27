#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    // inserting word
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // searching word
    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        // mapping
        int index = word[0] - 'A';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    // removing word (NOT OPTIMIZED)
    void removeUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        removeUtil(root->children[index], word.substr(1));
    }

    void removeWord(string word)
    {
        removeUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("TIM");
    t->insertWord("TIME");
    t->insertWord("TIMER");
    t->insertWord("ARE");
    t->insertWord("BOB");
    cout << "Searching .... " << t->searchWord("TME") << endl;
    t->removeWord("TIM");
    cout << t->searchWord("TIM")<<endl;
    t->insertWord("TIM");
    cout << t->searchWord("TIM");

    return 0;
}