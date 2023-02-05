class Solution {
    
    vector<int> vowelWordsIndex(vector<string>& words)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> ans;
        for(int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            if((vowels.count(word[0])) and  vowels.count(word[word.size() - 1]))
            {
              ans.push_back(i);
            }
        }
        return ans;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        // unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> ans;
        vector<int> idx = vowelWordsIndex(words);
        
        for(auto q: queries)
        {
            int left = q[0];
            int right = q[1];
            
            int count = 0;
            for(int x: idx)
            {
               if(x >= left and x <= right) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};