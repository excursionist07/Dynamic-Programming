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
     for(int i=1;i<n;i++)
     {
      swap[i]=notswap[i]=n;
      if(A[i]>A[i-1] && B[i]>B[i-1])
      {
       notswap[i]=notswap[i-1];
       swap[i]=swap[i-1]+1;
      }
      if(A[i]>B[i-1] && B[i]>A[i-1])
      {
       notswap[i]=min(notswap[i],swap[i-1]);
       swap[i]=min(swap[i],notswap[i-1]+1);
      }
     }
     return min(swap[n-1],notswap[n-1]);
    }
};
