#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define rep(i,s,e) for(i=s;i<=e;i++)
#define rrep(i,s,e) for(i=s;i>=e;i--)

#define S(t) scanf("%d",&t);
#define P(t) printf("%d ",t);
#define SLL(t) scanf("%lld",&t)
#define PLL(t) printf("%lld\n",t)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

/* Function to merge the two haves A[l..m] and A[m+1..r] of Array A[] */
void merging(int ARR[],int l,int m,int r)
{
        int i,j,k,n1=m-l+1,n2=r-m;
        /* create temp Arrays */
        int L[n1],R[n2];
        /* Copy data to temp Arrays L[] and R[] */
        rep(i,0,n1-1)
        {
             L[i]=ARR[l+i];
        }
        rep(j,0,n2-1)
        {
             R[j]=ARR[m+1+j];
        }
        /* Merge the temp Arrays back into A[l..r]*/
        i=0;
        j=0;
        k=l;
        while(i<n1 && j<n2)
        {
            if(L[i]<=R[j])
            {
                ARR[k]=L[i];
                i++;
            }
            else
            {
                ARR[k]=R[j];
                j++;
            }
            k++;
        }
        /* Copy the remaining elements of L[], if there are any */
        while(i<n1)
        {
            ARR[k]=L[i];
            i++;
            k++;
        }
        /* Copy the remaining elements of R[], if there are any */
        while(j<n2)
        {
            ARR[k]=R[j];
            j++;
            k++;
        }
}
/* l is for left index and r is right index of the sub-Array
  of A to be sorted */
void mergeSort(int ARR[],int l,int r)
{
        if(l<r)
        {
            int m=l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
            mergeSort(ARR,l,m);
            mergeSort(ARR,m+1,r);
            merging(ARR,l,m,r);
        }
}

int main()
{
          int i,N,A[100010];

          S(N);
          rep(i,0,N-1)
          {
             S(A[i]);
          }
          mergeSort(A,0,N-1);
          rep(i,0,N-1)
          {
             P(A[i]);
          }

          return 0;
}
