

double myPow(double x, int n)
{
    int s=0, c=0;
    double result=1, tmp=x, m=1;
    
    if(n == 0){
        return 1;
    }
    if(n == -2147483648)
    {
        s=-1;
        n=-(n+1);
        c=1;
    }
    else
    {
        if(n < 0)
        {
            s=-1;
            n=-n;
        }
    }
    
    while(1)
    {
        if(n <= 1){
            break;
        }
        if(n < 2*m)
        {
            result *= tmp;
            n -= m;
            tmp=x;
            m=1;
            continue;
        }
        tmp *= tmp;
        m *= 2;
    }
    
    if(n == 1){
        result *= x;
    }
    if(c == 1){
        result *= x;
    }
    if(s == -1){
        return 1/result;
    }
    
    return result;
}

