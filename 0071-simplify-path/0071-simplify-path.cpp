class Solution
{
    public:
        string simplifyPath(string path)
        {
            string res, tmp;
            // vector bechaving as stack
            vector<string> stk;
            
            // define string stream
            stringstream ss(path);
            
            // while we get a '/' from a str
            while (getline(ss, tmp, '/'))
            {
                // empty and '.' means current directory
                if (tmp == "" or tmp == ".") 
                    continue;
                
                // go back a directory
                if (tmp == ".." and !stk.empty()) 
                    stk.pop_back();
                
                // if any other case push the string to the vector
                else if (tmp != "..") 
                    stk.push_back(tmp);
            }
            
            // construct answer
            for (auto str: stk) 
                res += "/" + str;
            
            // last check (for empty case)
            return res.empty() ? "/" : res;
        }
};