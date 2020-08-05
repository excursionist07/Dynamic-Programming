class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
     int n=nums.size();
     if(n==0)
         return 0;

     int maxx=INT_MIN,cur=0,s=0,start,end,i=0;
     for(int i=0;i<n;i++)
         maxx=max(maxx,nums[i]);
     while(i<n)
     {
      cur+=nums[i];
      if(cur>maxx)
      {
       maxx=cur;
       start=s;
       end=i;
      }
      if(cur<0)
      {
       cur=0;
       s=i+1;
      }
      i++;
     }
     return maxx;

    }
};
