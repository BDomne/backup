

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int removeDuplicates(int* nums, int numsSize)
{
    int i, label;
    
    if(numsSize < 2){
        return numsSize;
    }
    label=nums[0];
    for(i=1; i<numsSize; ++i)
    {
        if(nums[i] == label){
            nums[i]=nums[numsSize-1];
        }
        else{
            label=nums[i];
        }
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    for(i=1; i<numsSize; ++i)
    {
        if(nums[i] == nums[i-1]){
            break;
        }
    }
    
    return i;
}

