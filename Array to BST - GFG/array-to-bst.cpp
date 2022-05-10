// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    void preorder(vector<int> nums , vector<int>& ans , int start ,int end){
        if( start > end) return;
        
        int mid=(start+end)/2;
        ans.push_back(nums[mid]);
        preorder(nums , ans, start, mid-1);
        preorder(nums , ans, mid+1, end);
        return;
    }
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int>ans;
        int start=0,end=nums.size()-1;
        preorder(nums,ans,start,end);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends