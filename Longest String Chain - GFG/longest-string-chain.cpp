//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool compare(string s1,string s2)
   {
       if(s1.length()!=s2.length()+1)
       return false;

       int i=0,j=0;

       while(i<s1.length())
       {
           if(j<s2.length()&&s1[i]==s2[j])
           {
               i++;
               j++;
           }
           else{
               i++;
           }
       }
       if(i==s1.length()&&j==s2.length())
       return true;
       else
       return false;
   }
   static bool comp(string &s1,string &s2)
   {
       return s1.size()<s2.size();
   }
    int longestChain(int n, vector<string>& words) {
        sort(words.begin(),words.end(),comp);
      vector<int> dp(n,1);
      int maxi=0;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<i;j++)
          {
              if(compare(words[i],words[j])&&dp[j]+1>dp[i])
              {
                  dp[i]=dp[j]+1;
              }
          }
          if(dp[i]>maxi)
          maxi=dp[i];
      }   
      return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends