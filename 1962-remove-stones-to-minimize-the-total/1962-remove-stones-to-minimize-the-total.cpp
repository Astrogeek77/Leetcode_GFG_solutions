class Solution
{
    public:
        int minStoneSum(vector<int> &piles, int k)
        {
            priority_queue<int> pq;	
            for(auto x: piles) pq.push(x);
            
            int ans = 0;
            for (int i = 0; i < k; i++)
            {
                int num = pq.top();
                pq.pop();
                num = num - num / 2;
                pq.push(num);
            }
            while (!pq.empty())
            {
                ans += pq.top();
                pq.pop();
            }
            return ans;
        }
};