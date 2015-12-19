class Solution {
public:
    string simplifyPath(string path) {       
        string result;
        int length = path.length();
        
        vector<string> paths;
        string onepath;
        
        bool in = false;
        
        for (int i=0; i<length; i++)
        {
            if (path[i] != '/')
                onepath += path[i];
                
            if (path[i] == '/' || i == length-1)
            {
                if (onepath == ".")
                {
                        
                }
                else if (onepath == "..")
                {
                    if (paths.size()) 
                        paths.pop_back();
                }
                else
                {
                    if (onepath.length())
                        paths.push_back(onepath);
                }
                onepath = "";
            }
        }

        
        if (paths.size())
        {
            for (int i=0,size=paths.size(); i<size; i++)
            {
                result += "/";
				result += paths[i];
            }
        }
        else
        {
            result = "/";
        }
        
        return result;
    }
};