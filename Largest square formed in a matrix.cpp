// 221. Largest square formed in a matrix

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
     int m=matrix.size();
     if(m==0)return 0;
     int n=matrix[0].size();
     int dp[m][n];
     dp[0][0]=matrix[0][0]-'0';
    // cout<<dp[0][0]<<"\n";
     for(int i=1;i<n;i++)
         dp[0][i]=matrix[0][i]-'0';
     for(int i=1;i<m;i++)
         dp[i][0]=matrix[i][0]-'0';
     for(int i=1;i<m;i++)
     {
      for(int j=1;j<n;j++)
      {
       if(matrix[i][j]=='1')
           dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
       else
           dp[i][j]=0;
      }
     }
     int maxx=0;
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       maxx=max(maxx,dp[i][j]);
      }
     }
        return maxx*maxx;
    }
};

// Maximum sum Rectangle

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
 ll up,down,start,endd;
 
 ll kadane(ll temp[],ll n)
 {
  ll maxx=-ESP,s=0,idx=0,cur=0;
  start=0;
  endd=0;
  while(idx<n)
  {
   cur+=temp[idx];
   if(cur>maxx)
   {
    maxx=cur;
    start=s;
    endd=idx;
   }
   if(cur<0)
   {
    cur=0;
    s=idx+1;
   }
   idx++;
  }
  return maxx;
 }
 
 int main()
 {
  hs;
  ll t;
  cin>>t;
  while(t--)
  {
   ll m,n;
   cin>>m>>n;
   ll a[m][n];
   rep(i,0,m)
   {
    rep(j,0,n)
    {
     cin>>a[i][j];
    }
   }
   ll maxx=-ESP;
   ll temp[m],left,right;
   for(ll i=0;i<n;i++)
   {
    mem(temp,0);
    for(ll j=i;j<n;j++)
    {
     for(ll k=0;k<m;k++)
       temp[k]+=a[k][j];
     ll zz=kadane(temp,m);
     if(zz>maxx)
     {
      maxx=zz;
      left=i;
      right=j;
      up=start;
      down=endd;
     }
    }
   }
   cout<<maxx<<"\n";
   //cout<<left<<" "<<right<<" "<<up<<" "<<down<<"\n";
   
  }
  return 0;
 }

// 1504. Count Submatrices With All Ones --> for doubt (https://leetcode.com/problems/count-submatrices-with-all-ones/discuss/720265/Java-Detailed-Explanation-From-O(MNM)-to-O(MN)-by-using-Stack)

class Solution {
public:
    int doit(vector<int>& vv) // Like we do in 1-D array
    {
     int ans=0,zz=0;
     for(int i=0;i<vv.size();i++)
     {
      zz=(vv[i]==0 ? 0 : 1+zz);
      ans+=zz;
     }
     return ans;
    }
    int numSubmat(vector<vector<int>>& mat) 
    {
     int m=mat.size();
     int n=mat[0].size();
     int ans=0;
     for(int j=0;j<n;j++)
     {
      vector<int>vv(m,1);
      for(int i=j;i<n;i++)
      {
       for(int k=0;k<m;k++)
           vv[k]&=mat[k][i];
       ans+=doit(vv);
      }
     }
     return ans;
     
    }
};

// O(n * n * m):

// 1074. Number of Submatrices That Sum to Target

class Solution {
public:
    int doit(vector<int>& vv,int tar) // 560. Subarray Sum Equals K [i.e--> // if cur sum exceeds or equal(0,5,5,5 && k==10) k value ,so we check by eliminating k from cur]
    {
     unordered_map<int,int>mp;
     int cur=0,ans=0;
     for(int i=0;i<vv.size();i++)
     {
      cur+=vv[i];
      if(cur==tar)
          ans++;
      if(mp.find(cur-tar)!=mp.end())
          ans+=mp[cur-tar];
      mp[cur]++;
     }
     return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
     int m=matrix.size();
     int n=matrix[0].size();
     int ans=0;
     for(int j=0;j<n;j++)
     {
      vector<int>vv(m,0);
      for(int i=j;i<n;i++)
      {
       for(int k=0;k<m;k++)
           vv[k]+=matrix[k][i];
       ans+=doit(vv,target);
      }
     }
     return ans;
    }
};

/// O(n * n * m):
