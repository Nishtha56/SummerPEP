/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearchAsc(int l, int r, MountainArray &mountainArr, int target){
        while(l<=r){
            int mid=l+(r-l)/2;

            if(mountainArr.get(mid)==target){
                return mid;
            }

            if(mountainArr.get(mid)<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }

    int binarySearchDsc(int l, int r, MountainArray &mountainArr, int target){ //logn
        while(l<=r){
            int mid=l+(r-l)/2;

            if(mountainArr.get(mid)==target){
                return mid;
            }

            if(mountainArr.get(mid)<target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        if(n<3) return -1;

        //peak element
        int l=0;
        int r=mountainArr.length()-1;
        while(l<r){
            int mid=l+(r-l)/2;

            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }

        int peak=l;
        int a=binarySearchAsc(0, peak, mountainArr, target); //Seach in asc means increasing side logn
        int b=binarySearchDsc(peak+1, n-1, mountainArr, target);//search in decreasing size (logn)

        if(a!=-1){
            return a;
        }
        return b;
    }
};