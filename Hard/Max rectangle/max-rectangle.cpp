//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    vector<int>previous(int *heights, int m){
        
        vector<int>prev(m);
        stack<int>s;
        s.push(-1);
        for(int i=0; i<m; i++){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            prev[i]=s.top();
            s.push(i);
        }
        return prev;
    }
    vector<int>nextele(int *heights, int m){
    
        vector<int>next(m);
        stack<int>s;
        s.push(-1);
        for(int i=m-1; i>=0; i--){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            next[i]=s.top();
            s.push(i);
        }
        return next;
    }
    int largestarea(int *heights, int m){
    
        vector<int> prev=previous(heights,m);
        vector<int> next=nextele(heights,m);
        int area=INT_MIN;
        for(int i=0; i<m; i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=m;
            }
            int b=next[i]-prev[i]-1;
            int res=l*b;
            area=max(area, res);
        }
        return area;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        int ans=largestarea(M[0],m);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j]!=0){
                    M[i][j]=M[i-1][j]+M[i][j];
                }
                else{
                  M[i][j]=0;
                }
            }
            ans=max(ans,largestarea(M[i],m));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends