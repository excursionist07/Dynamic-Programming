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


