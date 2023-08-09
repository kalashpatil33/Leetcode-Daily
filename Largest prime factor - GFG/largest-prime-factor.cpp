//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    //  bool isprime(int x)
    //  {
    //      for(int i=2;i<=sqrt(x);i++)
    //      {
    //          if(x%i==0)
    //          return false;
    //      }
    //      return true;
    //  }
    long long int largestPrimeFactor(int N){
        long long ans=N;
        
        // if(N==3||N==5||N==7||N==11)
       
        for(int i=2;i<=N;i++)
        {
            
            while(N%i==0)
            {
                 N=N/i;
            }
            ans=i;
          }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends