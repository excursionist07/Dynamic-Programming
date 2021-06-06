class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
     int n=nums.size();
     if(n==0)
         return 0;

     int maxx=INT_MIN,cur=0,s=0,start,end,i=0;
     for(int i=0;i<n;i++)
         maxx=max(maxx,nums[i]);
     while(i<n)
     {
      cur+=nums[i];
      if(cur>maxx)
      {
       maxx=cur;
       start=s;
       end=i;
      }
      if(cur<0)
      {
       cur=0;
       s=i+1;
      }
      i++;
     }
     return maxx;

    }
};

// 918. Maximum Sum Circular Subarray

class Solution {
public:
    int kadaneMax(vector<int>& nums)
    {
     int n=nums.size();
     int mx=INT_MIN;
     for(int i=0;i<n;i++)
         mx=max(mx,nums[i]);
     int cur=0,i=0;
     while(i<n)
     {
      cur+=nums[i];
     
      if(cur>mx)
         mx=cur;
      if(cur<0)
        cur=0;
      i++;
     }
     return mx;
    }
    
    int kadaneMin(vector<int>& nums)
    {
     int n=nums.size();
     int mn=INT_MAX;
     for(int i=0;i<n;i++)
         mn=min(mn,nums[i]);
     int cur=0,i=0;
     while(i<n)
     {
      cur+=nums[i];
      if(cur<mn)
         mn=cur;
      if(cur>0)
        cur=0;
      i++;
     }
     return mn;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) 
    {
     int n=nums.size();
     int total=0,mx=INT_MIN;
     bool positive=0;
     for(int i=0;i<n;i++)
     {
      total+=nums[i];
      mx=max(mx,nums[i]);
      if(nums[i]>=0)
          positive=1;
     }
         
     int ans1=kadaneMax(nums); // normal kadane in straight array
     int ans2=kadaneMin(nums); // if suffix+prefix makes max
     if(positive)
         return max(ans1,total-ans2);
     return mx; // if all elements are negative
     
     
    }
};

/*
--> proof for total-ans2
max(prefix+suffix)
= max(total sum - subarray)
= total sum + max(-subarray)
= total sum - min(subarray)
*/

// 304. Range Sum Query 2D - Immutable

class NumMatrix {
public:
    int m,n;
    vector<vector<int>>dp;
    
    NumMatrix(vector<vector<int>>& matrix) 
    {
     m=matrix.size();
     n=matrix[0].size();
     dp=vector<vector<int>>(m+1,vector<int>(n+1,0));
     for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
           dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];// prefix 2-D sum
     }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
     row1++;col1++;row2++;col2++;
     return dp[row2][col2]-(dp[row1-1][col2]+dp[row2][col1-1]-dp[row1-1][col1-1]);
    }
};


