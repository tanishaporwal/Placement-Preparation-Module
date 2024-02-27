class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int greatest=INT_MIN;
        for(int i=0; i<n; i++){
            if((i==0 && nums[i]>nums[i+1] && nums[i]>greatest) ||(i==n-1 && nums[i]>nums[i-1] && nums[i]>greatest)  ){
                 greatest=i;
            }
            else if((i>0 && i<n-1)&&(nums[i]>nums[i-1] && nums[i]>nums[i+1]) && nums[i]>greatest)           
            {
                greatest=i;
              }
              
        }
        return greatest;
        
    }
};