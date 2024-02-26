// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=0;
        int e=n;
        while(s<=e){
             int mid= s+(e-s)/2;
        if(isBadVersion(mid)==1){
            e=mid-1;
        }
        else{
            s=mid+1;
        }

        }
        return e+1;
        
    }
};