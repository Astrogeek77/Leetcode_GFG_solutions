// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
       {
           // Write Your Code here
           sort(candies,candies+N);
           int t1=0,t2=0,i=0,min=0,max=0;
           while(N>t1){
               min+=candies[i];
               i++;
               t1+=(K+1);
           }
           i=N-1;
           while(N>t2){
               max+=candies[i];
               i--;
               t2+=(K+1);
           }
           return{min,max};
       }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends