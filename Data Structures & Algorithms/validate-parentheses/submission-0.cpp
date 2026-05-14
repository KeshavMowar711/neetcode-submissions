class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char c : s)
        {
            // opening brackets
            if(c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                // no opening bracket
                if(st.empty())
                    return false;

                char top = st.top();

                // wrong matching
                if(c == ')' && top != '(')
                    return false;

                if(c == ']' && top != '[')
                    return false;

                if(c == '}' && top != '{')
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};