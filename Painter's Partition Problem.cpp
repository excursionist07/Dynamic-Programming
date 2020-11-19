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
  if(IsValid(C,mid,n))
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
