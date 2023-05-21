class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        for(int i = 0;i<n;++i) if(path[i]=='/') path[i] = ' '; 
        vector<string>v;
        stringstream s(path);
        string word;
        while(s>>word) {
            if(word=="..") {
                if(v.empty())
                continue;
                else v.pop_back();
                }
            else if(word==".")
            continue;
        else v.push_back(word);
        }
        string res = "/";
        for(auto it : v) res+= it + "/";
        if(res.back()=='/' && res.size() > 1)res.pop_back();
        return res;
    }
};