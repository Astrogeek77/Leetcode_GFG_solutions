class Solution
{
    public:
        bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
        {

            int x = jug1Capacity, y = jug2Capacity, z = x + y;
            int steps[]={x, -x, -y, y};

            queue<int> q;
            vector<int> vis(z + 1, 0);
            
            q.push(0);
            vis[0] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                if (node == targetCapacity) return true;
                
                for (int i = 0; i < 4; i++)
                {
                    int newNode = node + steps[i];
                    if (newNode >= 0 && newNode <= z && vis[newNode] == 0)
                    {
                        q.push(newNode);
                        vis[newNode] = 1;
                    }
                }
            }
            return false;
        }
};