

char * multiply(char * num1, char * num2)
{
    char *result, *str;
    int n, i, j, k, index, a, c, tmp;
    
    n=strlen(num1)+1+strlen(num2)+1;
    result=(char*)malloc(sizeof(char)*n);
    memset(result, '0', sizeof(char)*(n-1));
    result[n-1]='\0';
    index=n-2;
    str=(char*)malloc(sizeof(char)*(strlen(num2)+1));
    
    if(strlen(num1) == 1 && num1[0] == '0' || strlen(num2) == 1 && num2[0] == '0'){
        return result+n-2;
    }
    
    for(i=strlen(num1)-1; i>=0; --i)
    {
        a=0;
        memset(str, '0', sizeof(char)*(strlen(num2)+1));
        for(j=strlen(num2)-1; j>=0; --j)
        {
            tmp=(num1[i]-'0')*(num2[j]-'0')+a;
            a=tmp/10;
            str[j+1]=tmp%10+'0';
        }
        str[j+1]=a+'0';
        c=0;
        for(k=index, j=strlen(num2); k>=0; --k, --j)
        {
            if(j>=0)
            {
                tmp=result[k]-'0'+str[j]-'0'+c;
                result[k]=tmp%10+'0';
                c=tmp/10;
            }
            else
            {
                tmp=result[k]-'0'+c;
                result[k]=tmp%10+'0';
                c=tmp/10;
            }
        }
        index--;
    }
    free(str);
    for(i=0; i<n-2; ++i){
        if(result[i] == '0'){
            continue;
        }
        else{
            break;
        }
    }
    
    return result+i;
}

