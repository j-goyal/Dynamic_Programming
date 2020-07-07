// Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int subset_sum(int arr[], int n, int sum)     // Recursion
{
	if(sum==0)
		return 1;
	
	if(n==0 && sum!=0)
		return 0;
		
	if(arr[n-1]<=sum)
	{
		return subset_sum(arr,n-1,sum-arr[n-1]) + subset_sum(arr,n-1,sum);
	}
	else
	{
		return subset_sum(arr,n-1,sum);
	}
}


int subset_sum_DP(int arr[], int n, int sum)      // Bottom up
{
	int dp[n+1][sum+1];
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(j==0)
				dp[i][j]=1;
			
			else if(i==0 && j!=0)
				dp[i][j]=0;
			
			else if(arr[i-1]<=j)
				dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
			
			else if(arr[i-1]>j)
				dp[i][j]=dp[i-1][j];
				
		}
	}
	
// Print dp matrix	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			cout<<dp[i][j]<<" ";
		}		
		cout<<endl;
	}
	
	return dp[n][sum];
}

int main()
{
	int n=4;
	int arr[] = {1, 2, 3, 3};
	int X = 6 ;
	//cout<<subset_sum(arr,n,X);
	cout<<subset_sum_DP(arr,n,X);
	return 0;  

}
