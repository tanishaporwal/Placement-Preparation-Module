class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        vector<int>v;
        stack<int>s;
        s.push(-1);
        for(int i = nums2.size()-1; i >= 0; i--){
            while(!s.empty() && s.top()<nums2[i]){
                s.pop();
            }
            if(s.empty()){
                m[nums2[i]] = -1;
            }
            else{
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        for(auto it:nums1){
            v.push_back(m[it]);
        }
        return v;
    }
};