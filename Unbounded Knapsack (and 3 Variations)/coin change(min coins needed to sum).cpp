// min no. of coins for making given sum using given coin of array

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int min_coins_needed_DP(int coin[], int n, int sum)  //Bottom up dp
{
	int dp[n+1][sum+1];
	
	for(int i=0;i<n+1;i++)                   // initalization is complex
	{
		for(int j=0;j<sum+1;j++)
		{
			if(j==0)
				dp[i][j]=0;
				
			else if(i==0 && j!=0)
				dp[i][j]=INT_MAX-1;
			
			else if(coin[i-1]<=j)
				dp[i][j] = min(1 + dp[i][j-coin[i-1]], dp[i-1][j]);
			
			else if(coin[i-1]>j)
				dp[i][j] = dp[i-1][j];
		}
	}
	
	for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%12d", dp[i][j]); 
       printf("\n"); 
     }
	
	return dp[n][sum];
}

int main()
{
	int n=3;
	int coin[]={3,2,5};
	int sum=5;
	cout<<min_coins_needed_DP(coin,n,sum);
	return 0;  

}


