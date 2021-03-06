// LIS

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
      int n=nums.size();
      vector<int>dp(n,1);
      for(int j=1;j<n;j++)
      {
       for(int i=0;i<j;i++)
       {
        if(nums[j]>nums[i])
            dp[j]=max(dp[j],1+dp[i]);
       }
      }
      return *max_element(dp.begin(),dp.end());
     
    }
};

// n*log(n)

class Solution {
public:
    int bs(vector<int>&ans,int lo,int hi,int x) // lower_bound using binary search
    {
     while(lo<=hi)
     {
      int mid=(lo+hi)/2;
      if(ans[mid]==x)
          hi=mid-1;
      else if(ans[mid]>x)
          hi=mid-1;
      else
          lo=mid+1;
     }
     return max(0,lo);
    }
    int lengthOfLIS(vector<int>& nums)
    {
     vector<int>ans;
     for(int i=0;i<nums.size();i++)
     {
      //int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
	     // OR
      int idx=bs(ans,0,ans.size()-1,nums[i]);
      if(idx==ans.size())
         ans.push_back(nums[i]);
      else
          ans[idx]=nums[i];
     }
     return ans.size(); // if you want to print the lis then value in ans is not always correct.
    }
};

// 354. Russian Doll Envelopes

/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one 
envelope is greater than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll? (put one inside other)??
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
     int n=envelopes.size();
     if(n<2)
         return n;
     vector<pair<int,int>>vv;
     for(int i=0;i<n;i++)
         vv.push_back({envelopes[i][0],envelopes[i][1]});
     sort(vv.begin(),vv.end());
     int dp[n];
     for(int i=0;i<n;i++)
         dp[i]=1;
     int ans=1;
     for(int j=1;j<n;j++)
     {
      for(int i=0;i<j;i++)
      {
       if(vv[j].first>vv[i].first && vv[j].second>vv[i].second)
           dp[j]=max(dp[j],1+dp[i]),ans=max(ans,dp[j]);
      }
     }
     return ans; // if you have to print all indexes in LIS (https://codeforces.com/problemset/problem/4/D)
    }
};

// 2nd method-->(N*log(N))
/*
You can solve this problem in this way :

let's suppose the values are given as...
[2,3]
[4,6]
[3,7]
[4,8]

If we Sort this envelopes in a tricky way that Sort the envelopes according to width BUT when the values of height are same, we can sort it in reverse way like this :

[2,3]
[3,7]
[4,8]
[4,6]

Now just Do LIS on the all height values, you will get the answer
*/

class Solution {
public:
    static bool compare(pair<int,int>&a,pair<int,int>&b) // --> static-b'coz it's not ana instance member function
    {
     return (a.first<b.first || (a.first==b.first && a.second>b.second));
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
     int n=envelopes.size();
     if(n<2)
         return n;
     vector<pair<int,int>>vv;
     for(int i=0;i<n;i++)
         vv.push_back({envelopes[i][0],envelopes[i][1]});
     sort(vv.begin(),vv.end(),compare);
     vector<int>ans;
     for(int i=0;i<n;i++)
     {
      int idx=lower_bound(ans.begin(),ans.end(),vv[i].second)-ans.begin();
      if(idx==ans.size())
          ans.push_back(vv[i].second);
      else
          ans[idx]=vv[i].second;
     
     }
     return ans.size();
     
    }
};



// Longest Bitonic subsequence

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
    ll a[n],lis[n],lds[n];
    rep(i,0,n)
    {
     cin>>a[i];
     lis[i]=1;
     lds[i]=1;
    }
    for(ll j=1;j<n;j++)
    {
     for(ll i=0;i<j;i++)
     {
      if(a[j]>a[i])
       lis[j]=max(lis[j],1+lis[i]);
     }
    }
    for(ll j=n-2;j>=0;j--)
    {
     for(ll i=n-1;i>j;i--)
     {
      if(a[j]>a[i])
       lds[j]=max(lds[j],1+lds[i]);
     }
    }
    ll maxx=-1;
    rep(i,0,n)
     maxx=max(maxx,lis[i]+lds[i]-1);
    cout<<maxx<<"\n";
     
    
  }
  return 0;
 }

// 1671. Minimum Number of Removals to Make Mountain Array (Like Longest Bitonic subsequence)

//  // O(n*log(n))  
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
     int n=nums.size();
     vector<int>dp1(n),dp2(n);
     vector<int>ans;
     for(int i=0;i<n;i++)
     {
      int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
      if(idx==ans.size())
          ans.push_back(nums[i]);
      else
          ans[idx]=nums[i];
      dp1[i]=1+idx;
     }
     ans.clear();
     for(int i=n-1;i>=0;i--)
     {
      int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
      if(idx==ans.size())
          ans.push_back(nums[i]);
      else
          ans[idx]=nums[i];
      dp2[i]=1+idx;
     }
        
     int zz=0;
     
     for(int i=0;i<n;i++)
     {
      if(dp1[i]>1 && dp2[i]>1) // This is done b'coz in array first should increase then decrese (both must happen)
          zz=max(zz,dp1[i]+dp2[i]-1);
     }
     return n-zz;
    }
};

/*
https://leetcode.com/problems/maximum-length-of-pair-chain/
https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
*/

// 673. Number of Longest Increasing Subsequence

class Solution {
public:

    /*
    The idea is to use two arrays len[n] and cnt[n] to record the maximum length of Increasing Subsequence and the coresponding number of these sequence which ends with nums[i], respectively. 
    That is:
      dp[i]: the length of  the longest subsequence.
      cnt[i]: the number of such subsequences with that length.
   */
    int findNumberOfLIS(vector<int>& nums)
    {
     int n=nums.size();
     if(n<=1)
         return n;
     int dp[n],cnt[n];
     int maxx=0,res=0;
     for(int j=0;j<n;j++)
     {
      dp[j]=1;cnt[j]=1;
      for(int i=0;i<j;i++)
      {
       if(nums[j]>nums[i])
       {
         if(dp[j]==1+dp[i])
             cnt[j]+=cnt[i]; //i.e-1 1 2
         else if(dp[j]<1+dp[i])
         {
          dp[j]=1+dp[i];
          cnt[j]=cnt[i];
         }
       }
      }
      if(maxx==dp[j])res+=cnt[j];// 1 1 2 2
      if(maxx<dp[j])
      {
       maxx=dp[j];
       res=cnt[j];
      }
     }
     return res;


    }
};

// Maximum sum increasing subsequence

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


int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  ll a[n],b[n],c[n];
  f(n)
  {
    cin>>a[i];
    b[i]=a[i];
    c[i]=i;
  }
  for(ll j=1;j<n;j++)
  {
    for(ll i=0;i<j;i++)
    {
     if(a[j]>a[i])
     {
      b[j]=max(b[j],a[j]+b[i]);
      if(b[j]==a[j]+b[i])
        c[j]=i;
     }
    }
  }

  ll maxx=-1,index;
  f(n)
  {
   if(b[i]>maxx)
   {
    maxx=b[i];
    index=i;
   }
  }
  cout<<maxx<<endl;

  ll sum=0;
  while(sum!=maxx)
  {
    cout<<a[index]<<" ";
    sum=sum+a[index];
    index=c[index];
  }
 }
 return 0;
}

/*
https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
https://www.codechef.com/problems/LISA
https://www.codechef.com/problems/SEAINCR
https://www.codechef.com/problems/MMSUM
*/

// 801. Minimum Swaps To Make Sequences Increasing

class Solution {
public:
    /*
    swap[n] means the minimum swaps to make the A[i] and B[i] sequences increasing for 0 <= i <= n,
    in condition that we swap A[n] and B[n]
    not_swap[n] is the same with A[n] and B[n] not swapped.
@Acker help explain:
A[i - 1] < A[i] && B[i - 1] < B[i].
In this case, if we want to keep A and B increasing before the index i, can only have two choices.
  -> 1.1 don't swap at (i-1) and don't swap at i, we can get not_swap[i] = not_swap[i-1]
  -> 1.2 swap at (i-1) and swap at i, we can get swap[i] = swap[i-1]+1
   if swap at (i-1) and do not swap at i, we can not guarantee A and B increasing.
A[i-1] < B[i] && B[i-1] < A[i]
In this case, if we want to keep A and B increasing before the index i, can only have two choices.
   -> 2.1 swap at (i-1) and do not swap at i, we can get notswap[i] = Math.min(swap[i-1], notswap[i] )
   -> 2.2 do not swap at (i-1) and swap at i, we can get swap[i]=Math.min(notswap[i-1]+1, swap[i])
*/

    int minSwap(vector<int>& A, vector<int>& B)
    {
     int n=A.size();
     if(n<=1)
         return 0;
     int swap[n],notswap[n];
     swap[0]=1;notswap[0]=0;
     for(int i=1;i<n;i++)//O(n) space
     {
      swap[i]=notswap[i]=n;
      if(A[i]>A[i-1] && B[i]>B[i-1])
      {
       notswap[i]=notswap[i-1];// don't swap at (i-1) and don't swap at i
       swap[i]=swap[i-1]+1;//  swap at (i-1) and swap at i
      }
      if(A[i]>B[i-1] && B[i]>A[i-1])
      {
       notswap[i]=min(notswap[i],swap[i-1]);// swap at (i-1) and do not swap at i
       swap[i]=min(swap[i],notswap[i-1]+1);//   do not swap at (i-1) and swap at i
      }
     }
     return min(swap[n-1],notswap[n-1]);
    }
    
   /* int swap=1,not_swap=0;
     for(int i=1;i<n;i++)//O(1) space
     {
      int swap2=n,not_swap2=n;
      if(A[i]>A[i-1] && B[i]>B[i-1])
      {
       not_swap2=not_swap;
       swap2=swap+1;
      }
      if(A[i]>B[i-1] && B[i]>A[i-1])
      {
        not_swap2=min(not_swap2,swap);
        swap2=min(swap2,not_swap+1);
      }
      swap=swap2;
      not_swap=not_swap2;
     }
     return min(swap,not_swap);*/
};





// 665. Non-decreasing Array

// Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

// 1st method--> O(n^2)

class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
      int n=nums.size();
      vector<int>dp(n,1);
      for(int j=1;j<n;j++)
      {
       for(int i=0;i<j;i++)
       {
        if(nums[j]>=nums[i])
            dp[j]=max(dp[j],1+dp[i]);
       }
      }
      int zz=*max_element(dp.begin(),dp.end());
      return (zz>=n-1);
     
    }
};

// 2nd Method--> O(n*log(n))

class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
     int n=nums.size();
     vector<int>ans;
     for(int i=0;i<n;i++)
     {
      int idx=upper_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
      if(idx==ans.size())
          ans.push_back(nums[i]);
      else
          ans[idx]=nums[i];
     }
     return (ans.size()>=n-1);
     
    }
};


