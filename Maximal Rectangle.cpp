#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll INF=1e9+7;

const ll N=1e3+7;
ll a[N][N];


ll histoarea(vector<ll>vec)
{
 ll n=vec.size();
 stack<ll>stk;
 ll i=0,tp,maxx=0;
 while(i<n)
 {
  if(stk.empty() || vec[i]>=vec[stk.top()])
    stk.push(i),i++;
  else
  {
   tp=stk.top();
   stk.pop();
   if(stk.empty())
    maxx=max(maxx,vec[tp]*i);
   else
    maxx=max(maxx,vec[tp]*(i-stk.top()-1));
  }
 }
 while(!stk.empty())
 {
   tp=stk.top();
   stk.pop();
   if(stk.empty())
    maxx=max(maxx,vec[tp]*i);
   else
    maxx=max(maxx,vec[tp]*(i-stk.top()-1));
 }
 return maxx;
}

ll mxrecarea(ll m,ll n)
{
 ll dp[m][n];
 for(ll i=0;i<n;i++)
    dp[0][i]=a[0][i];
 for(ll i=1;i<m;i++)
 {
  for(ll j=0;j<n;j++)
  {
   if(a[i][j]==1)
    dp[i][j]=1+dp[i-1][j];
   else
    dp[i][j]=0;
  }
 }
 ll maxx=0;
 for(ll i=0;i<m;i++)
 {
  vector<ll>vec;
  for(ll j=0;j<n;j++)
  {
   vec.pb(dp[i][j]);
  }
  maxx=max(maxx,histoarea(vec));
 }
 return maxx;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll m,n;
  cin>>m>>n;
  f(m)
  {
   r(n)
   {
    cin>>a[i][j];
   }
  }
  cout<<mxrecarea(m,n)<<"\n";

 }
 return 0;
}
