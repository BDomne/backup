

char * getPermutation(int n, int k)
{
    int fact[]={0, 
                1, 
                1*2, 
                1*2*3, 
                1*2*3*4, 
                1*2*3*4*5, 
                1*2*3*4*5*6, 
                1*2*3*4*5*6*7, 
                1*2*3*4*5*6*7*8, 
                1*2*3*4*5*6*7*8*9};
    int i, j, m;
    char *result, *label;
    
    result=(char*)malloc(sizeof(char)*(n+1));
    label=(char*)malloc(sizeof(char)*n);
    memset(result, 0, sizeof(char)*(n+1));
    memset(label, 0, sizeof(char)*n);
    
    for(i=n-1; i>0; --i)
    {
        m=0;
        while(1)
        {
            if(fact[i]*m < k && fact[i]*(m+1) >= k)
            {
                k -= fact[i]*m;
                for(j=0; j<n; ++j)
                {
                    if(label[j] == 0){
                        m--;
                    }
                    if(m == -1)
                    {
                        sprintf(result+n-1-i, "%c", j+1+'0');
                        label[j]=1;
                        break;
                    }
                }
                break;
            }
            m++;
        }
    }
    for(i=0; i<n; ++i)
    {
        if(label[i] == 0)
        {
            sprintf(result+n-1, "%c", i+1+'0');
            break;
        }
    }
    free(label);
    
    return result;
}

