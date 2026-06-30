class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        //Line sweep//diff array//partial sum
        //take line array in this take a will be 1 and b will -1 
        //in prefix array do prefix sum using line array
        //then check it
        int last=right;
        for(int i=0;i<ranges.size();i++){
            last=max(last, ranges[i][1]);
        }
        vector<int> line(last+2, 0);

        for(int i=0;i<ranges.size();i++){
            int a=ranges[i][0];
            int b=ranges[i][1];
            line[a]++;
            line[b+1]--;
        }

        vector<int> pre(last+2,0);
        pre[0]=line[0];

        for(int i=1;i<last+2;i++){
            int a=line[i]+pre[i-1];
            pre[i]=a;
        }

        for(int i=left;i<=right;i++){
            if(pre[i]==0){
                return false;
            }
        }
        return true;
    }
};