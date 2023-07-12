//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        int n=V;
        vector<int> adjrev[n]; //We have reversed the adjacency list
         //We did so inorder to apply toposort..
        vector<int> indegree(n,0);
        vector<int> ans;
      for(int i=0;i<n;i++)
      {
          for(auto it:adj[i])
          {
              adjrev[it].push_back(i);
              indegree[i]++;
          }
      }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adjrev[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
//Time complexity is O(N+V) vertex plus edges

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends