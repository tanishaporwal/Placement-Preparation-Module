class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>v(nums.size());
        int sum=0;
        
        for(int i=nums.size()-1; i>=0; i--){
            v[i]=sum;
            sum+=nums[i];
        }
        
      int x=0;
      for(int i=0; i<nums.size(); i++){
          v[i]=abs(v[i]-x);
          x=x+nums[i];
      }
        return v;
    }
};