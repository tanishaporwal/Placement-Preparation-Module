class Solution {
public:
    void solve(string &digits, string output,vector<string>&mapping, int index, vector<string>&ans ){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int value=digits[index]-'0';
        for(int i=0; i<mapping[value].length(); i++){
        output.push_back(mapping[value][i]);
        solve(digits,output,mapping,index+1,ans);
        output.pop_back();}
        
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output="";
        vector<string> mapping{"","","abc","def","ghi","jkl", "mno","pqrs","tuv","wxyz"};
        int index=0;
        if(digits.length()==0){
            return ans;
        }
        solve(digits,output,mapping,index,ans);
        return ans; 
    }
};