class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
     int n=nums.size();
     unsigned int dp[1+target];
     dp[0]=1;
     //int mod=1e9+7;
     for(int i=1;i<=target;i++)
         dp[i]=0;
     for(int i=1;i<=target;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(i-nums[j]>=0)
       {
          dp[i]+=dp[i-nums[j]];
          //dp[i]%=mod;
       }

      }
     // cout<<dp[i]<<" ";
     }
     return dp[target];
    }
};
