/*
dp[i][j] represents the maximum coins we get after we burst all the balloons from i to j.
Let Kth is the last balloon to be burst in thr interval [i,j] then,
dp[i][j] = maximum value of bursting all the balloon on the left side of 'K' + maximum value of bursting all the balloon on the right side of 'K' + bursting balloon 'K' when left side and right side are gone.
dp[i][j] = dp[i][K-1] + (A[i-1] * A[K] * A[j+1]) + dp[K+1][j]
*/

class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
     int n=nums.size();
     if(n==0)
         return 0;
     if(n==1)
         return nums[0];
     nums.insert(nums.begin(),1);
     nums.push_back(1);
     vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));//n+2 size dp
     for(int len=1;len<=n;len++)
     {
      for(int i=1;i<=n-len+1;i++)
      {
       int j=i+len-1;// last index
       for(int k=i;k<=j;k++)// kth baloon burst to be last one
           dp[i][j]=max(dp[i][j],nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
      }
     }
     return dp[1][n];
     
    }
};

// O(n^3) time and O(n^2) space complexity
