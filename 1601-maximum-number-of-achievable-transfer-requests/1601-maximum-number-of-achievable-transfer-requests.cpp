class Solution {
public:
    int ans=0;
    void solve(int index,vector<vector<int>>& requests,vector<int> indegree,int count)
    {
        if(index==requests.size())
        {
            for(int i=0;i<indegree.size();i++)
            {
                if(indegree[i])
                    return;
            }
            ans=max(ans,count);
            return;
        }
        //request approved
        indegree[requests[index][0]]++;
        indegree[requests[index][1]]--;
        solve(index+1,requests,indegree,count+1);
        //request not approved
        indegree[requests[index][0]]--;
        indegree[requests[index][1]]++;
        solve(index+1,requests,indegree,count);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n,0);
        solve(0,requests,indegree,0);
        return ans;
    }
};