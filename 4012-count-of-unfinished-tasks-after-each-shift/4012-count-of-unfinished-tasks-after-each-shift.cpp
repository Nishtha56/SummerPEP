class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        int m=shifts.size();

        vector<int> ans;

        vector<long long> pre(n, 0);
        pre[0]=tasks[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+tasks[i];
        }

        long long sum=0;

        for(int i : shifts){
            int tot=i;

            long long need=pre[n-1]-sum;

            if(tot>=need){
                ans.push_back(0);
                sum=0;
                
            }
            else{
                sum=sum+tot;

                int r=upper_bound(pre.begin(), pre.end(), sum)-pre.begin();
                ans.push_back(n-r);
            }
            
        }
        return ans;

        
    }
};