//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int>a;
        // int l=0,r=l+1;
        //  long long x=0;
        // while(l<n){
        //     x=l
        //     x=x+arr[r];
        //     if(x==s){
        //         a.push_back(l+1);
        //         a.push_back(r+1);
        //         // break;
        //         return a;
        //         }
        //         r++;
            
        //     if(x>s or r==n){
        //     l++;
        //     r=l;
        //     x=0;}}
        //     // if(x==s)
        //     // return a;
        //     // else{
        //         a.push_back(-1);
        //  return a;
        int x=arr[0],b=0;
        
        for (int i=1; i<=n;i++  ){
            while(x>s && b<i-1) {
                x=x-arr[b];
                b++;
                
            }
            if(x==s){
                a.push_back(b+1);
                a.push_back(i);
            
            return a;}
            if(i<n){
                x=x+arr[i];
            }
        }
        if(x!=s)
          {
              a.push_back(-1);
              return a;
          }
        
        
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends