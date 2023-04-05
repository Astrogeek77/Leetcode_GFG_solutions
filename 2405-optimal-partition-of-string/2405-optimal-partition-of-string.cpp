class Solution
{
    public:
        int partitionString(string s)
        {
            int xr = 0, ans = 1;
            for (int i = 0; i < s.size(); i++)
            {
                if (xr &(1 << (s[i] - 'a')))
                {
                    xr = 0;
                    ans++;
                }
                xr ^= (1 << (s[i] - 'a'));
            }
            return ans;
        }
};

// class Solution:
//     def partitionString(self, s: str) -> int:
//         ans=1
//         ls=[]
//         for i in s:
//             if i in ls:
//                 ls=[i]
//                 ans+=1
//             else:
//                 ls+=[i]
//         return ans