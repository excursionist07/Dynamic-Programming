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

void palindromic(string s)
{
  ll n=s.length();
  bool vis[n][n];
  mem(vis,0);
  for(ll i=0;i<n;i++)
    vis[i][i]=1;
  ll maxlength=1;
  ll start=1;
  for(ll i=0;i<n-1;i++)
  {
   if(s[i]==s[i+1])
   {
    vis[i][i+1]=1;
    maxlength=2;
    start=i;
   }
  }
  for(ll k=3;k<=n;k++)
  {
   for(ll i=0;i<n-k+1;i++)
   {
    ll j=i+k-1;
    if(vis[i+1][j-1] && s[i]==s[j])
    {
      vis[i][j]=1;
      if(k>maxlength)
      {
       maxlength=k;
       start=i;
      }
    }
   }
  }
  ll low=start;
  ll high=start+maxlength-1;
  cout<<maxlength<<endl;
  for(ll i=start;i<=high;i++)
  {
    cout<<s[i];
  }
  cout<<"\n";

}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string s;
  cin>>s;
  palindromic(s);
 }
 return 0;
}
