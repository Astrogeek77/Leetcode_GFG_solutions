struct Node
{
    Node *links[2]; // for bits 0 and 1

    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }

    Node* get(int bit)
    {
        return links[bit];
    }
};

class Trie
{

    private:
        Node * root;

    public:

    /**Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /**Inserts numbers in bit form into the trie. */
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) &1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    /**Finds maximum XOR value from the trie. */
    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) &1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution
{
    public:
        int findMaximumXOR(vector<int> &nums)
        {
            Trie *obj = new Trie();
            int maxi = 0;
            
            for (auto num: nums)  obj->insert(num);
            for (auto num: nums) maxi = max(maxi, obj->findMax(num));
            
            return maxi;
        }
};