class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s = 0, l = mountainArr.length() - 1, mid;
		
        while(s < l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) s = mid + 1;
            else l = mid;
        }
        
        int peak = s;
        
        s = 0; l = peak;
        bool flagL = false, flagR = false;
        while(s <= l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) == target){
                flagL = true;
                break;
            }
            else if(mountainArr.get(mid) < target) s = mid + 1;
            else l = mid - 1;
        }
        if(flagL) return mid;
        
        s = peak + 1; l = mountainArr.length() - 1;
        while(s <= l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) == target){
                flagR = true;
                break;
            }
            else if(mountainArr.get(mid) > target) s = mid + 1;
            else l = mid - 1;
        }
        if(flagR) return mid;
        
        return -1;
    }
};