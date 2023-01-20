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
        this->data = ch;
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
        root = new TrieNode('/');
    }
    void inserUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumsion, all the word in the array will capital and in range A-Z
        int index = word[0] - 'A';

        TrieNode *child;

        // present in root children
        if (root->children[index] != NULL)
        {
            root = root->children[index];
        }
        // not present
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        inserUtil(child, word.substr(1));
    }

    void inserWord(string word)
    {
        inserUtil(root, word);
    }

    // search
    bool searchUtil(TrieNode *root, string word)
    {

        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool trieEmpty(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                return false;
            }
        }
        return true;
    }

    TrieNode *trieDelete(TrieNode *root, string word, int height = 0)
    {

        // Condition if the tree is empty
        if (!root)
        {
            return NULL;
        }

        // The final character of the word is being handled
        if (height == word.size())
        {

            /*
                After removal of the given word/key, the last node is
                not the end of the word
            */
            if (root->isTerminal)
            {
                root->isTerminal = false;
            }

            // In case if the given word isn't prefix of any other word
            if (trieEmpty(root))
            {
                delete (root);
                root = NULL;
            }
            return root;
        }

        /*
            In case it is not the last character, repeat for the child using
            ASCII value
        */
        int index = word[height] - 'a';
        root->children[index] = trieDelete(root->children[index], word, height + 1);

        /*
            In case the root does not have any child(its only child gets
            removed), then it is not the same for another word. The another
            word does not end here.
        */
        if (trieEmpty(root) && root->isTerminal == false)
        {
            // Node deleted
            delete (root);
            root = NULL;
        }
        return root;
    }

    void deleteWord(string word)
    {
        root = trieDelete(root, word);
    }
};

int main()
{

    Trie *t = new Trie();
    t->inserWord("SUMIT");
    cout << t->searchWord("SUMIT");
    t->deleteWord("SUMIT");
    cout << t->searchWord("SUMIT");
}