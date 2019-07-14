

int removeElement(int* nums, int numsSize, int val)
{
    int start=0, end=numsSize-1;
    
    if(numsSize == 0){
        return 0;
    }
    
    while(start < end)
    {
        while(start < end)
        {
            if(nums[start] == val)
            {
                while(start < end)
                {
                    if(nums[end] != val)
                    {
                        nums[start]=nums[end];
                        end--;
                        break;
                    }
                    else{
                        end--;
                    }
                }
                break;
            }
            else{
                start++;
            }
        }
    }
    if(nums[start] == val){
        return start;
    }
    
    return start+1;
}

