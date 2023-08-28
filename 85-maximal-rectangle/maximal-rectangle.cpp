class Solution {
    vector<int>previous(vector<int>&heights, int n){

        stack<int>s;
        s.push(-1);
        vector<int>prev(n);
        for(int i=0; i<n; i++){
            int curr=heights[i];
          while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            prev[i]=s.top();
            s.push(i);
        }
        return prev;
    }
    vector<int>nextele(vector<int>&heights, int n){

        stack<int>s;
        s.push(-1);
        vector<int>next(n);
        for(int i=n-1; i>=0; i--){
            int curr=heights[i];
          while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            next[i]=s.top();
            s.push(i);
        }
        return next;
    }
    int maxarea(vector<int>&heights){
        int n=heights.size();
        vector<int>prev;
        prev=previous(heights,n);
        vector<int>next;
        next=nextele(heights,n);
        int area=INT_MIN;
        for(int i=0; i<n; i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int res=l*b;
            area=max(area,res);


        }
        return area;


    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
       
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>heights(n,0);
      
        int ans=INT_MIN;
        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
              if(matrix[i][j]=='1')
              
             heights[j]++;
             else{
                 heights[j]=0;
             }
             
            }
           ans=max(ans,maxarea(heights));
        }
        return ans;
    }
};