class Solution {
public:
    vector<string> split(string s) {
        vector<string> ans;
        string temp;
        for(int i = 0; i < s.size(); i++) 
            if(s[i] == '/') {
                if(temp != "" && temp != ".") ans.push_back(temp);
                temp = "";
            }
            else temp += s[i];
        if(temp != "" && temp != ".") ans.push_back(temp);
        return ans;
    }

    string simplifyPath(string path) {
        stack<string> s;
        string ans;
        vector<string> v = split(path);
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == ".." && !s.empty()) s.pop();
            else if(v[i] != "..") s.push(v[i]); 
        }
        v.clear();
        while(!s.empty()) {
            string t = s.top();
            v.push_back(t);
            s.pop();
        }
        if(v.size() == 0) return "/";
        else {
            for(int i = v.size() - 1; i >= 0; i--) 
                ans += "/" + v[i];
            return ans;
        }
    }
};