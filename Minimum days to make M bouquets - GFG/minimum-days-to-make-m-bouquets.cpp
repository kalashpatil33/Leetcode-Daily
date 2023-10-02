//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool ispossible(vector<int> &bloomDay,int hours,int m,int k)
    {
        int  c=0,d=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++)
        {
            if(c==k)
            {
                d++;
                c=0;
            }
            if(bloomDay[i]<=hours)
            {
                c++;
            }
            else{
                c=0;
            }
        }
        d=d+c/k;
        if(d>=m)
        return true;
        return false;
    }
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      int maxi=*max_element(bloomDay.begin(),bloomDay.end());
      int mini=*min_element(bloomDay.begin(),bloomDay.end());
      int n=bloomDay.size();
      if(M*K>n)
      return -1;
      long long ans=-1;
      long long l=mini,h=maxi;
      while(l<=h)
      {
          long long mid=(l+h)/2;
           bool check=ispossible(bloomDay,mid,M,K);
           
           if(check)
           {
           h=mid-1;
           ans=mid;
           }
           else{
               l=mid+1;
           }
          
          
      }
      return ans;
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends