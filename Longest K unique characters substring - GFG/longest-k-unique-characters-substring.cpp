//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int j=0;
    int cnt=0;
    int ans=INT_MIN;
    vector<int> freq(26,0);
    for(int i=0;i<s.length();i++)
    {
        
         while((cnt<k||freq[s[j]-'a']!=0)&&j<s.length())
         {
             if(freq[s[j]-'a']==0)
             {
                 freq[s[j]-'a']++;
                 cnt++;
             }
             else{
                  freq[s[j]-'a']++;
             }
             j++;
         }
         ans=max(ans,j-i);
         
         while(i<s.length())
         {
             freq[s[i]-'a']--;
             if(freq[s[i]-'a']==0)
             {
             cnt--;
             break;
             }
             i++;
         }
    }
    if(ans<k)
    return -1;
    return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends