class Solution {
public:
    unordered_map<string,bool>mp;
    /*bool doit(string s)
    {
     if(s.length()==0)
         return true;
     for(int i=1;i<=s.length();i++)
     {
      if(mp[s.substr(0,i)] && doit(s.substr(i,s.length()-i)))
          return true;
     }
     return false;
    }*/
    bool doit(string s)
    {
     int n=s.length();
     if(n==0)
         return true;
     bool dp[n+1];
     memset(dp,0,sizeof(dp));
     dp[0]=true;
     for(int len=1;len<=n;len++)
     {
      for(int i=0;i<len;i++)
      {
       if(dp[i] && mp[s.substr(i,len-i)])
       {
        dp[len]=true;
        break;
       }
      }
     }
     return dp[n];
     
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
     int n=s.length();
     mp.clear();
     if(n==0)
         return true;
     for(int i=0;i<wordDict.size();i++)
         mp[wordDict[i]]=1;
     return doit(s);
    }
};
