//Given two strings str1 and str2, print the shortest string that has both str1 and str2 as subsequences.

// small changes in print LCS code
#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001]; //global declaration

void SCS_bottom_up_DP(string a, string b, int n, int m)
{
	for(int i=0;i<n+1;i++)          // substract length of longest common subsequence from combined string.
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
				
			else if(a[i-1]==b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			
			else if(a[i-1]!=b[j-1])
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	int p=n;
	int q=m;
	vector<char> v;
	
	while(p>0 && q>0)
	{
		if(a[p-1]==b[q-1])
		{
			v.push_back(a[p-1]);         //store that character
			p--;
			q--;
		}
		else 
		{
			if (dp[p-1][q] > dp[p][q-1])
			{
				v.push_back(a[p-1]);
				p--;
			} 
        		 
			else
			{
				v.push_back(b[q-1]);
				q--;
			}  		 	
		}
	}
	
	// for remaining elements (only one loop will execute between two)
	while(p>0)          
	{
		v.push_back(a[p-1]);
		p--;
	}
	
	while(q>0)
	{
		v.push_back(b[q-1]);
		q--;
	}
	
	reverse(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	
	//return n+m-dp[n][m];
}

int main() 
{ 

	string a,b;
	cin>>a>>b;
	//getline(cin,a);
	//getline(cin,b);
	
	int n = a.length();
	int m = b.length();
	
	memset(dp,-1,sizeof(dp));
	
	SCS_bottom_up_DP(a,b,n,m);
	
	return 0;

}
