class Solution
{
    public:
    int largestRectangleArea(vector<int> &heights)
    {
        // Approach

        // we find next smallest integer to the left 
        // and next smallest integer to the right
        // and then use the formula to calc widths (using indexes)
        // => Next Smallest Element to the right(NSR) - Next Smallest Element to the left(NSL)
        // we find the maximum of this widths 
        // and multiply it with our height to get the triangle of the max area

        int N = heights.size();
        int maxArea = 0, width = 0;

        stack<int> st;
        vector<int> NSR(N, N), NSL(N, -1);

        // Next Smallest Element to the left
        for (int i = 0; i < N; i++)
        {
            // we found a smaller element
            while (!st.empty() and heights[i] < heights[st.top()])
            {
                NSR[st.top()] = i;
                // cout << "NSR[i]: " << NSR[st.top()] << '\n';
                st.pop();
            }
            st.push(i);
        }
        
        // clear the stack
        while(!st.empty()) st.pop();
        
        
        // Next Smallest Element to the right
        for (int i = N - 1; i >= 0; i--)
        {
            // we found a smaller element
            while (!st.empty() and heights[i] < heights[st.top()])
            {
                NSL[st.top()] = i;
                // cout << "NSL[i]: " << NSL[st.top()] << '\n';
                st.pop();
            }
            st.push(i);
        }
        
        // calculate all the possible reactangle areas
        for(int i = 0; i < N; i++)
        {
            width = NSR[i] - NSL[i] - 1;
            
            // printf("NSR[%d]: %d - NSL[%d]: %d => %d\n", i, NSR[i], i, NSL[i], width);
            // cout << "width: " << width << endl;
            
            int newArea = width * heights[i];
            
            // printf("%d * %d => %d\n", width, heights[i], newArea);
            
            if(newArea > maxArea) maxArea = newArea;
            // maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};