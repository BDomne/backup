
char* longestPalindrome(char* s) 
{
    char *temp, *p;
    int i, j, len, label;
    
    if(strcmp(s, "") == 0){
        return s;
    }
    len=strlen(s);
    if(len == 1){
        return s;
    }
    temp=(char*)malloc(sizeof(char)*(len+1));
    for(i=len; i>1; --i)
    {
        memset(temp, 0, sizeof(char)*(len+1));
        p=s;
        while(1)
        {
            memcpy(temp, p, i);
            label=1;
            for(j=0; j<i/2; ++j)
            {
                if(temp[j] != temp[i-j-1])
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
    if(i == 1)
    {
        memset(temp, 0, sizeof(char)*(len+1));
        memcpy(temp, s, 1);
    }
    
    return temp;
}
