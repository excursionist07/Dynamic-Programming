// same as rod cutting

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

void unbounded_kanpsack(ll wt[],ll val[],ll n,ll total)
{
  ll k[n+1][total+1];
  f(n+1)
  {
    r(total+1)
    {
      if(i==0 || j==0)
        k[i][j]=0;
      else if(j>=wt[i-1])
        k[i][j]=max(k[i-1][j],val[i-1]+k[i][j-wt[i-1]]);
      else
        k[i][j]=k[i-1][j];
    }
  }
  cout<<k[n][total]<<endl;
}
int main()
{
  hs;
  ll n;
  cin>>n;
  ll wt[n],val[n];
  f(n)
  {
    cin>>wt[i]>>val[i];
  }
  ll total;
  cin>>total;
  unbounded_kanpsack(wt,val,n,total);
  return 0;
}

/*
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
*/
