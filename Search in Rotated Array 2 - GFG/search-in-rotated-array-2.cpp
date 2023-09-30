//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& x, int key) {
        // Code here
        
        // int n=x.size();
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(x[mid]==key)
            return true;
            
            while(x[l]==x[mid] && x[mid]==x[h])
            {
            l++;
            h--;
            }
            
            if(x[l]<=x[mid])              //array is sorted in left half
            {
                if(x[l]<=key && key<=x[mid])
                {
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{                //sorted right half
                if(x[mid]<x[h])
                {
                    if(x[mid]<=key && key<=x[h])
                    {
                        l=mid+1;
                    }
                    else{
                        h=mid-1;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends