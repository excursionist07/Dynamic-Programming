 // for any keystroke n, we will need to choose between:- 
        // 1. pressing Ctrl-V once after copying the 
        // A's obtained by n-3 keystrokes. 
  
        // 2. pressing Ctrl-V twice after copying the A's 
        // obtained by n-4 keystrokes. 
  
        // 3. pressing Ctrl-V thrice after copying the A's 
        // obtained by n-5 keystrokes.

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
 
 const ll N=100;
 ll dp[N];
 
 void doit()
 {
  rep(i,0,7)
   dp[i]=i;
  rep(i,7,N)
   dp[i]=max(2*dp[i-3],max(3*dp[i-4],4*dp[i-5]));
 }
 
 int main()
 {
  hs;
  doit();
  ll t;
  cin>>t;
  while(t--)
  {
   ll n;
   cin>>n;
   cout<<dp[n]<<"\n";
  }
  return 0;
 }

// 2-KEY KEYBOARD-----ans is sum of prime factors of n


class Solution {
public:
    int minSteps(int n) 
    {
     if(n==1)
         return 0;
     int ans=0,p=2;
     while(n>1)
     {
      while(n%p==0)
      {
       ans+=p;
       n/=p;
      }
      p++;
     }
     return ans;
    }
};
