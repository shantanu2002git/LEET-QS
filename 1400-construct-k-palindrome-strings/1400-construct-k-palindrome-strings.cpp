class Solution
{
public:
    bool canConstruct(string s, int k)
    {
       map<char,int>mp;
        int n = s.size();
        if(n<k){
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            cout<<s[i]<< " ";
        }
        cout<<"ki";
        int odd=0;
        for(auto it : mp){
            cout<<it.first<<" "<<it.second<<" "<<endl;
            odd+=(it.second%2);
        }
        if(odd>k){
            return 0;
        }
        return 1;
    }
};
