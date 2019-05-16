

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int *result, i, c=1;
    
    *returnSize=digitsSize;
    result=(int*)malloc(sizeof(int)*(digitsSize+1));
    for(i=digitsSize-1; i>-1; --i)
    {
        result[i+1]=(digits[i]+c)%10;
        c=(digits[i]+c)/10;
    }
    if(c == 1)
    {
        result[0]=1;
        *returnSize=digitsSize+1;
        return result;
    }
    
    return result+1;
}

