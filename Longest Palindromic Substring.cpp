// 5. Longest Palindromic Substring

// o(n*n) && o(n*n)

class Solution {
public:
    string lps(string str)
    {
     int n=str.length();
     bool isPal[n][n];
     memset(isPal,0,sizeof(isPal));
     int maxx=1,start=0;
     for(int i=0;i<n;i++)
       isPal[i][i]=1;
      
     
     for(int i=0;i<n-1;i++)
     {
      if(str[i]==str[i+1])
      {
       isPal[i][i+1]=1;
       start=i;
       maxx=2;
      }
     }
     for(int len=3;len<=n;len++)
     {
      for(int i=0;i<n-len+1;i++)
      {
       int j=i+len-1;
       if(isPal[i+1][j-1] && str[i]==str[j])
       {
        isPal[i][j]=1;
        if(len>maxx)
        {
         maxx=len;
         start=i;
        }
       }
       
      }
     }
     return str.substr(start,maxx);
    }
    string longestPalindrome(string s)
    {
     int n=s.length();
     if(n==0)
         return "";
    
     return lps(s);
    }
};

// o(n*n) && o(1) --> expanding around the center

class Solution {
public:
    string longestPalindrome(string s) 
    {
     int n=s.length();
     if(n<2)
         return s;
     int len=1,start=0;
     for(int i=1;i<n;i++)
     {
      // odd size palindrome
      int lo=i-1,hi=i+1;
      while(lo>=0 && hi<n && s[lo]==s[hi])
      {
       if(hi-lo+1>len)
         len=hi-lo+1,start=lo;   
       lo--;
       hi++;
       
      }
      // even size palindrome
      lo=i-1;hi=i;
      while(lo>=0 && hi<n && s[lo]==s[hi])
      {
       if(hi-lo+1>len)
           len=hi-lo+1,start=lo;
       lo--;
       hi++;
       
      }
     
     }
     return s.substr(start,len);
        
    }
};

// o(n*n) && o(n) --> expanding around the center (trivial algo used in manachers)

class Solution {
public:
    string longestPalindrome(string s) 
    {
     int n=s.length();
     if(n==0)
         return "";
     vector<int>d1(n),d2(n);
     // expanding around the center
        
     for(int i=0;i<n;i++)
     {
      // odd length
      d1[i]=1;
      while(i-d1[i]>=0 && i+d1[i]<n && s[i-d1[i]]==s[i+d1[i]])
          d1[i]++;
      
      // even length
      d2[i]=0;
      while(i-d2[i]-1>=0 && i+d2[i]<n && s[i-d2[i]-1]==s[i+d2[i]])
          d2[i]++;
      
     }
    
     int l=-1,r=-1;
     int len=0;
     for(int i=0;i<n;i++)
     {
      if(2*d1[i]-1>len)
          len=2*d1[i]-1,l=i-(d1[i]-1),r=i+(d1[i]-1);
      if(2*d2[i]>len)
          len=2*d2[i],l=i-d2[i],r=i+d2[i]-1;
     }
     return s.substr(l,len);
     
    }
};

// o(n) && o(n)--> Manachers's algo

class Solution {
public:
    string longestPalindrome(string s) 
    {
     int n=s.length();
     if(n<2)
         return s;
     vector<int>d1(n),d2(n);
     int l=0,r=-1;
     
     // for odd size
     for(int i=0;i<n;i++)
     {
      if(r>=i)
          d1[i]=min(r-i+1,d1[l+r-i]); // We'll try to extract some information from the already calculated values in d1[]. So, let's find the "mirror" position of i in the sub-palindrome (l,r), i.e. we'll get the position j=l+(r−i)
      else
          d1[i]=1;
      // trivial algo
      while(i-d1[i]>=0 && 1+d1[i]<n && s[i-d1[i]]==s[i+d1[i]])
          d1[i]++;
      if(i+d1[i]-1>r)
      {
       r=i+d1[i]-1;
       l=i-(d1[i]-1);
      }
     }
        
     // for even size
     l=0;r=-1;
     for(int i=0;i<n;i++)
     {
      if(r>=i)
          d2[i]=min(r-i+1,d2[l+r-i+1]);
      else
          d2[i]=0;
      // // trivial algo
      while(i-d2[i]-1>=0 && i+d2[i]<n && s[i-d2[i]-1]==s[i+d2[i]])
          d2[i]++;
      if(i+d2[i]-1>r)
      {
       r=i+d2[i]-1;
       l=i-d2[i];
      }
      
     }
     l=-1;r=-1;
     int len=0;
     for(int i=0;i<n;i++)
     {
      if(2*d1[i]-1>len) // odd length
          len=2*d1[i]-1,l=i-(d1[i]-1),r=i+(d1[i]-1);
      if(2*d2[i]>len) // even length
          len=2*d2[i],l=i-d2[i],r=i+d2[i]-1;
     }
     return s.substr(l,len);
        
    }
};

// 131. Palindrome Partitioning

class Solution {
public:
    bool IsPal(string s,int start,int end)
    {
     while(start<=end)
     {
      if(s[start++]!=s[end--])
          return false;
     }
     return true;
    }
    void doit(string s,vector<string>temp,vector<vector<string>>&ans,int idx)
    {
     if(idx==s.length())
     {
      ans.push_back(temp);
      return;
     }
     for(int i=idx;i<s.length();i++)
     {
      if(IsPal(s,idx,i))
      {
       temp.push_back(s.substr(idx,i-idx+1));
       doit(s,temp,ans,i+1);
       temp.pop_back();
      }
     }
    }
    vector<vector<string>> partition(string s) 
    {
     vector<vector<string>>ans;
     int n=s.length();
     if(n==0)
         return ans;
     vector<string>temp;
     doit(s,temp,ans,0);
     return ans;
    }
};

// 132.Palindrome Partioning(min cut)

class Solution {
public:
    int doit(string str)
    {
     int n=str.length();
     bool isPal[n][n];
     //int dp[n][n];
     memset(isPal,0,sizeof(isPal));
    /* for(int i=0;i<n;i++)//O(n^3)
     {
      dp[i][i]=0;
      isPal[i][i]=1;
     }
    for(int i=0;i<n-1;i++)
     {
      if(str[i]==str[i+1])
      {
       isPal[i][i+1]=1;
       dp[i][i+1]=0;
      }
      else
      {
       isPal[i][i+1]=0;
       dp[i][i+1]=1;
      }
     }
     for(int len=3;len<=n;len++)
     {
      for(int i=0;i<n-len+1;i++)
      {
       int j=i+len-1;
       isPal[i][j]=(isPal[i+1][j-1] && str[i]==str[j]);
       if(isPal[i][j])
           dp[i][j]=0;
       else
       {
         dp[i][j]=INT_MAX;
         for(int k=i;k<=j-1;k++)
             dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
       }
       
      }
     }
     return dp[0][n-1];*/
     int dp[n];
     for(int i=0;i<n;i++)
         isPal[i][i]=1;
     for(int len=2;len<=n;len++)
     {
      for(int i=0;i<n-len+1;i++)
      {
       int j=i+len-1;
       if(len==2)
           isPal[i][j]=(str[i]==str[j]);
       else
           isPal[i][j]=(isPal[i+1][j-1] && str[i]==str[j]);
      }
     }
     for(int i=0;i<n;i++)
     {
      if(isPal[0][i])
           dp[i]=0;
      else
       {
        dp[i]=INT_MAX;
        for(int j=0;j<i;j++)
        {
         if(isPal[j+1][i])
             dp[i]=min(dp[i],1+dp[j]);
        }
       }
      
     }
     return dp[n-1];
     
    }
    int minCut(string s)
    {
     int n=s.length();
     if(n<=1)
         return 0;
     return doit(s);
    }
};


