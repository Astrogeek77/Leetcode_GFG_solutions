// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool partitionArray(int N, int K, int M, vector<int> &A){
        sort(A.begin(), A.end());
        deque <int> q;
        q.push_back(0);
        for(int i=K-1; i<N; i++){
            while(i-q.front()+1 >= K){
                if(A[i]-A[q.front()] <= M){
                    q.push_back(i+1);
                    break;
                }
                q.pop_front();
                if(q.empty())
                    return false;
            }
        }
        return q.back() == N;
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends