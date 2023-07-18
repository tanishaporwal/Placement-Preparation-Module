class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        vector<int>v;
        map<int,bool>m;
        for(int i=0; i<nums1.size(); i++){
            m.insert({nums1[i],true});
        }
        for(int i=0; i<nums2.size(); i++){
            if(m[nums2[i]]==true){
                s.insert(nums2[i]);
            }
            
        }
        for(auto x:s){
            v.push_back(x);
        }
        return v;
    }
};