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

void doit(string str)//O(n^3)
{
 ll n=str.length();
 ll dp[n];
 bool isPal[n][n];
 mem(isPal,0);
 rep(i,0,n)
 {
  //dp[i][i]=0;
  isPal[i][i]=1;
 }
 // for length 2
 /*for(ll i=0;i<n-1;i++)
 {
  if(str[i]==str[i+1])
  {
   dp[i][i+1]=0;
   isPal[i][i+1]=1;
  }
  else
  {
   dp[i][i+1]=1;
   isPal[i][i+1]=0;
  }
 }*/

 /*for(ll len=3;len<=n;len++)//O(n^3)
 {
  for(ll i=0;i<n-len+1;i++)
  {
   ll j=i+len-1;// ending index
   isPal[i][j]=(str[i]==str[j] && isPal[i+1][j-1]);
   if(isPal[i][j])
    dp[i][j]=0;
   else
   {
    dp[i][j]=ESP;
    for(ll k=i;k<=j-1;k++)
        dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
   }
  }
 }
 cout<<dp[0][n-1]<<"\n";*/

 for(ll len=2;len<=n;len++)//O(n^2)
 {
  for(ll i=0;i<n-len+1;i++)
  {
   ll j=i+len-1;
   if(len==2)
    isPal[i][j]=(str[i]==str[j]);
   else
    isPal[i][j]=(str[i]==str[j] && isPal[i+1][j-1]);
  }
 }


 for(ll i=0;i<n;i++)
 {
  if(isPal[0][i])
    dp[i]=0;
  else
  {
   dp[i]=ESP;
   for(ll j=0;j<i;j++)
   {
    if(isPal[j+1][i])
        dp[i]=min(dp[i],1+dp[j]);
   }
  }
 }
 cout<<dp[n-1]<<"\n";
}
int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  string str;
  cin>>str;
  doit(str);
 }
 return 0;

}
