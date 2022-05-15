// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    void AllSubsets(vector<int> arr, int n, int index, vector<vector<int>>& result, vector<int>& subset)
    {
        result.push_back(subset);
        for (int i = index; i < n; ++i)
        {
            subset.push_back(arr[i]);
            AllSubsets(arr, n, i+1, result, subset);
            subset.pop_back();
            while (i < n-1 && arr[i+1] == arr[i]) ++i;
        }
    }
    
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> result; // result vector
        vector<int> subset; // all possible subsets
        sort(arr.begin(), arr.end()); // lexographic ordering
        AllSubsets(arr, n, 0, result, subset); // recursive backtracking helper func
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends