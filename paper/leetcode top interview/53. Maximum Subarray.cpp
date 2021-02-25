class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int end = 0, _end = 0, sum = nums[0], i, j;
        vector<int> vec;

        for(i = 1, vec.push_back(nums[0]); i < nums.size(); ++i)
        {
            vec.push_back(0);
            for(j = vec.size() - 1; j >= end; --j)
            {
                vec[j] += nums[i];
                if(vec[j] > sum)
                {
                    sum = vec[j];
                    _end = vec.size() - 1;
                }
            }
            if(end != _end)
            {
                end = _end;
                vec[end] = sum;
            }
        }

        return sum;
    }
};