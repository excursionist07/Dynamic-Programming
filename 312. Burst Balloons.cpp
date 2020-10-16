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

// matrixmultiplication

#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof dp)
#define INF 1000000007
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;


ll matrixmultiplication(ll a[],ll n)
{
    ll dp[n][n];
    ll j,len,i,k,q;
    for(i=1;i<n;i++)
        dp[i][i]=0;
    for(len=2;len<n;len++)
    {
        for(i=1;i<n-len+1;i++)
        {
             j=i+len-1;
            dp[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
                if(q<dp[i][j])
                    dp[i][j]=q;
            }
        }
    }
    return dp[1][n-1];
}
int main()
{
  ll n;
  cin>>n;
  ll a[n];
  f(n)
  {
      cin>>a[i];
  }
  cout<<matrixmultiplication(a,n)<<endl;
  return 0;

}

/*
https://www.codechef.com/problems/MIXTURES
https://www.spoj.com/problems/MIXTURES/
*/
