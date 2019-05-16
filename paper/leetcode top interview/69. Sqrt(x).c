

int mySqrt(int x)
{
    long start=1, end=x, mid;
    int result;
    
    while(1)
    {
        mid=(start+end)/2;
        if(mid*mid <= x && (mid+1)*(mid+1) >= x)
        {
            if((mid+1)*(mid+1) == x){
                result=mid+1;
            }
            else{
                result=mid;
            }
            break;
        }
        else
        {
            if(mid*mid > x){
                end=mid;
            }
            else{
                start=mid;
            }
        }
    }
    
    return result;
}

