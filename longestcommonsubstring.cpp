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


void lcs(string s1,string s2)
{
 ll m=s1.length();
 ll n=s2.length();
 ll maxx=0,row,col;
 ll k[m+1][n+1];
 f(m+1)
 {
  r(n+1)
  {
   if(i==0 || j==0)
    k[i][j]=0;
   else if(s1[i-1]==s2[j-1])
   {
    k[i][j]=1+k[i-1][j-1];
    if(k[i][j]>maxx)
    {
      maxx=k[i][j];
      row=i;
      col=j;
    }
   }
    else
    k[i][j]=0;
  }
 }

 ll zz=maxx;
 char ch[zz];
 while(k[row][col]!=0)
 {
   if(s1[row-1]==s2[col-1])
   {
    ch[--zz]=s1[row-1];
    row--;
    col--;
   }

 }
 string str="";
 f(maxx)
 {
  str=str+ch[i];
 }
 cout<<str<<endl;



}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {

  string s1,s2;
  cin>>s1>>s2;
  lcs(s1,s2);

 }
 return 0;
}
