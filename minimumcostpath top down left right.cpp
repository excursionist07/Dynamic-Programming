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
typedef pair<ll,pair<ll,ll>>PI;
ll HRX=1e18;
ll INF=1e9+7;



ll dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};


int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  ll a[n][n];
  ll dist[n][n];
  bool vis[n][n];
  f(n)
  {
    r(n)
    {
     cin>>a[i][j];
     vis[i][j]=0;
     dist[i][j]=HRX;
    }
  }
  priority_queue<PI,vector<PI>,greater<PI>>pq;
  pq.push(m_p(a[0][0],m_p(0,0)));
  dist[0][0]=a[0][0];
  vis[0][0]=1;

  while(!pq.empty())
  {
   PI u=pq.top();
   pq.pop();
   ll weight=u.first;
   ll x=u.second.first;
   ll y=u.second.second;
   for(ll i=0;i<4;i++)
   {
    ll xx=x+dir[i][0];
    ll yy=y+dir[i][1];
    if(xx>=0 && yy>=0 && xx<n && yy<n && dist[xx][yy]>dist[x][y]+a[xx][yy] && !vis[xx][yy])
    {
     vis[xx][yy]=1;
     dist[xx][yy]=dist[x][y]+a[xx][yy];
     pq.push(m_p(dist[xx][yy],m_p(xx,yy)));
    }
   }
  }
  cout<<dist[n-1][n-1]<<endl;
}
 return 0;
}
