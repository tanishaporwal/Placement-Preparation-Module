class Solution {
public:
void solve(vector<int> &w,int sum){
    
}
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=INT_MIN;
        for(int w=0;w<accounts.size(); w++){
            int sum=0;
            
            for(int j=0; j<accounts[w].size(); j++){
              sum=sum+accounts[w][j];
             
            }
            if(maxi<sum){
                maxi=sum;

            }
        }
        return maxi;
    }
};