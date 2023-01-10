class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> bank;
        
        // freq count of chars in magazine
        for(char ch: magazine)
            bank[ch]++;
        
        // compare with ransomNote chars
        for(char ch: ransomNote)
        {
            // if any letter is missing return false
            if(bank[ch] <= 0) 
                return false;
            
            // dec. the char (freq) found
            bank[ch]--;
        }
        return true;
    }
};