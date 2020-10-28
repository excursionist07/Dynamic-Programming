// coin change problem

class Solution {
public:
    int coinchange(vector<int>&coins,int total)
    {
     int n=coins.size();
     int dp[n+1][total+1];
     for(int i=0;i<=n;i++)
         dp[i][0]=1;
     for(int i=1;i<=total;i++)
         dp[0][i]=0;
     for(int i=1;i<=n;i++)
     {
      for(int j=1;j<=total;j++)
      {
       if(j>=coins[i-1])
           dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
       else
           dp[i][j]=dp[i-1][j];
      }
     }
     return dp[n][total];
    }
    int change(int amount, vector<int>& coins) 
    {
     int n=coins.size();
     if(amount==0)
         return 1;
     if(n==0)
         return 0;
     
     return coinchange(coins,amount);
    }
};


// Minimum coins to get total

class Solution {
public:
    int mcc(vector<int>& coins,int total)
    {
     int n=coins.size();
     int dp[n+1][total+1];
     for(int i=0;i<=n;i++)
         dp[i][0]=0;
     for(int i=1;i<=total;i++)
         dp[0][i]=1e9;
     for(int i=1;i<=n;i++)
     {
      for(int j=1;j<=total;j++)
      {
       if(j>=coins[i-1])
           dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
      else
          dp[i][j]=dp[i-1][j];
      }
     }
     if(dp[n][total]!=1e9)
         return dp[n][total];
     else
         return -1;
    }
    int coinChange(vector<int>& coins, int amount)
    {
     int n=coins.size();
     if(n==0 || amount==0)
         return 0;
     return mcc(coins,amount);
    }
};

// 377. Combination Sum IV

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
     int n=nums.size();
     if(target==0)
         return 1;
     if(n==0)
         return 0;
     unsigned int dp[target+1];
     for(int i=0;i<=target;i++)
         dp[i]=0;
     dp[0]=1;
     for(int j=1;j<=target;j++)
     {
      for(int i=0;i<n;i++)
      {
       if(j-nums[i]>=0)
           dp[j]+=dp[j-nums[i]];
      }
     }
     return dp[target];
    }
};

