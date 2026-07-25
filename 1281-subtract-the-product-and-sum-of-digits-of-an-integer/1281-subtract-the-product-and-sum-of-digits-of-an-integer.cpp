class Solution {
public:
    int subtractProductAndSum(int n) {
        int temp=n;
        int p=1;
        int s=0;

        while(temp>0){
            int rem=temp%10;

            p=p*rem;
            s=s+rem;
            temp=temp/10;
        }

        return p-s;
    }
};