class Solution {
	public:
		int guessNumber(int n) {
			long l=1;
			long h=n;
			long mid;
            while(l <= h) {
                mid= (l+h)/2;
                if(guess(mid)==1) {
                    l=mid+1;
                    }
                else if(guess(mid)==-1) {
                    h=mid-1;
                }
                else {
                    return mid;
                }
            }
		return l;
	}
};