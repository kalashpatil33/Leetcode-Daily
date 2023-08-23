//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	   int n=grid.size();
    int m=grid[0].size();
    int p=word.size();
    set<vector<int>> result_set;
    vector<int> dx = {-1, 1, 0, 0, -1, 1, -1, 1};
    vector<int> dy = {0, 0, -1, 1, -1, -1, 1, 1};
 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (grid[i][j] == word[0]) 
            { // If the first character matches
                for (int dir = 0; dir < 8; dir++) 
                { // Check all 8 directions
                    int x = i, y = j, k;
                    for (k = 0; k < p; k++) 
                    {
                        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != word[k])
                            break;
                        x += dx[dir];
                        y += dy[dir];
                    }
                    if (k == p) 
                    { // If the word is found
                        vector<int> location = {i, j};
                        result_set.insert(location);
                    }
                }
            }
        }
    }
    vector<vector<int>> result(result_set.begin(), result_set.end());
    
    return result;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends