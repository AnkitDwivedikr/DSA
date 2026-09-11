class Solution {
public:
    int strStr(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        for(int i=0; i<=n-m; i++){
            int j=0;
            for(j=0; j<m; j++){
                if(s1[i+j] != s2[j]){
                    break;
                }
            }
            if(j==m)
            return i;
        }
        return -1;
    }
};