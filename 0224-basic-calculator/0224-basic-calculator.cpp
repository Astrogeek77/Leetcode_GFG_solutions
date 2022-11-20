class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int result = 0;
        int number = 0;
        
        int n = s.size();
        stack<int> st;
        
        for(int i = 0; i < n; i++) 
        {
            char c = s[i];
            // convert to number.
            if(c >= '0' && c <= '9') number = number * 10 + (c - '0');
            
            if(c == '-') 
            {
                result += (sign) * (number);
                number = 0;
                sign = -1;
            }
            if(c == '+') 
            {
                result += (sign) * (number);
                number = 0;
                sign = 1;
            }
            if(c == '(') 
            {
                
                st.push(result);
                // sign is pushed afterwards
                st.push(sign); 
                
                result = 0;
                sign = 1;
            }
            
            if(c == ')') 
            {
                result += (sign) * (number);
                number = 0;
                result *= st.top(); // to get the sign
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        
        result += (sign) * number;
        return result;
    }
};