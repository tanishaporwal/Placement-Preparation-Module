class Solution {
public:
void solve(vector<int> &nums,int index, vector<vector<int>>&ans){
    if(index>=nums.size()){
        ans.push_back(nums);
        return;
    }
   
    for(int i=index; i<nums.size(); i++){
swap(nums[index],nums[i]);
solve(nums,index+1,ans);
        //Backtracking
swap(nums[index],nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        solve(nums,index,ans);
        return ans;

    }
};
