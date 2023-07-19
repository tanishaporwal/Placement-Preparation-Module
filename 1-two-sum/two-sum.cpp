class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        vector<int>v;
       map<int,int>m;
       for(int i=0; i<n.size(); i++){
           m[n[i]]=i;
       }
       
       for(int i=0; i<n.size(); i++){
           int diff=t-n[i];
          if(m.find(diff)!=m.end()){
             if(m[diff]!=i)
             return {i, m[diff]};}
          }
        
       
       
       return {-1,-1};
       
    }
}; 