class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        for (auto v : intervals) {
            if (v[1] < newInterval[0]) {
                ans.push_back(v);
            }
            else if (v[0] > newInterval[1]) {
                ans.push_back(newInterval);
                newInterval = v;
            }
            else {
                newInterval[0] = min(newInterval[0], v[0]);
                newInterval[1] = max(newInterval[1], v[1]);
            }
        }

        ans.push_back(newInterval);
        return ans;
    }
};//akd;