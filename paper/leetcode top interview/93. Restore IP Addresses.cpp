class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        searchIpAddress(s, 4, "", result);
        return result;
    }
private:
    bool isValid(string s)
    {
        bool result = false;

        if(s.length() == 1){
            result = true;
        }
        else
        {
            if(s[0] != '0')
            {
                int num = stoi(s);
                if(num < 256){
                    result = true;
                }
            }
        }

        return result;
    }

    void searchIpAddress(string s, int cnt, string ipaddr, vector<string>& result)
    {
        if(s.length() >= cnt && s.length() <= cnt * 3)
        {
            if(cnt == 1)
            {
                if(isValid(s))
                {
                    ipaddr += s;
                    result.push_back(ipaddr);
                }
            }
            else
            {
                string str, tmp = ipaddr;
                for(int i = 0; i < 3 && i < s.length(); ++i)
                {
                    str = s.substr(0, i + 1);
                    if(isValid(str))
                    {
                        ipaddr += str;
                        ipaddr += ".";
                        searchIpAddress(s.substr(i + 1), cnt - 1, ipaddr, result);
                        ipaddr = tmp;
                    }
                }
            }
        }
    }
};