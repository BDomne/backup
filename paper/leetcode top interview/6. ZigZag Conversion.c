

char * convert(char * s, int numRows)
{
    char **array, *p=s, *result;
    int i, label=1;
    
    result=(char*)malloc(strlen(s)+1);
    memset(result, 0, strlen(s)+1);
    if(numRows == 1)
    {
        memcpy(result, s, strlen(s));
        return result;
    }
    
    array=(char**)malloc(sizeof(char*)*numRows);
    for(i=0; i<numRows; ++i)
    {
        array[i]=(char*)malloc(strlen(s)/(numRows-1)+2);
        memset(array[i], 0, strlen(s)/(numRows-1)+2);
    }
    
    while(*p != '\0')
    {
        if(label > 0)
        {
            for(i=0; i<numRows-1; ++i)
            {
                if(*p == '\0'){
                    break;
                }
                array[i][strlen(array[i])]=*p;
                p++;
            }
        }
        else
        {
            for(i=numRows-1; i>0; --i)
            {
                if(*p == '\0'){
                    break;
                }
                array[i][strlen(array[i])]=*p;
                p++;
            }
        }
        label = -label;
    }
    
    for(i=0; i<numRows; ++i)
    {
        sprintf(result+strlen(result), "%s", array[i]);
        free(array[i]);
    }
    free(array);
    
    return result;
}

