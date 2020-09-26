

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void findSubSubstring(char * s, char ** words, int wordsSize, char *flag)
{
    int i;

    if(wordsSize < 2)
    {
        if(strstr(s, words[0]) - s == 0){
            *flag = 1;
        }
    }
    else
    {
        for(i = 0; i < wordsSize; ++i)
        {
            if(*flag == 1){
                break;
            }
            if(strstr(s, words[i]) - s == 0)
            {
                if(i != wordsSize - 1){
                    strcpy(words[i], words[wordsSize - 1]);
                }
                findSubSubstring(s + strlen(words[0]), words, wordsSize - 1, flag);
            }
        }
    }
}

int preCheck(char * s, char ** words, int wordsSize)
{
    int i, j, m, result = 0;
    char *p = NULL, **flag = NULL;

    m = strlen(words[0]);
    flag = (char **)malloc(sizeof(char *) * m);
    for(i = 0; i < m; ++i){
        flag[i] = (char *)malloc(sizeof(char) * wordsSize);
    }

    for(i = 0; i < m; ++i)
    {
        for(j = 0; j < wordsSize; ++j)
        {
            flag[i][j] = 0;
            p = s + i;
            while(strlen(p) >= m)
            {
                if(strstr(p, words[j]) - p == 0)
                {
                    flag[i][j] = 1;
                    break;
                }
                p += m;
            }
            if(flag[i][j] == 0){
                break;
            }
        }
        if(j == wordsSize)
        {
            result = 1;
            break;
        }
    }

    for(i = 0; i < m; ++i){
        free(flag[i]);
    }
    free(flag);

    return result;
}

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize)
{
    char *label = NULL, **temp = NULL, flag;
    int *result = NULL, i, j, n;

    *returnSize = 0;
    n = strlen(s) - strlen(words[0]) * wordsSize + 1;
    if(n > 0)
    {
        if(preCheck(s, words, wordsSize) == 0){
            return result;
        }
        label = (char *)malloc(sizeof(char) * n);
        memset(label, 0, sizeof(char) * n);
        temp = (char **)malloc(sizeof(char *) * wordsSize);
        for(i = 0; i < wordsSize; ++i){
            temp[i] = (char *)malloc(sizeof(char) * (strlen(words[0]) + 1));
        }
        for(i = 0; i < n; ++i)
        {
            flag = 0;
            for(j = 0; j < wordsSize; ++j){
                strcpy(temp[j], words[j]);
            }
            findSubSubstring(s + i, temp, wordsSize, &flag);
            if(flag == 1)
            {
                label[i] = 1;
                ++(*returnSize);
            }
        }
        for(i = 0; i < wordsSize; ++i){
            free(temp[i]);
        }
        free(temp);
    }

    if(*returnSize > 0)
    {
        result = (int *)malloc(sizeof(int) * (*returnSize));
        for(i = 0, j = 0; i < n; ++i)
        {
            if(label[i] == 1){
                result[j++] = i;
            }
        }
    }
    if(label != NULL){
        free(label);
    }

    return result;
}
