class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string , vector<string>>mp;
        
        for(string s:strs){
            
            string temp = s;
            sort(temp.begin(),temp.end());
            
            mp[temp].push_back(s);
            
        }
        
        vector<vector<string>>ans;
        
        for(auto st:mp){
            ans.push_back(st.second);
        }
        return ans;
    }
};


    