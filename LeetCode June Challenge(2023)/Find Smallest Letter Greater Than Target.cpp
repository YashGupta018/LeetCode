class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters[0]>target || letters[letters.size()-1]<=target) {
            return letters[0];
        }
        int l=0,h=letters.size();
        while(l<h) {
            int mid=l+(h-l)/2;
            if(letters[mid]>target) {
                h=mid;
            }
            else {
                l=mid+1;
            }
        }
    return letters[l%letters.size()];
    }
};