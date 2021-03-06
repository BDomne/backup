

int search(int* nums, int numsSize, int target)
{
    int start=0, end=numsSize-1, mid;
    
    while(start <= end)
    {
        mid=(start+end)/2;
        if(nums[mid] == target){
            return mid;
        }
        else
        {
            if(nums[mid] > target && nums[mid] < nums[end] ||
              nums[start] < target && nums[mid] > target ||
              nums[start] == target ||
              nums[mid] < nums[end] && nums[end] < target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
    }
    
    return -1;
}

