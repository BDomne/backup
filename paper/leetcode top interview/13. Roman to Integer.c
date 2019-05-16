

int romanToInt(char * s)
{
    int value[26], result=0, i, n;
    
    value['I'-'A']=1;
    value['V'-'A']=5;
    value['X'-'A']=10;
    value['L'-'A']=50;
    value['C'-'A']=100;
    value['D'-'A']=500;
    value['M'-'A']=1000;
    n=strlen(s);
    
    if(n == 1){
        result=value[s[0]-'A'];
    }
    else
    {
        if(n > 1)
        {
            for(i=1; i<n; ++i)
            {
                if(value[s[i-1]-'A'] >= value[s[i]-'A']){
                    result += value[s[i-1]-'A'];
                }
                else{
                    result -= value[s[i-1]-'A'];
                }
            }
            result += value[s[i-1]-'A'];
        }
    }
    
    return result;
}

