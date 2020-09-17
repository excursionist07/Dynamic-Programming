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

// o(n*n) && o(n) --> expanding around the center

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
    
     int maxx1=0,maxx2=0,idx1=-1,idx2=-1;
     for(int i=0;i<n;i++)
     {
      if(2*d1[i]-1>maxx1)
      {
       maxx1=2*d1[i]-1;
       idx1=i;
      }
     }
        
     for(int i=0;i<n;i++)
     {
      if(2*d2[i]>maxx2)
      {
       maxx2=2*d2[i];
       idx2=i;
      }
     }
     if(maxx1>maxx2)
         return s.substr(idx1-maxx1/2,maxx1/2)+s[idx1]+s.substr(idx1+1,maxx1/2);
     else
         return s.substr(idx2-maxx2/2,maxx2/2)+s.substr(idx2,maxx2/2);
     
    }
};


