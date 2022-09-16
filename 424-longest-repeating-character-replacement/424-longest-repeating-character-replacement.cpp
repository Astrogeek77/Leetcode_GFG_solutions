class Solution
{
    public:
        int characterReplacement(string s, int k)
        {
            int n = s.size();
            int i = 0, j = 0; // sliding window pointers
            
            int ans = -1;
            int maxi = -1;
            
            map<char, int> mp;
            
            while (j < n)
            {
                mp[s[j]]++;
                maxi = max(maxi, mp[s[j]]);
                
                if (j - i + 1 > maxi + k)
                {
                    mp[s[i]]--;	// decrease the count of char
                    i++;	//slide window towards right
                }
                
                ans = max(ans, j - i + 1);
                j++;
            }
            
            return ans;
        }
};