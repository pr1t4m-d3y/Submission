class Solution {
public:
    long long int mySqrt(int x) {      
        long long int start=0,end=x,mid,sq;
        while (start<=end){
            mid=start+(end-start)/2;
            if(mid*mid==x)
            return mid;
            else if(mid*mid>x)
            end=mid-1;
            else{
                sq=mid;
                start=mid+1;
            }
        }
        return sq;

    }
};