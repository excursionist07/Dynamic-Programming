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
