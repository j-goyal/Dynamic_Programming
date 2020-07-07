// determine if there is a subset of the given set with sum equal to given sum.

/*
o Same as 0-1 knapsack as in this problem we also have to decide whether to include element in our subset or not
   (include that weight to bag or not)
o Also, sum is equivalent to capacity of the bag which decreases when we include element.
o Only difference is the base condition.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

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

		


int main()
{
	int n=6;
	int set[] = {3, 34, 4, 12, 5, 2}; 
	int sum = 9;
	
	if(isSubsetSum_bottom_up(set,n,sum))
		cout<<"YES subset is present with given sum\n";
	else
		cout<<"NO there is no subset present";
	
	return 0;  

}
