//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string ans="";
        while(n>0)
        {
            n=n-1;
            
            char temp='A'+n%26;
            
            ans=temp+ans;   // this gives AB as ans
            // ans=ans+temp; //    this gives BA as ans
            
            n=n/26;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends