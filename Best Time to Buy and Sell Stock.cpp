// 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int n=prices.size();
      int minn=INT_MAX,maxx=0;
      for(int i=0;i<n;i++)
      {
       if(prices[i]<minn)
           minn=prices[i];
       else if(prices[i]-minn>maxx)
           maxx=prices[i]-minn;
      }
        return maxx;
    }
};

// 122. Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
     int n=prices.size();
     if(n<=1)return 0;
     int ans=0;
     for(int i=1;i<n;i++)
         ans+=max(0,prices[i]-prices[i-1]);
     return ans;
     }
};

// 123. Best Time to Buy and Sell Stock III

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
    int maxProfit(vector<int>& prices)
    {
     int n=prices.size();
     if(n<=1)
         return 0;

     return doit(prices,2);
    }
};

//  188. Best Time to Buy and Sell Stock IV

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
     if(k>=n-1)
     {
      int res=0;
      for(int i=1;i<n;i++)
          res+=max(0,prices[i]-prices[i-1]);
      return res;
          
     }
     
     return doit(prices,k);
    }
};

// 309. Best Time to Buy and Sell Stock with Cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int n=prices.size();
      if(n<=1)return 0;
      if(n==2)return max(0,prices[1]-prices[0]);
      vector<int>buy(n,0);
      vector<int>sell(n,0);
      buy[0]=-prices[0];
      sell[1]=buy[0]+prices[1];
      buy[1]=-prices[1];
      //sell[2]=max(buy[1]+prices[2],sell[1]-prices[1]+prices[2]);
      //buy[2]=-prices[2];
     // int maxx=max(sell[2],max(sell[1],0));
       int maxx=max(sell[1],0);
      for(int i=2;i<n;i++)
      {
       sell[i]=max(buy[i-1]+prices[i],sell[i-1]-prices[i-1]+prices[i]);
       buy[i]=max(sell[i-2]-prices[i],buy[i-1]+prices[i-1]-prices[i]);
       if(sell[i]>maxx)
           maxx=sell[i];
      }
      return maxx;
      
    }
};
