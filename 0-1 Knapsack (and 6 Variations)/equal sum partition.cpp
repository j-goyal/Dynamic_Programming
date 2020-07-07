// determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.

/*
o First we check sum of array, if its odd then it is not possible to partition it into 2 subsets.
o If sum is even, we check for a subset with sum = sum/2. If we find any subset with sum=sum/2, then return true because
    then the other remaining elements form the subset with same sum(sum/2). 
o Same as SUBSET SUM problem, only little modification.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


bool isSubsetSum_bottom_up(int set[], int n, int sum)    //Bottom up
{
	bool dp[n+1][sum+1];
	
	for(int j=1;j<sum+1;j++)         // same as recursion
		dp[0][j]=false;              // n==i, sum==j
	
	for(int i=0;i<n+1;i++)
		dp[i][0]=true;
		
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(set[i-1]<=j)
			{
				dp[i][j] = dp[i-1][j-set[i-1]] || dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	/*
	for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", dp[i][j]); 
       printf("\n"); 
     }*/
		
	return dp[n][sum];		
}

bool equal_sum_partition_bottom_up(int arr[], int n)
{
	int sum=0;      
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	
	if(sum%2 != 0)          // sum of array needs to be even for equal sum partition
		return false;
	
	else
	{
		return isSubsetSum_bottom_up(arr,n,sum/2);  // only check for one partition	                                            
	}
}


/*
bool isSubsetSum(int set[], int n, int sum)     // Recursion
{
	
	if(n==0 && sum!=0)           // base condition
		return false;
	if(sum==0)                   // base condition
		return true;
		
	if(set[n-1]<=sum)         //choice
	{
		return ( isSubsetSum(set,n-1,sum-set[n-1]) || isSubsetSum(set,n-1,sum) );
	}
	
	else if(set[n-1]>sum)       // ignore because value is greater than sum
	{
		return isSubsetSum(set,n-1,sum);
	}
}
*/


int main()
{
	int n=4;
	int arr[] = {1, 5, 11, 5};
	
	if(equal_sum_partition_bottom_up(arr,n))
		cout<<"YES two subsets are present with equal sum\n";
	else
		cout<<"NO subset present";
	
	return 0;  

}
