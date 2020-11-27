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

// 1048. Longest String Chain

class Solution {
public:
    static bool compare(string& s1,string& s2)
    {
     return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words)
    {
     sort(words.begin(),words.end(),compare);
     unordered_map<string,int>dp;
     int ans=1;
     for(auto xx:words)
     {
      for(int i=0;i<xx.length();i++)
      {
       dp[xx]=max(dp[xx],dp[xx.substr(0,i)+xx.substr(1+i)]+1); // just like word break for a particular word xx we are checking if any string(size of size(xx)-1) is present by masking each charcter of string xx one at a time
       ans=max(ans,dp[xx]);
      }
     }
     return ans;
    }
    
};
