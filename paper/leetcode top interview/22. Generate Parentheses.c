

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void generate(char **str, int *cnt, char *tmp, int n, int left, int right)
{
    char stack[100], index=-1;
    int i;
    
    if(left > n || right > n){
        return;
    }
    else
    {
        if(left == n && right == n)
        {
            tmp[2*n]='\0';
            index++;
            stack[index]=tmp[0];
            for(i=1; i<2*n; ++i)
            {
                if(index > -1 && stack[index] == '(' && tmp[i] == ')'){
                    index--;
                }
                else
                {
                    index++;
                    stack[index]=tmp[i];
                }
            }
            if(index == -1)
            {
                str[*cnt]=(char*)malloc(sizeof(char)*(2*n+1));
                strcpy(str[*cnt], tmp);
                (*cnt)++;
            }
        }
        else
        {
            tmp[left+right]='(';
            generate(str, cnt, tmp, n, left+1, right);
            tmp[left+right]=')';
            generate(str, cnt, tmp, n, left, right+1);
        }
    }
}

char ** generateParenthesis(int n, int* returnSize)
{
    char **str=NULL, *tmp=NULL;
    
    *returnSize=0;
    str=(char**)malloc(sizeof(char*)*(1024*100));
    tmp=(char*)malloc(sizeof(char)*(2*n+1));
    generate(str, returnSize, tmp, n, 0, 0);
    free(tmp);
    
    return str;
}

