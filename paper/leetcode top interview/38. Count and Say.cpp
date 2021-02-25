class Solution {
public:
    string countAndSay(int n) 
    {
        string result = "";
        
        if(n == 1){
            result += "1";
        }
        else
        {
            string str = countAndSay(n - 1);
            int pos = 0, cnt = 1;
            string c1 = str.substr(pos, 1), c2;
            while(pos + cnt < str.size())
            {
                c2 = str.substr(pos + cnt, 1);
                if(c1.compare(c2) == 0){
                    ++cnt;
                }
                else
                {
                    result += to_string(cnt) + c1;
                    c1 = c2;
                    pos += cnt;
                    cnt = 1;
                }
            }
            result += to_string(cnt) + c1;
        }
        
        return result;
    }
};