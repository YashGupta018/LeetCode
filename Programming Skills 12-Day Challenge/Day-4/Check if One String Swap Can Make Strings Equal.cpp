class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
            if(s1 == s2)
        return true;
    int count = 0;
    int pos1 = -1 , pos2 = -1; 
    for(int i = 0 ; i< s1.length() ; i++) {
        if(s1[i] != s2[i]) {   
            count++;
            if(count == 1)
            pos1 = i;
            else if(count == 2)
            pos2 = i;
            else if(count >= 3)
            return false;
        }
    }
    if(count == 1)
        return false;
    cout<<pos1<<" "<<pos2<<endl;
    swap(s1[pos1] , s1[pos2]);
    if(s1 == s2)
        return true;
    return false;
    }
};