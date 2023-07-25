class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n=candies.size();
        vector<bool>v;
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
         if(candies[i]>maxi){
             maxi=candies[i];
         }
        
        }
        for(int i=0; i<n; i++){
            if(candies[i]+extraCandies<maxi){
                v.push_back(false);
            }
            else{
               v.push_back(true);
            }
        
        }
        return v;
    }
};