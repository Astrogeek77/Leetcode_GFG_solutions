struct Node
{
    Node *links[26];
    bool flag = false;

    // check if a key(char) exist in Trie
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // add a node
    void add(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // get a node 
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    // mark ending of a word
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node * root;

    public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // if the trie does not contain a char add a new node with the char.
            if (!(node->containsKey(word[i])))
            {
                node->add(word[i], new Node());
            }
            // set node to the new node
            node = node->get(word[i]);
        }
        // after completion of word, mark end
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // check of the trie contains a node with given char value.
            if (!(node->containsKey(word[i])))
            {
                return false;
            }
            // set node to the node to be found
            node = node->get(word[i]);
        }
        // if the word is found end will be marked true, else false.
        return node->isEnd();
    }

    bool startsWith(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // check of the trie contains a node with given char value.
            if (!(node->containsKey(word[i])))
            {
                return false;
            }
            // set node to the node to be found
            node = node->get(word[i]);
        }
        // same working as search just checking for the end is avoided.
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */