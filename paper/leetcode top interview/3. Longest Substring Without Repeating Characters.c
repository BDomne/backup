
int lengthOfLongestSubstring(char* s) 
{
    char cnt[256], *temp, *p;
    int i, j, n=0, label;
    
    memset(cnt, 0, sizeof(char)*256);
    for(i=0; i<strlen(s); ++i){
        cnt[s[i]]++;
    }
    for(i=0; i<256; ++i)
    {
        if(cnt[i] != 0){
            n++;
        }
    }
    if(n == 1){
        return n;
    }
    temp=(char*)malloc(sizeof(char)*(n+1));
    for(i=n; i>2; --i)
    {
        memset(temp, 0, sizeof(char)*(n+1));
        p=s;
        while(1)
        {
            memcpy(temp, p, i);
            memset(cnt, 0, sizeof(char)*256);
            for(j=0; j<i; ++j){
                cnt[temp[j]]++;
            }
            label=1;
            for(j=0; j<i; ++j)
            {
                if(cnt[temp[j]] != 1)
                {
                    label=0;
                    break;
                }
            }
            if(label == 1){
                break;
            }
            p=p+1;
            if(*(p+i-1) == '\0'){
                break;
            }
        }
        if(label == 1){
            break;
        }
    }
    free(temp);
    
    return i;
}
