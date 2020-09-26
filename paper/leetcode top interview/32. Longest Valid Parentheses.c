
int longestValidParentheses(char * s)
{
    int *stack = NULL, index = 0, n, i, result = 0;
    char *p = NULL, *temp = NULL;

    n = strlen(s);
    if(n < 2){
        return result;
    }

    stack = (int *)malloc(sizeof(int) * (n + 1));
    temp = (char *)malloc(sizeof(char) * (n + 1));
    strcpy(temp, s);
    p = temp;
    while(*p != '\0')
    {
        if(index > 0 && temp[stack[index - 1]] == '(' && *p == ')'){
            --index;
        }
        else{
            stack[index++] = p - temp;
        }
        ++p;
    }

    for(i = 0; i < index; ++i){
        temp[stack[i]] = '\0';
    }
    p = temp;
    while(p - temp < n)
    {
        if(*p == '\0'){
            ++p;
        }
        else
        {
            if(strlen(p) > result){
                result = strlen(p);
            }
            p += strlen(p);
        }
    }
    free(stack);
    free(temp);

    return result;
}
