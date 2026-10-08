class Solution {
public:
    NestedInteger deserialize(string s) {
        
     stack<NestedInteger> st;
     int num = 0;
     bool negative = false;

     for(int i=0; i<s.size(); i++){
        if(s[i]=='-' || (s[i] >= '0' && s[i] <= '9')){
            
            if(s[i] == '-'){
                negative = true;
            }
            else{
                num = num*10 + (s[i] - '0');

                if(i+1 == s.size() || s[i+1] == ',' || s[i+1]==']')
                {
                    if(negative)
                    num = -num;

                   NestedInteger temp(num);

                    if(st.empty())
                    return temp;

                    st.top().add(temp);

                    num = 0;
                    negative = false;
                }
            }
        }

        else if(s[i] == '['){
            st.push(NestedInteger());
        }

        else if(s[i] == ']'){

           NestedInteger temp = st.top();
            st.pop();

            if(st.empty())
            return temp;

            st.top().add(temp);
        }

     }
     
     return NestedInteger(num);

    }
};