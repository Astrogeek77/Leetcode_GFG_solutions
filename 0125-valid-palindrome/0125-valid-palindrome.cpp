class Solution {
public:
    bool isPalindrome(string s) 
    {
        
        // count the number of alphanumerics in the string.
        string raw;
        for(char ch: s)
        {
            if((ch >= 'a' and ch <= 'z') or (ch >= '0' and ch <= '9'))
                raw.push_back(ch);
            else if (ch >= 'A' and ch <= 'Z')
                raw.push_back(ch - 'A' + 'a'); // convert upper to lower
        }
        
        // compare the string from front and back
        int left = 0, right = raw.size() - 1;
        while(left < right)
        {
            if(raw[left] != raw[right]) return false;
            
            left++;
            right--;
        }
        return true;
    }
};