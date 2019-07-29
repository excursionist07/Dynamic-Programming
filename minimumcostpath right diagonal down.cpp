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

const ll N=2*1001;
ll a[N][N];
ll n,m;

void minncost(ll m,ll n)
{
 ll k[m][n];
 k[0][0]=a[0][0];
 for(ll i=1;i<n;i++)
    k[0][i]=a[0][i]+k[0][i-1];
 for(ll i=1;i<m;i++)
    k[i][0]=a[i][0]+k[i-1][0];
 for(ll i=1;i<m;i++)
 {
  for(ll j=1;j<n;j++)
  {
    k[i][j]=min(k[i-1][j-1],min(k[i-1][j],k[i][j-1]))+a[i][j];
  }
 }
 cout<<k[m-1][n-1]<<endl;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>n>>m;
  f(m)
  {
    r(n)
    {
     cin>>a[i][j];
    }
  }
  minncost(m,n);

 }
 return 0;

}
