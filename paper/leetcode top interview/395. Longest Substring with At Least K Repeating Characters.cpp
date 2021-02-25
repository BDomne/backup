class Solution {
public:
    void searchLongestSubstring(string s, int k, int &result)
    {
        int len = s.length();

        if(len >= k && len > result)
        {
            int cnt[26] = {0}, n = 0;
            char c[27] = {0};
            char *p = new char[len + 1], *q = nullptr, *r = nullptr;

            strcpy(p, s.data());
            for(int i = 0; i < len; ++i){
                ++ cnt[p[i] - 'a'];
            }
            for(int i = 0; i < 26; ++i)
            {
                if(cnt[i] != 0 && cnt[i] < k){
                    c[n++] = 'a' + i;
                }
            }
            if(n == 0 && len > result){
                result = len;
            }
            else
            {
                q = strtok_r(p, c, &r);
                while(q)
                {
                    searchLongestSubstring(q, k, result);
                    q = strtok_r(NULL, c, &r);
                }
            }

            delete[] p;
        }
    }

    int longestSubstring(string s, int k)
    {
        int result = 0;
        searchLongestSubstring(s, k, result);
        return result;
    }
};