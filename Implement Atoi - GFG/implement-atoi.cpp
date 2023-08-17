//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    long long myatoi(int i,string &s,long long result,int sign)
     {
         if(result*sign>INT_MAX)
         return INT_MAX;
         if(result*sign<=INT_MIN)
         return INT_MIN;
        if(i>=s.size())
         {
             return result*sign;
         }
     if(s[i]<'0'||s[i]>'9')
     {
    // cout<<s[i]<<endl;     
     return -1;
     }
        

         return myatoi(i+1,s,(result*10+s[i]-'0'),sign);

        //  return result;

     }
    int atoi(string s) {
      int sign=1;
        int i=0;
         if(s[0]=='-')
         {
         sign=-1;
         i++;
         }
    //   cout<<s<<endl;
         return myatoi(i,s,0,sign);
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends