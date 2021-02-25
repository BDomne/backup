class Solution {
public:
    Solution() {init();}
    int numDecodings(string s) 
    {
        int result = 1, cnt;
        const char *str = s.c_str(), *p, *q;

        p = str;
        while((q = strchr(p, '0')) != NULL)
        {
            if(q == str || (*(q - 1) != '1' && *(q - 1) != '2')){
                result = 0;
                break;
            }
            p = q + 1;
        }

        if(result == 1)
        {
            p = strchr(str, '1');
            q = strchr(str, '2');
            while(p != NULL || q != NULL)
            {
                if(p != NULL && q != NULL){
                    if(p > q){
                        p = q;
                    }
                }
                else{
                    if(p == NULL){
                        p = q;
                    }
                }
                cnt = 0;
                while(*(p + cnt) == '1' || *(p + cnt) == '2'){
                    ++ cnt;
                }
                str = p + cnt;
                if(*(p + cnt) == '0')
                {
                    cnt -= 2;
                    if(cnt < 0){
                        cnt = 0;
                    }
                }
                if(*(p + cnt) == '\0' || (*(p + cnt -1) == '2' && *(p + cnt) > '6')){
                    -- cnt;
                }
                result *= value[cnt];
                p = strchr(str, '1');
                q = strchr(str, '2');
            }
        }

        return result;
    }
private:
    vector<long> value;

    void init()
    {
        value.push_back(1);
        value.push_back(2);
        for(int i = 0; i < 50; ++i){
            value.push_back(value[i] + value[i + 1]);
        }
    }
};