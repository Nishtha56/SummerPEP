class Solution {
public:
    int maxProduct(int n) {
        int maxi=0;
        int temp=n;

        while(n>0){
            int rem=n%10;
            temp=n/10;

            while(temp>0){
                int b=temp%10;
                maxi=max(maxi, rem*b);
                temp=temp/10;
            }

            n=n/10;
        }
        return maxi;
    }
};