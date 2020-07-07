// Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference 
// between their sums is minimum.


/*
o Divide into two subsets s1 and s2 such that abs(s2-s1) is minimum
o We select one subset say s1 other is (sum-s1),  so abs diff is (sum-s1)-s1  ie (sum-2s1)
o Now we select no. less than sum/2 for s1 such that subset sum of the no.s below the sum/2 should exists
o For eg we have 1,2,7 in array, sum=10 sum/2 = 5,      0 1 2 3 4 5 6 7 8 9 10 no. line
o Now we consider no.<=5 i.e 5,4,3,2,1. we cannot make any subset with given sum 5 so we reject 5. // 4 is also rejected,
o So we left with 1,2,3 for s1 then corresponding s2 (from sum-2s1) = 8,6,4 respectively.
o Then we select min. of these no.'s which is our output.

So we use subset sum problem for values of s1 and finally we store that values in vector and return min.(of sum-2[v(i)])

*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int find_min(int arr[], int n, int sum)      // Bottom up
{
	// same code as of subset sum
	bool dp[n+1][sum+1];
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(j==0)
				dp[i][j]=true;
			
			else if(i==0 && j!=0)
				dp[i][j]=false;
			
			else if(arr[i-1]<=j)
				dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
			
			else if(arr[i-1]>j)
				dp[i][j]=dp[i-1][j];				
		}
	}


 vector<int> v;
	for(int j=0;j<(sum+1)/2;j++)
	{
		if (dp[n][j]==true)
		{
			v.push_back(j);
		}	
	}
	
	int mini = INT_MAX;
	for(int i=0;i<v.size();i++)
	{
		mini = min(mini, sum-2*v[i]);
	}
	
	return mini;	
}


int min_subset_sum(int arr[], int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	
	return find_min(arr,n,sum);
}

int main()
{
	int n=4;
	int arr[] = {1, 9, 7, 5}; 
	cout<<min_subset_sum(arr,n);
	return 0;  

}
