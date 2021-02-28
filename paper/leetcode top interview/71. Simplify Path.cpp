class Solution {
public:
    string simplifyPath(string path)
    {
        vector<string> vec;
        char *str = new char[path.length() + 1], *p = nullptr;
        string result;

        strcpy(str, path.data());
        p = strtok(str, "/");
        while(p != NULL)
        {
            if(strcmp(p, ".") != 0)
            {
                if(strcmp(p, "..") == 0)
                {
                    if(vec.size() > 0){
                        vec.pop_back();
                    }
                }
                else{
                    vec.push_back(p);
                }
            }
            p = strtok(NULL, "/");
        }
        delete[] str;

        if(vec.size() == 0){
            result += "/";
        }
        else
        {
            for(int i = 0; i < vec.size(); ++i)
            {
                result += "/";
                result += vec[i];
            }
        }
        
        return result;
    }
};