class Solution {
public:

    bool isValid(string s) {

        int count = 0;

        for(char ch : s) {

            if(ch == '(') {
                count++;
            }
            else if(ch == ')') {

                count--;

                if(count < 0)
                    return false;
            }
        }

        return count == 0;
    }


    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while(!q.empty()) {

            int n = q.size();

            while(n--) {

                string curr = q.front();
                q.pop();

                // Check current string
                if(isValid(curr)) {

                    ans.push_back(curr);
                    found = true;
                }

                // Agar valid mil gaya,
                // is level se aur removal nahi karna
                if(found)
                    continue;

                // Ek-ek bracket remove karo
                for(int i = 0; i < curr.size(); i++) {

                    // Sirf brackets remove karenge
                    if(curr[i] != '(' && curr[i] != ')')
                        continue;

                    // Duplicate removal avoid karo
                    if(i > 0 && curr[i] == curr[i - 1])
                        continue;

                    string next = curr.substr(0, i) +
                                  curr.substr(i + 1);

                    if(visited.find(next) == visited.end()) {

                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // Minimum removals wale level par
            // valid answer mil gaya
            if(found)
                break;
        }

        return ans;
    }
};//akd