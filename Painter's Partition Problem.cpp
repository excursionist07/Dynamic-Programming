// Painter's Partition Problem(IB)


bool IsValid(vector<int>&C,int mid,int n) // O(n)
{
 long long int painter=1,cur=0;
 for(int i=0;i<C.size();i++)
 {
  if(cur+C[i]>mid)
  {
   cur=C[i];
   painter++;
   if(painter>n)
    return false;
  }
  else
   cur+=C[i];
 }
 return true;
}
long long int bs(vector<int>&C,int n) // O(log(n))
{
 long long int start=-1,end=0;
 for(int i=0;i<C.size();i++)
 {
  end+=C[i];
  start=max(start,(long long int)C[i]);
 }
 long long int ans=0;
 while(start<=end)
 {
  int mid=(start+end)/2;
  if(IsValid(C,mid,n)) // -->if valid see if we can minimize the answer more...
  {
    ans=mid;
    end=mid-1;
  }
  else
   start=mid+1;
 }
 return ans;
}

int Solution::paint(int A, int B, vector<int> &C)  // O(n*log(n))
{
  long long int zz=bs(C,A);
  return ((zz%10000003)*(B%10000003))%10000003;
}

// 410. Split Array Largest Sum

class Solution {
public:
    bool IsValid(vector<int>&nums,int mid,int n)
    {
     int cur=0,painter=1;
     for(int i=0;i<nums.size();i++)
     {
      if(cur+nums[i]>mid)
      {
       cur=nums[i];
       painter++;
       if(painter>n)
           return false;
      }
      else
          cur+=nums[i];
     }
     return true;
    }
    int bs(vector<int>&nums,int n)
    {
     int start=-1,end=0;
     for(int i=0;i<nums.size();i++)
     {
      end+=nums[i];
      start=max(start,nums[i]);
     }
     int ans=0;
     while(start<=end)
     {
      int mid=(start+end)>>1;
      if(IsValid(nums,mid,n))
      {
       ans=mid;
       end=mid-1;
      }
      else
          start=mid+1;
     }
     return ans;
    }
    int splitArray(vector<int>& nums, int m)
    {
     int n=nums.size();
     int ans=bs(nums,m);
     return ans;
    }
};

// 875. Koko Eating Bananas
/*
Time O(Nlog(MaxP))
Space O(1)
*/

class Solution {
public:
    bool IsValid(vector<int>&piles,int H,int mid)
    {
     int cnt=0;
     for(int i=0;i<piles.size();i++)
     {
      cnt+=((piles[i]+mid-1)/mid);
      if(cnt>H)
          return false;
     }
     return true;
    }
    int bs(vector<int>&piles,int H)
    {
     int start=1,end=0; // binary search from (start=1 to end) b'coz (piles = [3,6,7,11], H = 27, here it can eat 1 banana/hour)
     for(int i=0;i<piles.size();i++)
       end=max(end,piles[i]);
     int ans;
     while(start<=end)
     {
      int mid=(start+end)>>1;
      if(IsValid(piles,H,mid))
      {
       ans=mid;
       end=mid-1;
        
      }
      else
          start=mid+1;
     }
     return ans;
    }
    int minEatingSpeed(vector<int>& piles, int H) 
    {
     int n=piles.size();
     int ans=bs(piles,H);
     return ans;
    }
};

// 1482. Minimum Number of Days to Make m Bouquets

class Solution {
public:
    bool IsValid(vector<int>&bloomDay,int mid,int k,int m)
    {
     int n=bloomDay.size();
     int bouq=0,zz=0;
     for(int i=0;i<n;i++)
     {
      if(bloomDay[i]>mid)
          zz=0;
      else if(++zz>=k)
      {
       bouq++;
       zz=0;
      }
     }
     return bouq>=m;
     
    }
    int bs(vector<int>& bloomDay,int m,int k)
    {
     int start=1,end=-1;
     for(int i=0;i<bloomDay.size();i++)
         end=max(end,bloomDay[i]);
     int ans=-1;
     while(start<=end)
     {
      int mid=(start+end)>>1;
      if(IsValid(bloomDay,mid,k,m))
      {
       ans=mid;
       end=mid-1;
      }
      else
          start=mid+1;
     }
     return ans;
         
    }
    int minDays(vector<int>& bloomDay, int m, int k)
    {
      int n=bloomDay.size();
      if(m*k>n)
          return -1;
      int ans=bs(bloomDay,m,k);
      return ans;
    }
};

/*
Binary Search:

https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
https://leetcode.com/problems/koko-eating-bananas/
https://leetcode.com/problems/split-array-largest-sum/
https://leetcode.com/problems/kth-missing-positive-number/
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
https://codeforces.com/problemset/problem/670/D1
https://codeforces.com/problemset/problem/670/D2
https://codeforces.com/problemset/problem/778/A
https://codeforces.com/problemset/problem/363/D
*/
