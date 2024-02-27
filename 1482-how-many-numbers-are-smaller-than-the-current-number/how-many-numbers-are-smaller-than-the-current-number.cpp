class Solution {
public:

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int>v=nums;
        map<int, int>m;
        sort(v.begin(), v.end());
        for(int i=0;i <n; i++){
            if(i>0 &&(v[i-1]==v[i]))
            continue;
           
            else
             m[v[i]]=i;
            
        }

        for(int i=0; i<n ; i++){
            nums[i]=(m[nums[i]]);
        }
        return nums;

        
    }
};