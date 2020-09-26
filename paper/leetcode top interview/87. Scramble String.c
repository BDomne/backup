

#define MAXLEN 30

int preCheck(char *s1, char *s2)
{
    int letters[26] = {0}, i;

    for(i = 0; i < strlen(s1); ++i)
    {
        ++letters[s1[i] - 'a'];
        --letters[s2[i] - 'a'];
    }
    for(i = 0; i < 26; ++i)
    {
        if(letters[i] != 0){
            return 0;
        }
    }

    return 1;
}

void searchScramble(char *s, char *s2, int m, int *flag)
{
    char *p = NULL, *q = s, temp[2][MAXLEN + 2] = {{0}, {0}}, temp2[MAXLEN * 2] = {0};
    int i, j, n = 0;

    for(i = 0; i <= m; ++i)
    {
        if(preCheck(q, s2 + n) == 0){
            return;
        }
        if(strlen(q) > 1)
        {
            for(j = 1; j < strlen(q); ++j)
            {
                if(q[j - 1] != q[j]){
                    break;
                }
            }
            if(j < strlen(q)){
                p = q;
            }
        }
        strcat(temp2, q);
        n += strlen(q); 
        q += strlen(q) + 1;
    }
    if(strcmp(temp2, s2) == 0)
    {
        *flag = 1;
        return;
    }
    
    if(p != NULL)
    {
        memcpy(temp2, s, sizeof(char) * 2 * strlen(s2));
        for(n = strlen(p), i = 1; i < n; ++i)
        {
            memcpy(temp[0], p, sizeof(char) * i);
            temp[0][i] = '\0';
            memcpy(temp[0] + i + 1, p + i, sizeof(char) * (n - i));

            memcpy(temp[1], p + i, sizeof(char) * (n - i));
            temp[1][n - i] = '\0';
            memcpy(temp[1] + n - i + 1, p, sizeof(char) * i);

            for(j = 0; j < 2; ++j)
            {
                memcpy(s, temp2, sizeof(char) * (p - s));
                memcpy(p, temp[j], sizeof(char) * (n + 1));
                memcpy(p + n + 1, temp2 + (p + n - s), sizeof(char) * (strlen(s2) + m - (p + n - s)));
                searchScramble(s, s2, m + 1, flag);
                if(*flag == 1){
                    return;
                }
                memcpy(s, temp2, sizeof(char) * 2 * strlen(s2));
            }
        }
    }
}

bool isScramble(char *s1, char *s2)
{
    char s[MAXLEN * 2] = {0};
    int flag = 0;

    if(preCheck(s1, s2) == 1)
    {
        strcpy(s, s1);
        searchScramble(s, s2, 0, &flag);
    }

    if(flag == 1){
        return true;
    }
    return false;
}
