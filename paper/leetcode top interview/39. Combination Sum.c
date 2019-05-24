

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void combination(int *nums, int n, int target, int **result, int *cnt, int **colsize, int *tmp, int m)
{
    int i, j;
    
    for(i=0; i<n; ++i)
    {
        tmp[m-1]=nums[i];
        if(target-nums[i] > 0){
            combination(nums, n, target-nums[i], result, cnt, colsize, tmp, m+1);
        }
        else
        {
            if(target-nums[i] == 0)
            {
                for(j=0; j<m-1; ++j)
                {
                    if(tmp[j] > tmp[j+1]){
                        return;
                    }
                }
                result[*cnt]=(int*)malloc(sizeof(int)*m);
                memcpy(result[*cnt], tmp, sizeof(int)*m);
                (*colsize)[*cnt]=m;
                (*cnt)++;
            }
            break;
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    int **result=NULL, *tmp=NULL;
    
    qsort(candidates, candidatesSize, sizeof(candidates[0]), cmp);
    *returnSize=0;
    *returnColumnSizes=(int*)malloc(sizeof(int)*1024*100);
    result=(int**)malloc(sizeof(int*)*1024*100);
    tmp=(int*)malloc(sizeof(int)*1024*100);
    
    combination(candidates, candidatesSize, target, result, returnSize, returnColumnSizes, tmp, 1);
    *returnColumnSizes=(int*)realloc(*returnColumnSizes, sizeof(int)*(*returnSize));
    result=(int**)realloc(result, sizeof(int*)*(*returnSize));
    free(tmp);
    
    return result;
}

