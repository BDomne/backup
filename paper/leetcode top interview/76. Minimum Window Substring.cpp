class Solution {
public:
    string minWindow(string s, string t)
    {
        string result = "";
        const char *begin = nullptr, *end = nullptr;
        int i, n = 0;
        vector<int> vec;
        set<char> st;
        multiset<char> mst;
        map<char, int> mp;

        for(i = 0; i < t.size(); ++i){
            st.insert(t[i]);
            mst.insert(t[i]);
        }
        for(auto iter = st.begin(); iter != st.end(); ++iter)
        {
            vec.push_back(0);
            mp.insert(make_pair(*iter, n++));
        }
        for(auto miter = mst.begin(); miter != mst.end(); ++miter){
            -- vec[mp[*miter]];
        }

        for(i = 0, begin = end = s.data(); i < s.size(); ++i, ++end)
        {
            auto iter = st.find(*end);
            if(iter != st.end())
            {
                ++ vec[mp[*end]];
                auto miter = mst.find(*end);
                if(miter != mst.end()){
                    mst.erase(miter);
                }
            }
            while(mst.empty())
            {
                iter = st.find(*begin);
                if(iter != st.end())
                {
                    if(-- vec[mp[*begin]] < 0)
                    {
                        mst.insert(*begin);
                        if(result.empty() || end - begin + 1 < result.size()){
                            result = s.substr(begin - s.data(), end - begin + 1);
                        }
                    }
                }
                ++ begin;
            }
        }

        return result;
    }
};