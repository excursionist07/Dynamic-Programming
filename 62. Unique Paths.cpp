// 62. Unique Paths

class Solution {
public:
    /*int doit(int m,int n)
    {
     if(m==1 || n==1)
         return 1;
     return doit(m-1,n)+doit(m,n-1)//+doit(m-1,n-1) if diagonal movements are allowed;
    }*/
    int uniquePaths(int m, int n)
    {
     int dp[m][n];
     for(int i=0;i<m;i++)
         dp[i][0]=1;
     for(int i=1;i<n;i++)
         dp[0][i]=1;
     for(int i=1;i<m;i++)
     {
      for(int j=1;j<n;j++)
          dp[i][j]=dp[i-1][j]+dp[i][j-1];
     }
     return dp[m-1][n-1];
    }
};

// 63. Unique Paths II(obstacle in grid)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
     int m=obstacleGrid.size();
     if(m==0)
         return 0;
     int n=obstacleGrid[0].size();
     if(obstacleGrid[0][0]==1)
         return 0;
     int dp[m][n];
     dp[0][0]=1;
     for(int i=1;i<n;i++)
     {
      if(obstacleGrid[0][i]==0 && dp[0][i-1]==1)
          dp[0][i]=1;
      else
          dp[0][i]=0;
     }
     for(int i=1;i<m;i++)
     {
      if(obstacleGrid[i][0]==0 && dp[i-1][0]==1)
          dp[i][0]=1;
      else
          dp[i][0]=0;
     }
     for(int i=1;i<m;i++)
     {
      for(int j=1;j<n;j++)
      {
       if(obstacleGrid[i][j]==0)
           dp[i][j]=dp[i-1][j]+dp[i][j-1];
       else
           dp[i][j]=0;
      }
     }
     return dp[m-1][n-1];
    }
};

// Minimum Cost Path right and down

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
ll m,n;

void minncost(ll m,ll n)
{
  ll k[m][n];
  k[0][0]=a[0][0];
  for(ll i=1;i<n;i++)
  {
    k[0][i]=a[0][i]+k[0][i-1];
  }
  for(ll i=1;i<m;i++)
  {
    k[i][0]=a[i][0]+k[i-1][0];
  }
  for(ll i=1;i<m;i++)
  {
    for(ll j=1;j<n;j++)
    {
     k[i][j]=min(k[i-1][j],k[i][j-1])+a[i][j];
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
  cin>>m>>n;
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

// minimumcostpath right diagonal down

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

// minimumcostpath top down left right

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

// 174. Dungeon Game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
     int m=dungeon.size();
     int n=dungeon[0].size();
     int dp[m+1][n+1];// adding one dummy row & col for just ease.
     for(int i=0;i<=m;i++)
         for(int j=0;j<=n;j++)
             dp[i][j]=INT_MAX;
     dp[m][n-1]=1; // b'coz at any cell health can't be 0
     dp[m-1][n]=1; // b'coz at any cell health can't be 0
     for(int i=m-1;i>=0;i--)
     {
      for(int j=n-1;j>=0;j--)
      {
       int xx=min(dp[i][j+1],dp[i+1][j])-dungeon[i][j];
       dp[i][j]=(xx<=0 ? 1 : xx);
      }
     }
     return dp[0][0];
        
    }
};

// 741. Cherry Pickup

const int N=52;
int dp[N][N][N];

class Solution {
public:
    int doit(vector<vector<int>>& grid,int n,int r1,int c1,int c2)
    {
     int r2=r1+c1-c2;// using Manhattan distance(r1+c1=r2+c2)
     if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
         return INT_MIN;
     if(dp[r1][c1][c2]!=-1)return dp[r1][c1][c2];
     if(r1==n-1 && c1==n-1)return grid[r1][c1];
     int ans=grid[r1][c1];
     if(c1!=c2) // both are not at same place
         ans+=grid[r2][c2];
     int temp=max(doit(grid,n,r1+1,c1,c2),doit(grid,n,r1+1,c1,c2+1)); // (DD && DR);
     temp=max(temp,doit(grid,n,r1,c1+1,c2+1)); // (RR)
     temp=max(temp,doit(grid,n,r1,c1+1,c2));  //(RD)
     ans+=temp;
     return (dp[r1][c1][c2]=ans);
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
     int n=grid.size();
     for(int i=0;i<N;i++)
         for(int j=0;j<N;j++)
             for(int k=0;k<N;k++)
                 dp[i][j][k]=-1;
     int ans=max(0,doit(grid,n,0,0,0));
     return ans;

    }
};

// Path in Matrix

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
