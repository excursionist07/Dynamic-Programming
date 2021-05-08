class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
     int n=nums.size();
     if(n<=2 || n%2==0) // if size is even it can always win
         return 1;
     int total=0;
     for(int i=0;i<n;i++)
         total+=nums[i];
     int dp[n][n];
     for(int i=0;i<n;i++)
         dp[i][i]=nums[i];
     for(int i=0;i<n-1;i++)
         dp[i][i+1]=max(nums[i],nums[i+1]);
     for(int len=3;len<=n;len++)
     {
      for(int i=0;i<n-len+1;i++)
      {
       int j=i+len-1;
       int front=nums[i]+min(dp[i+1][j-1],dp[i+2][j]); // if u choose ith coin first
       int back=nums[j]+min(dp[i][j-2],dp[i+1][j-1]); // if u choose jth coin first
       dp[i][j]=max(front,back);
      }
     }
     return (2*dp[0][n-1]-total>=0);
     
     
     
    }
};

// dp(i, j) represents the maximum value the user can collect from i'th coin to j'th coin.
// dp[0][n-1] collected by first player
/*
take example of [a,b,c,d,e]: (here i==0 && j==4)
  // 1st case: if u choose from front
     front=a[0]+min(dp[1][3],dp[2][4])
  // 2nd case: if u choose from back
     back=a[4]+min(dp[0][2],dp[1][3])
     
  dp[i][j]=max(front,back)
     
         
*/
