#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;


int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  ll a[n];
  f(n)
  {
    cin>>a[i];
  }
  if(a[0]==0)
  {
   cout<<"INFINITY"<<endl;
   return 0;
  }

  ll b[n],c[n];
  b[0]=0;
  for(ll i=1;i<n;i++)
    b[i]=INF;
  c[0]=-1;
  for(ll j=1;j<n;j++)
  {
    for(ll i=0;i<j;i++)
    {
      if(i+a[i]>=j)
      {
        b[j]=min(b[j],b[i]+1);
        c[j]=i;
        break;

      }
    }
  }
  cout<<b[n-1]<<endl;
  f(n)
  {
    cout<<c[i]<<" ";
  }
  cout<<"\n";
 }
 return 0;
}

/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
https://www.hackerearth.com/problem/algorithm/interesting-path/
https://www.spoj.com/problems/STAR3CAS/
https://www.spoj.com/problems/DCEPC12F/
https://www.codechef.com/problems/JUMP
*/

// 45. Jump Game II

//O(n)

 /*
maxReach- The variable maxReach stores at all time the maximal reachable index in the array.
steps- The variable step stores the number of steps we can still take(and is initialized with value at index 0, i.e. initial number of steps)
jumps-stores the amount of jumps necessary to reach that maximal reachable position.
*/

int jump(vector<int>& nums) 
    {
     int n=nums.size();
     if(n==0 || n==1)
         return 0;
     int maxreach=nums[0];
     int steps=nums[0];
     int jumps=1;
     for(int i=1;i<n;i++)
     {
       if(i==n-1)
           return jumps;
       maxreach=max(maxreach,i+nums[i]);
       steps--;
       if(steps==0)
       {
        jumps++;
        if(i>=maxreach) // 1,1,1,0,1
            return -1;
         steps=maxreach-i;
       }
     }
        return -1;
    }

// 871. Minimum Number of Refueling Stops--->O(n^2)

/*
dp[i] means the furthest distance that we can get with i times of refueling.

So for every station s[j],
if the current distance dp[i] >= s[j][0], we can refuel:
dp[i + 1] = max(dp[i + 1], dp[i] + s[j][1])

In the end, we'll return the first t with dp[i] >= target,
otherwise we'll return -1.
*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
     int n=stations.size();
     unsigned int dp[n+1];
     for(int i=0;i<=n;i++)
         dp[i]=startFuel;
    
     for(int j=0;j<n;j++)
     {
      for(int i=j;i>=0;i--)
      {
       if(dp[i]>=stations[j][0]) // f it can reach station j, then we can refuel it from station j to cover maximum distance.
           dp[i+1]=max(dp[i+1],dp[i]+stations[j][1]);
      }
     }
     for(int i=0;i<=n;i++)
     {
      if(dp[i]>=target)
          return i;
     }
     return -1;
    
     
    }
};
