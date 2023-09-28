//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int ans=0;
    void merge (vector<int> &arr,int l,int mid,int h)
    {
        int i=l,j=mid+1,k=l;
        
        vector<int> a;
        
        while(i<=mid && j<=h)
        {
            if(arr[i] > arr[j])
            {
                a.push_back(arr[j++]);
            }
            else{
                 a.push_back(arr[i++]);
            }
        }
        
        while(i<=mid)
        {
           a.push_back(arr[i++]);
        }
            while(j<=h)
        {
           a.push_back(arr[j++]);
        }
        int x=0;
        for(int i=l;i<=h;i++)
        {
            arr[i]=a[x++];
        }
    }
     void fun(vector<int> &arr,int low,int mid,int high)
  {
      int right=mid+1;
      for(int i=low;i<=mid;i++)//for the first array
      {
          while(right<=high && arr[i]>2*arr[right])
          {
              right++;
          }
          ans+=right-(mid+1);
      }
  }
    void mergeSort(vector<int> &arr,int l,int h)
    {
        if(l==h)
        return;
        
        int mid=(l+h)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
         fun(arr,l,mid,h);
        merge(arr,l,mid,h);
    }
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        
        mergeSort(arr,0,n-1);
        return ans;
        
    }
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends