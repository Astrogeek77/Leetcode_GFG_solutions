class Solution
{
    struct TrieNode
    {
        TrieNode *children[26];
        string word;

        // constructor for trie data structure
        TrieNode(): word("")
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
    };

    public:
    // find words using dfs
    vector<string> findWords(vector<vector < char>> &board, vector< string > &words)
    {
        TrieNode *root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    // Inserts a word into the trie.
    TrieNode* buildTrie(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (int j = 0; j < words.size(); j++)
        {
            string word = words[j];
            TrieNode *curr = root;
            for (int i = 0; i < word.length(); i++)
            {
                char c = word[i] - 'a';
                if (curr->children[c] == nullptr)
                {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector < char>> &board, int i, int j, TrieNode *p, vector< string > &result)
    {
        // for each char find suitable words available in the board.
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a']) return;
        
        p = p->children[c - 'a'];
        if (p->word.size() > 0)
        {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        
        int dx[] = {-1, 0,1, 0};
        int dy[] = {0, -1, 0, 1};
        
        for(int k = 0; k < 4; k++)
        {
            int di = i + dx[k];
            int dj = j + dy[k];
            
            if(di >= 0 and di <= board.size() - 1 and dj >= 0 and dj <= board[0].size() - 1)
            {
                dfs(board, di, dj, p, result);
            }
        }
        
        // // up
        // if (i > 0) dfs(board, i - 1, j, p, result);
        // // left
        // if (j > 0) dfs(board, i, j - 1, p, result);
        // // down
        // if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
        // // right
        // if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);
        board[i][j] = c;
    }
};