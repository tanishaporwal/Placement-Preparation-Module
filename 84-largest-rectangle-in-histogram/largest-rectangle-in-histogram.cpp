class Solution {
    public:
    vector<int> nextelement (vector<int>heights, int n){
        vector<int>prev(n);
        stack<int>s;
        s.push(-1);
        for(int i=n-1; i>=0; i--){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr)
            s.pop();
            prev[i]=s.top();
            s.push(i);
        }
        return prev;
    }
   
    vector<int>previous(vector<int>heights, int n){
        vector<int>next(n);
        stack<int>s;
        s.push(-1);
        for(int i=0; i<n; i++){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr)
            s.pop();
            next[i]=s.top();
            s.push(i);
        }
        return next;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prev(n);
        prev=previous(heights,n);
        vector<int>next(n);
        next=nextelement(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n; i++ ){
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
};