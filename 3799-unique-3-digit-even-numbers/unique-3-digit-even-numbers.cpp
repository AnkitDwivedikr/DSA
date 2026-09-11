class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        set<int> st;

        int n = digits.size();

        for (int i = 0; i < n; i++) {          // hundreds
            for (int j = 0; j < n; j++) {      // tens
                for (int k = 0; k < n; k++) { // units

                    // same digit position use nahi karna
                    if (i == j || i == k || j == k)
                        continue;

                    // first digit 0 nahi ho sakta
                    if (digits[i] == 0)
                        continue;

                    // last digit even hona chahiye
                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};//akd