/*
Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].

1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]

Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.
*/


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

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  ll dp[n][n];
  rep(i,0,n)
  {
   rep(j,0,n)
   {
     cin>>dp[i][j];
   }
  }

  ll ans=-1;
  rep(i,1,n)
  {
    rep(j,0,n)
    {
     ll maxx=-ESP;
     if(i-1>=0)
      maxx=max(maxx,dp[i-1][j]);
     if(i-1>=0 && j-1>=0)
      maxx=max(maxx,dp[i-1][j-1]);
     if(i-1>=0 && j+1<n)
      maxx=max(maxx,dp[i-1][j+1]);
     dp[i][j]=dp[i][j]+maxx;
     ans=max(ans,dp[i][j]);
    }
  }

  cout<<ans<<"\n";

 }
 return 0;
}
