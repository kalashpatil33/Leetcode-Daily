//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

   bool ispossible(vector<int> &stalls,int distance,int k)
   {
       int n=stalls.size();
       int curr=0;
       int c=1;
       for(int i=1;i<n;i++)
       {
           if((stalls[i]-stalls[curr])>=distance)
           {
               curr=i;
               c++;
           }
           if(c>=k)
           return true;
       }
       return false;
       
   }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        // int maxi=*max_element(stalls.begin(),stalls.end());
        // int mini=*min_element(stalls.begin(),stalls.end());
        int l=1,h=stalls[n-1]-stalls[0];
        int ans=0;
        while(l<=h)
        {
        int mid=(l+h)/2;
        bool check=ispossible(stalls,mid,k);
        if(check)
        {
            // ans=l;
            l=mid+1;
        }
        else{
            h=mid-1;
         }
        }
        
        return h;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends