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

unordered_map<string,bool>mp;

/*bool doit(string str)//Recursive O(2^n)
{
 if(!str.length())return true;
 for(ll i=1;i<=str.length();i++)
 {
  if(mp[str.substr(0,i)] && doit(str.substr(i,str.length()-i)))
    return true;
 }
 return false;
}
*/
bool doit1(string str)//O(str.size()^2))
{
 ll n=str.length();
 if(n==0)
    return true;
 bool dp[n+1];
 mem(dp,false);
 dp[0]=true;
 for(ll len=1;len<=n;len++)
 {
  for(ll i=0;i<len;i++)
  {
   if(dp[i] && mp[str.substr(i,len-i)])
   {
    dp[len]=true;
    break;
   }
  }
 }
 return dp[n];
}
int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  mp.clear();
  ll n;
  cin>>n;
  string dict[n];
  rep(i,0,n)
  {
   cin>>dict[i];
   mp[dict[i]]=1;
  }
  string str;
  cin>>str;
  if(doit1(str))
    cout<<"Found";
  else
    cout<<"Not Found";
  cout<<"\n";

 }
 return 0;
}
