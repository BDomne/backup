

int reverse(int x)
{
    char str[11];
    char max[]={'2','1','4','7','4','8','3','6','4','7'};
    char min[]={'2','1','4','7','4','8','3','6','4','8'};
    int n=0, tmp=x, label=0;
    
    memset(str, 0, 11);
    if(x < 0)
    {
        if(x == -2147483648){
            x++;
        }
        tmp=-x;
        label=1;
    }
    while(1)
    {
        if(tmp/10 != 0)
        {
            str[n]='0'+tmp%10;
            n++;
            tmp=tmp/10;
        }
        else{
            break;
        }
    }
    str[n]='0'+tmp;
    n++;
    if(n < 10)
    {
        tmp=atoi(str);
        if(label == 1){
            tmp=-tmp;
        }
    }
    else
    {
        if(label == 0)
        {
            if(strcmp(str, max) > 0){
                return 0;
            }
            else{
                tmp=atoi(str);
            }
        }
        else
        {
           if(strcmp(str, min) > 0){
                return 0;
            }
            else{
                tmp=-atoi(str);
            } 
        }
    }
    
    return tmp;
}

