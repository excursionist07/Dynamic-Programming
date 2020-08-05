// UGLY NUMBER I

class Solution {
public:
    bool isUgly(int num)
    {
     if(num==1 || num==2 || num==3 || num==5)
         return true;
     while(num && num%2==0)
         num/=2;
     while(num && num%3==0)
         num/=3;
     while(num && num%5==0)
         num/=5;
     return (num==1);
    }
};

// UGLY NUMBER II

class Solution {
public:
    int nthUglyNumber(int n) 
    {
     if(n==1)
         return 1;
     int dp[n];
     dp[0]=1;
     int aa=2,bb=3,cc=5,i2=0,i3=0,i5=0;
     for(int i=1;i<n;i++)
     {
      int minn=min(aa,min(bb,cc));
      dp[i]=minn;
      if(minn==aa)
      {
       i2++;
       aa=dp[i2]*2;
      }
      if(minn==bb)
      {
       i3++;
       bb=dp[i3]*3;
      }
      if(minn==cc)
      {
       i5++;
       cc=dp[i5]*5;
      }
       
      
     }
     return dp[n-1];
     
    }
};

/*
(1) 1×2, 2×2, 3×2, 4×2, 5×2, …
(2) 1×3, 2×3, 3×3, 4×3, 5×3, …
(3) 1×5, 2×5, 3×5, 4×5, 5×5, …
*/
