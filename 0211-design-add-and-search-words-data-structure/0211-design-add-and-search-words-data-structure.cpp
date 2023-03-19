class TrieNode
{
    public:
        unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode()
    {
        isWord = false;
    }
};

class WordDictionary
{
    private:
        TrieNode * root;

    public:
        WordDictionary()
        {
            root = new TrieNode();
        }

    void addWord(string word)
    {
        TrieNode *node = root;
       	// Traverse the trie for each character in the word
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
           	// If the current node does not have a child with character c,
           	// create a new node and add it as a child of the current node
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
           	// Move to the child node corresponding to character c
            node = node->children[c];
        }
       	// Mark the last node as a word node
        node->isWord = true;
    }

    bool search(string word)
    {
        return searchHelper(root, word, 0);
    }

    bool searchHelper(TrieNode *node, string &word, int index)
    {
       	// If we have reached the end of the word,
       	// check if the current node is a word node
        if (index == word.length())
        {
            return node->isWord;
        }
        char c = word[index];
        if (c == '.')
        {
           	// If the current character is a dot, we need to check all children of the current node
           	// recursively by skipping over the dot character and moving to the next character of the word
            for (auto &p: node->children)
            {
                if (searchHelper(p.second, word, index + 1))
                {
                    return true;
                }
            }
           	// If no child node matches the remaining characters of the word,
           	// return false
            return false;
        }
        else
        {
           	// If the current character is not a dot, move to the child node
           	// corresponding to that character and continue recursively
            if (node->children.find(c) == node->children.end())
            {
               	// If there is no child node corresponding to the current character,
               	// return false
                return false;
            }
            TrieNode *child = node->children[c];
            return searchHelper(child, word, index + 1);
        }
    }
};

/**
 *Your WordDictionary object will be instantiated and called as such:
 *WordDictionary* obj = new WordDictionary();
 *obj->addWord(word);
 *bool param_2 = obj->search(word);
 */