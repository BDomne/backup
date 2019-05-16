

int divide(int dividend, int divisor)
{
    int s=0, result=-1, tmp, sum=0;
    
    if(dividend < 0){
        s += -1;
    }
    if(divisor < 0){
        s += -1;
    }
    if(s == -2){
        s=0;
    }
    if(dividend > 0){
        dividend=-dividend;
    }
    if(divisor > 0){
        divisor=-divisor;
    }
    tmp=divisor;
    if(divisor == -1){
        sum=dividend;
    }
    else
    {
        while(dividend <= divisor)
        {
            if(dividend-divisor > divisor)
            {
                sum += result;
                dividend -= divisor;
                divisor=tmp;
                result=-1;
                continue;
            }
            result += result;
            divisor += divisor;
        }
    }
    if(sum == (int)pow(-2, 31) && s == 0){
        return (int)pow(2, 31);
    }
    if(s == 0){
        return -sum;
    }
    
    return sum;
}

