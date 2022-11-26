class Solution
{
    
    void findHelper(int ind, string s, string curr, unordered_set<string> set, vector<string> &res)
    {
        if (ind == s.length())
        {
           	// when we reach string end, popback to remove the trailing space.
            curr.pop_back();
            
            // push current string to result vector
            res.push_back(curr);
        }
        
        string str = "";
        for (int i = ind; i < s.length(); i++)
        {
           	// get every substring and check if it exists in set
            str.push_back(s[i]);
            if (set.count(str))
            {
               	// we have got a word in dict 
               	// explore more and get other substrings
                findHelper(i + 1, s, curr + str + " ", set, res);
            }
        }
    }
    public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        //insert all the words in the set
        unordered_set<string> set;
        vector<string> res;
        
        for (auto word: wordDict) set.insert(word);
        
        //to store the current string 
        string curr = "";
        findHelper(0, s, curr, set, res);
        return res;
    }

};