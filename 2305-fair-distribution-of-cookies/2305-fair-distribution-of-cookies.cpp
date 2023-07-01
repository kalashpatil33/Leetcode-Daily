class Solution {
public:
    void solve(int j,vector<int> &ans,vector<int> &sum
    ,vector<int> &A,int k)
    {
        if(j==A.size())
        {
            int x=0;
           for(auto it:sum)
           {
            //    cout<<it<<" ";
               x=max(x,it);
           }
            ans.push_back(x);
           return;
        }
        for(int i=0;i<k;i++)
        {
            // cout<<i<<" "<<j<<" "<<endl;
            sum[i]=sum[i]+A[j];
            solve(j+1,ans,sum,A,k);
            sum[i]=sum[i]-A[j];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> a;
        vector<int> sum(k,0);
        solve(0,a,sum,cookies,k);
        int ans=*min_element(a.begin(),a.end());
        return ans;
    }
};