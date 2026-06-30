class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        //diff array
        vector<vector<long long>> ans;
        map<long long, long long> diff;

        for(auto& i: segments){
            int first=i[0];
            int last=i[1];
            int color=i[2];

            diff[first]=diff[first]+color;
            diff[last]=diff[last]-color;


        }

        long long sum=0;
        long long st=-1;

        for (auto &it : diff) {
            long long curr=it.first;

            if (st!=-1 && sum>0) {
                ans.push_back({st,curr, sum});
            }

            sum+=it.second;
            st=curr;
        }
        return ans;


    }
};