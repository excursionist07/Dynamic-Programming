class Solution {
public:

    /*
    The idea is to use two arrays len[n] and cnt[n] to record the maximum length of Increasing Subsequence and the coresponding number of these sequence which ends with nums[i], respectively. That is:

len[i]: the length of the Longest Increasing Subsequence which ends with nums[i].
cnt[i]: the number of the Longest Increasing Subsequence which ends with nums[i].
*/
    int findNumberOfLIS(vector<int>& nums)
    {
     int n=nums.size();
     if(n<=1)
         return n;
     int dp[n],cnt[n];
     int maxx=0,res=0;
     for(int j=0;j<n;j++)
     {
      dp[j]=1;cnt[j]=1;
      for(int i=0;i<j;i++)
      {
       if(nums[j]>nums[i])
       {
         if(dp[j]==1+dp[i])
             cnt[j]+=cnt[i];
         else if(dp[j]<1+dp[i])
         {
          dp[j]=1+dp[i];
          cnt[j]=cnt[i];
         }
       }
      }
      if(maxx==dp[j])res+=cnt[j];
      if(maxx<dp[j])
      {
       maxx=dp[j];
       res=cnt[j];
      }
     }
     return res;


    }
};
