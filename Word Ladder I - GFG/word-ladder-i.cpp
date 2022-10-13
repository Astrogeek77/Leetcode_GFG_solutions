//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
        int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
        {
            queue<pair<string, int>> q;
            q.push({ startWord, 1 });
            unordered_set<string> set(wordList.begin(), wordList.end());
            set.erase(startWord);

            while (!q.empty())
            {
                string word = q.front().first;
                int steps = q.front().second;
                q.pop();
                
                if(word == targetWord) return steps;

                for (int i = 0; i < word.size(); i++)
                {
                    char org = word[i];

                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[i] = c;
                        if (set.find(word) != set.end())
                        {
                            set.erase(word);
                            q.push({ word, steps + 1 });
                        }
                    }
                    word[i] = org;
                }
            }
            return 0;
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends