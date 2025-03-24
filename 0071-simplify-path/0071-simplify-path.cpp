class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans;

        for(int i = 0; i < path.size(); i++) {
            if(path[i] == '/') 
                continue; // Skip redundant '/'

            string temp;
            while(i < path.size() && path[i] != '/') {
                temp += path[i];
                i++;
            }

            if(temp == ".") 
                continue;
            else if(temp == "..") {
                if(!st.empty()) 
                    st.pop(); // Go back one directory
            } 
            else {
                st.push(temp); // Push valid directory name
            }
        }

        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans; // Ensure at least "/"
    }
};
