// 198. House Robber

class Solution {
public:
    int rob(vector<int>& nums) 
    {
     int n=nums.size();
     if(n==0)
         return 0;
     if(n==1)
         return nums[0];
     if(n==2)
         return max(nums[0],nums[1]);
     int dp[n];
     dp[0]=nums[0];
     dp[1]=max(nums[0],nums[1]);
     for(int i=2;i<n;i++)
         dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
     return dp[n-1];
    }
};

// 213. House Robber II

class Solution {
public:
    int doit(vector<int>&nums,int l,int r) //--> replace i by i-l(L)
    {
     int n=nums.size()-1;
     int dp[n];
     dp[0]=nums[l];
     dp[1]=max(nums[l],nums[l+1]);
     for(int i=l+2;i<=r;i++)
         dp[i-l]=max(dp[i-l-1],nums[i]+dp[i-l-2]);
     return dp[n-1];
    }
    int rob(vector<int>& nums) 
    {
     int n=nums.size();
     if(n==0)
         return 0;
     if(n==1)
         return nums[0];
     if(n==2)
         return max(nums[0],nums[1]);
     return max(doit(nums,0,n-2),doit(nums,1,n-1));
    }
};

// 337. House Robber III


class Solution {
public:
    int doit(TreeNode* root,int& l,int& r)
    {
     if(!root)
         return 0;
     int ll=0,lr=0,rl=0,rr=0;
     l=doit(root->left,ll,lr);
     r=doit(root->right,rl,rr);
     return max(root->val+ll+lr+rl+rr,l+r);
    }
    int rob(TreeNode* root)
    {
     if(!root)
         return 0;
     int l,r;
     return doit(root,l,r);
     
    }
};
