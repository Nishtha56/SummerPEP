class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        unordered_map<int, int>map1,map2;
        vector<int>x1,x2;
        set<int> time;
        
        for(auto i : series1){
            map1[i[0]]=i[1];
            time.insert(i[0]);
            x1.push_back(i[0]);
        }
        for(auto i : series2){
            map2[i[0]]=i[1];
            x2.push_back(i[0]);
            time.insert(i[0]);
        }
        
        vector<vector<int>> res;
        
        for (int i : time) {
            int a;
            
            if (map1.find(i) != map1.end()) {
                a = map1[i];
            } else {
                auto l = lower_bound(x1.begin(), x1.end(), i);
                a = (l != x1.end()) ? map1[*l] : 0;
            }
            
            int b;
            if (map2.find(i) != map2.end()) {
                b = map2[i];
            } else {
                auto l = lower_bound(x2.begin(), x2.end(), i);
                b = (l != x2.end()) ? map2[*l] : 0;
            }
            
            res.push_back({i, a+ b});
        }
        
        return res;
    }
};