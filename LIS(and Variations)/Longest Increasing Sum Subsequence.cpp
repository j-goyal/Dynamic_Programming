#include<bits/stdc++.h>
using namespace std;

int longest_sum_Subsequence(int n, int arr[])  // bottom up
{
	int dp[n];
	dp[0]=arr[0];
		
	for(int i=1;i<n;i++)  // max ending at index i
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
				dp[i]=max(dp[i], dp[j]+arr[i]);
		}
	}
	
	int res=dp[0];
	for(int i=0;i<n;i++)
	{
		res=max(res,dp[i]);
	}
   	
	return res;
}


int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        cout << longest_sum_Subsequence(n, arr) << endl;
    }
}
