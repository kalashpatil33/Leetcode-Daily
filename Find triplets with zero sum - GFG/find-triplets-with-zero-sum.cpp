//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
         if(n==3)
    {
        if(arr[1]+arr[2]+arr[0]==0)
        return true;
        else
        return false;
    }
    else
    {
    sort(arr,arr+n);
    int f=0;
   
      for(int i=0;i<n;i++)
      {
          while(i!=0&&i<n&&arr[i]==arr[i-1])
          {
              if(arr[i]!=0)
              f=1;
              i++;
          }
          
          int target=arr[i];
          int st=i+1;
          int end=n-1;
          while(st<end)
          {
              if((arr[st]+arr[end]+target)==0)
              {
                  return true;
              }
              if((arr[st]+arr[end]+target)>0)
              {
                  end--;
              }
              else
              st++;
          }
      }
    }
      return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends