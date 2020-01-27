#include<bits/stdc++.h>
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

ll decimal(string str,ll p,ll q)
{
 ll ans=0;
 for(ll i=p;i<q;i++)
   ans=(ans*2)+(str[i]-'0');

 return ans;

}

bool power(ll a,ll b)
{
 while(a>1)
 {
  if(a%b!=0)
    return 0;
  a/=b;
 }
 return 1;
}

void mincut(string str)
{
  ll n=str.length();
  ll dp[n+1];
  f(n+1)
   dp[i]=HRX;
  dp[0]=0;
  for(ll j=1;j<=n;j++)
  {
    if(str[j-1]=='0')
        continue;
    for(ll i=0;i<j;i++)
    {
     if(str[i]=='0')
        continue;
     ll num=decimal(str,i,j);
     if(!power(num,5))
        continue;
     dp[j]=min(dp[j],dp[i]+1);

    }
  }
  if(dp[n]!=HRX)
    cout<<dp[n]<<endl;
  else
    cout<<"-1"<<endl;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string str;
  cin>>str;
  mincut(str);
 }
 return 0;

}
