class Solution {
public:
    int doit(vector<int>& prices,int k)
    {
     int n=prices.size();
     int dp[k+1][n];
     //O(days*days*k)
     for(int i=0;i<=k;i++)
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
        dp[i][j]=max(res,dp[i][j-1]);//dp[i][j-1]--not transacting on jth day
       }
      }
     }
     return dp[k][n-1];
    }
    int maxProfit(int k, vector<int>& prices) 
    {
     int n=prices.size();
     if(n<=1 || k==0)
         return 0;
     k=min(k,n/2);
     return doit(prices,k);
    }
};
