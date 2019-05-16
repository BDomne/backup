

int strStr(char * haystack, char * needle)
{
    int index;
    char *p=haystack;
    
    if(strlen(needle) == 0){
        return 0;
    }
    while(1)
    {
        if((p=strchr(p, needle[0])) != NULL)
        {
            if(strlen(p) >= strlen(needle))
            {
                if(memcmp(p, needle, strlen(needle)) == 0){
                    return p-haystack;
                }
                p++;
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    
    return -1;
}

