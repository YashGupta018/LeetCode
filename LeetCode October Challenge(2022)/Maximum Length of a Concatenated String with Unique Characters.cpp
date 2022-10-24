class Solution {
public:
    int m[26];
    int ans=0;
    void fun(vector<string>& v,int st,int n)
    {
        int res=0;
        for(int i=0;i<26;i++)
        {
            if(m[i]>1)return;
            if(m[i]==1)res++;
        }
        ans=max(ans,res);
        for(int i=st;i<n;i++)
        {
            for(char ch:v[i])m[ch-'a']++;
            fun(v,i+1,n);
            for(char ch:v[i])m[ch-'a']--;
        }
    }
    int maxLength(vector<string>& arr) {
        memset(m,0,sizeof(m));
        ans=0;
        fun(arr,0,arr.size());
        return ans;
    }
};