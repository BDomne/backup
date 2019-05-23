

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct _node{
    char s[128];
    int index;
}node, *pNode;

int cmp1(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

int cmp2(const void *a, const void *b)
{
    return strcmp((*(pNode)a).s, (*(pNode)b).s);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    char ***result;
    pNode array;
    int i, j, index1=0, index2, n=0;
    
    *returnSize=0;
    *returnColumnSizes=(int*)malloc(sizeof(int)*1024*100);
    array=(pNode)malloc(sizeof(node)*strsSize);
    for(i=0; i<strsSize; ++i)
    {
        strcpy(array[i].s, strs[i]);
        array[i].index=i;
        qsort(array[i].s, strlen(array[i].s), sizeof(char), cmp1);
    }
    qsort(array, strsSize, sizeof(node), cmp2);
    
    for(i=1; i<strsSize; ++i)
    {
        index2=i;
        if(strcmp(array[i].s, array[i-1].s) != 0)
        {
            (*returnColumnSizes)[*returnSize]=index2-index1;
            (*returnSize)++;
            index1=index2;
        }
    }
    (*returnColumnSizes)[*returnSize]=i-index1;
    (*returnSize)++;
    
    *returnColumnSizes=(int*)realloc(*returnColumnSizes, sizeof(int)*(*returnSize));
    result=(char***)malloc(sizeof(char**)*(*returnSize));
    for(i=0; i<*returnSize; ++i)
    {
        result[i]=(char**)malloc(sizeof(char*)*(*returnColumnSizes)[i]);
        for(j=0; j<(*returnColumnSizes)[i]; ++j)
        {
            result[i][j]=(char*)malloc(sizeof(char)*(strlen(array[n].s)+1));
            strcpy(result[i][j], strs[array[n].index]);
            n++;
        }
    }
    free(array);
    
    return result;
}

