#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 */

 /*ll doit(ll egg,ll floor)//O(2^n)
 {
  if(floor==0 || floor==1)
    return floor;
  if(egg==1)
    return floor;
  ll minn=ESP,res;
  for(ll i=1;i<=floor;i++)
  {
   res=max(doit(egg-1,i-1),doit(egg,floor-i));
   if(res<minn)
    minn=res;
  }

  return 1+minn;
 }*/
 ll doit(ll egg,ll floor)//O(egg*floor*floor)
 {
   ll dp[egg+1][floor+1];
   for(ll i=1;i<=egg;i++)
   {
    dp[i][0]=0;
    dp[i][1]=1;
   }
   for(ll i=1;i<=floor;i++)
    dp[1][i]=i;
   for(ll i=2;i<=egg;i++)
   {
    for(ll j=2;j<=floor;j++)
    {
     dp[i][j]=ESP;
     for(ll x=1;x<=j;x++)
     {
      ll res=1+max(dp[i-1][x-1],dp[i][j-x]);
      if(dp[i][j]>res)
        dp[i][j]=res;
     }
    }
   }
   return dp[egg][floor];
 }

 int main()
 {
  hs;
  ll t;
  cin>>t;
  while(t--)
  {
   ll egg,floor;
   cin>>egg>>floor;
   cout<<doit(egg,floor)<<"\n";
  }
  return 0;
 }
