class Solution {
public:
    int binary(vector<int>& nums,int s,int e,int ele){
    
    int mid=s+(e-s)/2;
    if(s>e ){
        return -1;
    }
    if(nums[mid]==ele){
        return mid ;
    }
    else if(ele<nums[mid]){
        return binary(nums,s,mid-1,ele);
    }
    else{
   
        return binary(nums,mid+1,e,ele);}
    
}
    int search(vector<int>& nums, int target) {
        
       int ans=binary(nums,0,nums.size()-1,target);
        return ans;
    }
};