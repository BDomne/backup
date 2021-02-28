class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> result;

        if(intervals.size() == 0){
            result.push_back(newInterval);
        }
        else
        {
            int begin = newInterval[0], end = newInterval[1], i, j, val;
            vector<int> vec;

            if(intervals[0][0] < begin){
                begin = intervals[0][0];
            }
            if(intervals[intervals.size() - 1][1] > end){
                end =intervals[intervals.size() - 1][1];
            }
            int n = (end - begin + 1) * 2;
            char *arr = new char[n];
            memset(arr, 0, sizeof(char) * n);
            val = begin;

            for(begin = newInterval[0] - val, end = newInterval[1] - val, 
                i = begin * 2; i <= end * 2; ++i){
                    arr[i] = 1;
            }
            for(j = 0; j < intervals.size(); ++j)
            {
                for(begin = intervals[j][0] - val, end = intervals[j][1] - val, 
                    i = begin * 2; i <= end * 2; ++i){
                        arr[i] = 1;
                }
            }

            for(i = 0; i < n - 1; ++i)
            {
                if(arr[i] == 0){
                    continue;
                }
                begin = i / 2 + val;
                while(arr[i + 1] == 1){
                    ++ i;
                }
                end = i / 2 + val;
                vec.clear();
                vec.push_back(begin);
                vec.push_back(end);
                result.push_back(vec);
            }

            delete[] arr;
        }
        
        return result;
    }
};