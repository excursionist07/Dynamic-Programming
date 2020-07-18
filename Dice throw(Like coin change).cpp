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
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

void doit(ll face,ll dice,ll total)
{
 ll dp[dice+1][total+1];
 mem(dp,0);
 for(ll i=1;i<=face && i<=total;i++)
    dp[1][i]=1;
 for(ll i=2;i<=dice;i++)
 {
  for(ll j=1;j<=total;j++)
  {
   for(ll k=1;k<j && k<=face;k++)
   {
    dp[i][j]+=dp[i-1][j-k];
   }
  }
 }
 cout<<dp[dice][total]<<"\n";
}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll face,dice,total;
  cin>>face>>dice>>total;
  doit(face,dice,total);

 }
 return 0;
}
