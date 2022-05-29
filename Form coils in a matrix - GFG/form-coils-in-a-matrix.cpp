// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        vector<vector<int>>m(4*n, vector<int>(4*n));
        int k=1;
        for(int i=0;i<4*n;i++)
            for(int j=0;j<4*n;j++)
                m[i][j]=k++; 
                
        int a = 0, b= 0, c = 4*n, d = c-1;
        vector<int>res1;
        while(c>a and d>b)
        {
            for(int i=a;i<c;i++)
                res1.insert(res1.begin(),m[i][b]);
            a++,b++;
            
            for(int j=b;j<d;j++)
                res1.insert(res1.begin(),m[c-1][j]);
            b++,c--;

            for(int i=c-1;i>=a;i--)
                res1.insert(res1.begin(),m[i][d-1]);
            c--,d--;

            for(int j=d-1;j>=b;j--)
                res1.insert(res1.begin(),m[a][j]);
            a++,d--;
        }

        vector<int>res2;
        a=4*n-1,b=a,c=0,d=1;
        while(a>c and b>d)
        {
            for(int i=a;i>=c;i--)
                res2.insert(res2.begin(),m[i][b]);
            a--,b--;

            for(int j=b;j>=d;j--)
                res2.insert(res2.begin(),m[c][j]);
            b--,c++;

            for(int i=c;i<=a;i++)
                res2.insert(res2.begin(),m[i][d]);
            c++,d++;

            for(int j=d;j<=b;j++)
                res2.insert(res2.begin(),m[a][j]);
            a--,d++;
        }
        return {res2,res1};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends