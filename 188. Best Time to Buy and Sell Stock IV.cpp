class Solution {
public:
    int doit(vector<int>& prices,int k)
    {
     int n=prices.size();
     int dp[k+1][n];
     //O(days*days*k)
     /*for(int i=0;i<=k;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(i==0 || j==0)
           dp[i][j]=0;
       else
       {
        int res=INT_MIN;
        for(int d=0;d<j;d++)
            res=max(res,prices[j]-prices[d]+dp[i-1][d]);
        dp[i][j]=max(res,dp[i][j-1]);
       }
      }
     }*/
     //O(days*k)
     for(int i=0;i<=k;i++)
         dp[i][0]=0;
     for(int i=1;i<n;i++)
         dp[0][i]=0;
     for(int i=1;i<=k;i++)
     {
      int prev=INT_MIN;
      for(int j=1;j<n;j++)
      {
       prev=max(prev,dp[i-1][j-1]-prices[j-1]);
       dp[i][j]=max(dp[i][j-1],prices[j]+prev);
      }
     }
     return dp[k][n-1];
    }
    int maxProfit(int k, vector<int>& prices) 
    {
     int n=prices.size();
     if(n<=1 || k==0)
         return 0;
     if(2*k>n)
     {
      int res=0;
      for(int i=1;i<n;i++)
          res+=max(0,prices[i]-prices[i-1]);
      return res;
          
     }
     cout<<n;
     return doit(prices,k);
    }
};
